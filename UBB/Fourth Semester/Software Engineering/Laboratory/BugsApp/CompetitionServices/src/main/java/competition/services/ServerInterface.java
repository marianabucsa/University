package competition.services;

import competition.model.Bug;
import competition.model.Step;
import competition.model.User;

public interface ServerInterface {
    User login(String username, String password, ObserverInterface o) throws Exception;

    Iterable<User> findAllUsers() throws Exception;

    Iterable<Bug> findAllBugs() throws Exception;

    Iterable<Bug> findAllBugsProgrammer(String username) throws Exception;

    void repairBug(Bug bug) throws Exception;

    Bug saveBug(Bug bug) throws Exception;

    User saveUser(User user) throws Exception;

    User deleteUser(String username) throws Exception;

    User updateUser(User user) throws Exception;

    Bug updateBug(Bug bug) throws Exception;

    Bug deleteBug(Integer id) throws Exception;

    Iterable<Step> findAllStepsForBug(Integer id) throws Exception;

    Step saveStep(Step step) throws Exception;

    Step updateStep(Step step) throws Exception;

    Step deleteStep(Integer id) throws Exception;
}
