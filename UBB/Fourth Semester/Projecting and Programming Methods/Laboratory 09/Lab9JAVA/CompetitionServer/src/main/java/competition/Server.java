package competition;

import competition.model.Child;
import competition.model.Enrollment;
import competition.model.Round;
import competition.model.User;
import competition.persistance.*;
import competition.services.IObserver;
import competition.services.IServer;
import org.apache.thrift.TException;
import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.TTransport;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.StreamSupport;

public class Server implements IServer.Iface {
    private final int nrThreads = 5;
    private int clientPort = 9091;
    private UsersInterface usersRepo;
    private RoundsInterface roundsRepo;
    private EnrollmentsInterface enrollmentsRepo;
    private ChildrenInterface childrenRepo;
    private Map<Long, Integer>  loggedUsers;

    public Server(UsersDBRepo usersDBRepo, RoundsDBRepo roundsDBRepo, ChildrenDBRepo childrenDBRepo, EnrollmentsDBRepo enrollmentsDBRepo) {
        this.childrenRepo = childrenDBRepo;
        this.enrollmentsRepo = enrollmentsDBRepo;
        this.roundsRepo = roundsDBRepo;
        this.usersRepo = usersDBRepo;
        loggedUsers = new ConcurrentHashMap<>();
    }

    @Override
    public int login(String username, String password) {
        User user = usersRepo.findUser(username, password);
        if (user != null) {
            loggedUsers.put(user.getId(), clientPort);
            int cp = clientPort;
            clientPort += 1;
            return cp;
        }
        return -1;
    }

    @Override
    public void logout(User u) throws org.apache.thrift.TException {
        loggedUsers.remove(u.getId());
    }


    @Override
    public synchronized long getNrChildrenForRound(String name) {
        Round round = roundsRepo.findOneName(name);
        return StreamSupport.stream(enrollmentsRepo.findChildrenForRound(round.getId()).spliterator(), false).count();
    }

    @Override
    public synchronized List<Round> findAllRounds() {
        return (List<Round>) roundsRepo.findAll();
    }

    @Override
    public synchronized Enrollment FindEnrollmentByChildAndRound(String firstname, String lastname, String roundName) {
        Child child = childrenRepo.findOneName(firstname, lastname);
        Round round = roundsRepo.findOneName(roundName);
        Enrollment e = enrollmentsRepo.findOne(new Pair(child.getId(), round.getId()));
        if(e == null){
            e = new Enrollment(1,child,round,true);
        }
        return e;
    }

    @Override
    public synchronized Child SaveChild(String firstname, String lastname, int age) {
        Child child = new Child(1,firstname, lastname, age,false);
        Child c= childrenRepo.save(child);
        if(c == null){
            c = new Child(1,firstname, lastname, age,true);
        }
        return c;
    }

    @Override
    public synchronized List<Child> findChildrenForRound(String roundName) {
        return (List<Child>) enrollmentsRepo.findChildrenForRound(roundsRepo.findOneName(roundName).getId());
    }

    @Override
    public synchronized Child FindChildByName(String firstname, String lastname) {
       Child c =childrenRepo.findOneName(firstname, lastname);
        if(c == null){
            c = new Child(1,firstname, lastname, 6,true);
        }
        return c;
    }

    @Override
    public synchronized List<Child> FindChildrenByAgeGroup(String ageGroup) {
        Iterable<Child> children = childrenRepo.findAll();
        List<Child> e = new ArrayList<Child>();
        for (Child child : children)
            if (Objects.equals(getAgeGroup(child), ageGroup))
                e.add(child);
        return e;
    }

    @Override
    public synchronized Enrollment SaveEnrollment(String firstname, String lastname, int age, String roundName) {
        Child child = childrenRepo.findOneName(firstname, lastname);
        Round round = roundsRepo.findOneName(roundName);
        Enrollment enrollment = new Enrollment(1,child, round,false);
        Enrollment enrollment1=enrollmentsRepo.save(enrollment);
        if(enrollment1 == null){
            enrollment1 = new Enrollment(1,child, round,true);
        }
        notifyObservers();
        return enrollment1;
    }

    @Override
    public synchronized long FindNumberOfEnrollmentsForChild(String firstname, String lastname) {
        Child child = childrenRepo.findOneName(firstname, lastname);
        if(child == null)
            return 0;
        Iterable<Round> roundsForChild = enrollmentsRepo.findRoundsForChild(child.getId());
        return StreamSupport.stream(roundsForChild.spliterator(), false).count();
    }


    public synchronized void notifyObservers() {
        ExecutorService executor = Executors.newFixedThreadPool(loggedUsers.size());
        loggedUsers.entrySet().forEach(x -> executor.execute(() -> {
            System.out.println("Notifying observer");
            try {
                TTransport transport = new TSocket("localhost", x.getValue());
                transport.open();

                TProtocol protocol = new TBinaryProtocol(transport);

                IObserver.Client client = new IObserver.Client(protocol);
                client.update();

            } catch (TException e) {
                e.printStackTrace();
            }
        }));
        executor.shutdown();
        System.out.println();
    }

    public String getAgeGroup(Child child) {
        if (child.getAge() >= 6 && child.getAge() <= 8)
            return "6-8 years old";
        if (child.getAge() >= 9 && child.getAge() <= 11)
            return "9-11 years old";
        else
            return "12-15 years old";
    }
}

