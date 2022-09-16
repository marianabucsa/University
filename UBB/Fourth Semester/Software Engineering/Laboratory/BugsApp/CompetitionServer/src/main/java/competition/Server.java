package competition;

import competition.model.Bug;
import competition.model.Stage;
import competition.model.Step;
import competition.model.User;
import competition.persistance.BugsInterface;
import competition.persistance.StepsInterface;
import competition.persistance.UsersDBRepo;
import competition.persistance.UsersInterface;
import competition.services.ObserverInterface;
import competition.services.ServerInterface;

import java.util.Map;
import java.util.Objects;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Server implements ServerInterface {
    private final int nrThreads = 5;
    private UsersInterface usersRepo;
    private BugsInterface bugsRepo;
    private StepsInterface stepsRepo;
    private Map<String, ObserverInterface> loggedUsers;

    public Server(UsersDBRepo usersDBRepo, BugsInterface bugsDBRepo, StepsInterface stepsDBRepo) {
        this.bugsRepo = bugsDBRepo;
        this.usersRepo = usersDBRepo;
        this.stepsRepo = stepsDBRepo;
        loggedUsers = new ConcurrentHashMap<>();
    }

    @Override
    public User login(String username, String password, ObserverInterface o) {
        User user = usersRepo.findOne(username);
        if (user != null && Objects.equals(password, user.getPassword()))
            loggedUsers.put(user.getId(), o);
        return user;
    }

    @Override
    public Iterable<User> findAllUsers() throws Exception {
        Iterable<User> users=  usersRepo.findAll();
        //notifyObservers();
        return users;
    }

    @Override
    public Iterable<Bug> findAllBugs() throws Exception {
        Iterable<Bug> bugs=  bugsRepo.findAll();
        //notifyObservers();
        return bugs;
    }

    @Override
    public Iterable<Step> findAllStepsForBug(Integer id) throws Exception {
        Iterable<Step> steps=  stepsRepo.findAllForBug(id);
        //notifyObservers();
        return steps;
    }

    @Override
    public Step saveStep(Step step) {
        Step step1 = stepsRepo.save(step);
        notifyObservers();
        return step1;
    }

    @Override
    public Step deleteStep(Integer id) {
        Step step = stepsRepo.delete(id);
        notifyObservers();
        return step;
    }

    @Override
    public Step updateStep(Step step) {
        Step step1 = stepsRepo.update(step);
        notifyObservers();
        return step1;
    }

    @Override
    public Iterable<Bug> findAllBugsProgrammer(String username) throws Exception {
        Iterable<Bug> bugs=  bugsRepo.findAllForProgrammer(username);
        //notifyObservers();
        return bugs;
    }

    @Override
    public void repairBug(Bug bug) {
        bug.setStage(Stage.Reparat);
        bugsRepo.update(bug);
        notifyObservers();
    }

    @Override
    public Bug saveBug(Bug bug) {
        Bug bug1 = bugsRepo.save(bug);
        notifyObservers();
        return bug1;
    }

    @Override
    public User saveUser(User user) {
        User user1 = usersRepo.save(user);
        notifyObservers();
        return user1;
    }

    @Override
    public User deleteUser(String username) {
        User user1 = usersRepo.delete(username);
        notifyObservers();
        return user1;
    }

    @Override
    public User updateUser(User user) {
        User user1 = usersRepo.update(user);
        notifyObservers();
        return user1;
    }

    @Override
    public Bug updateBug (Bug bug) {
        Bug bug1 = bugsRepo.update(bug);
        notifyObservers();
        return bug1;
    }

    @Override
    public Bug deleteBug (Integer id) {
        Bug bug1 = bugsRepo.delete(id);
        notifyObservers();
        return bug1;
    }
    public void notifyObservers() {
        ExecutorService executor = Executors.newFixedThreadPool(nrThreads);
        loggedUsers.values().forEach(x -> executor.execute(() -> {
            System.out.println("Notifying observer");
            x.update();
        }));
        executor.shutdown();
    }
}

