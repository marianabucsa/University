package competition;

import competition.model.Child;
import competition.model.Enrollment;
import competition.model.Round;
import competition.model.User;
import competition.persistance.*;
import competition.services.ObserverInterface;
import competition.services.ServerInterface;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.StreamSupport;

public class Server implements ServerInterface {
    private final int nrThreads = 5;
    private UsersDBRepo usersRepo;
    private RoundsDBRepo roundsRepo;
    private EnrollmentsDBRepo enrollmentsRepo;
    private ChildrenDBRepo childrenRepo;
    private Map<Long, ObserverInterface> loggedUsers;

    public Server(UsersDBRepo usersDBRepo, RoundsDBRepo roundsDBRepo, ChildrenDBRepo childrenDBRepo, EnrollmentsDBRepo enrollmentsDBRepo) {
        this.childrenRepo = childrenDBRepo;
        this.enrollmentsRepo = enrollmentsDBRepo;
        this.roundsRepo = roundsDBRepo;
        this.usersRepo = usersDBRepo;
        loggedUsers = new ConcurrentHashMap<>();
    }

    @Override
    public User login(String username, String password, ObserverInterface o) {
        User user = usersRepo.findUser(username, password);
        if (user != null)
            loggedUsers.put(user.getId(), o);
        return user;
    }

    @Override
    public void logout(User u, ObserverInterface o) {
        loggedUsers.remove(u.getId(), o);
    }


    @Override
    public synchronized long getNrChildrenForRound(String name) {
        Round round = roundsRepo.findOneName(name);
        return StreamSupport.stream(enrollmentsRepo.findChildrenForRound(round.getId()).spliterator(), false).count();
    }

    @Override
    public synchronized Iterable<Round> findAllRounds() {
        return roundsRepo.findAll();
    }

    @Override
    public synchronized Enrollment FindEnrollmentByChildAndRound(String firstname, String lastname, String roundName) {
        Child child = childrenRepo.findOneName(firstname, lastname);
        Round round = roundsRepo.findOneName(roundName);
        return enrollmentsRepo.findOne(new Pair(child.getId(), round.getId()));
    }

    @Override
    public synchronized Child SaveChild(String firstname, String lastname, int age) {
        Child child = new Child(firstname, lastname, age);
        return childrenRepo.save(child);

    }

    @Override
    public synchronized Iterable<Child> findChildrenForRound(String roundName) {
        return enrollmentsRepo.findChildrenForRound(roundsRepo.findOneName(roundName).getId());
    }

    @Override
    public synchronized Child FindChildByName(String firstname, String lastname) {
        return childrenRepo.findOneName(firstname, lastname);
    }

    @Override
    public synchronized Iterable<Child> FindChildrenByAgeGroup(String ageGroup) {
        Iterable<Child> children = childrenRepo.findAll();
        List<Child> e = new ArrayList<Child>();
        for (Child child : children)
            if (Objects.equals(child.getAgeGroup(), ageGroup))
                e.add(child);
        return e;
    }

    @Override
    public synchronized Enrollment SaveEnrollment(String firstname, String lastname, int age, String roundName) {
        Child child = childrenRepo.findOneName(firstname, lastname);
        Round round = roundsRepo.findOneName(roundName);
        Enrollment enrollment = new Enrollment(child, round);
        Enrollment enrollment1=enrollmentsRepo.save(enrollment);
        notifyObservers();
        return enrollment1;
    }

    @Override
    public synchronized long FindNumberOfEnrollmentsForChild(String firstname, String lastname) {
        Child child = childrenRepo.findOneName(firstname, lastname);
        Iterable<Round> roundsForChild = enrollmentsRepo.findRoundsForChild(child.getId());
        return StreamSupport.stream(roundsForChild.spliterator(), false).count();
    }

    @Override
    public void notifyObservers() {
        ExecutorService executor = Executors.newFixedThreadPool(nrThreads);
        loggedUsers.values().forEach(x -> executor.execute(() -> {
            System.out.println("Notifying observer");
            x.update();
        }));
        executor.shutdown();
    }
}

