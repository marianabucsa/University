package competition.services;

import competition.model.Child;
import competition.model.Enrollment;
import competition.model.Round;
import competition.model.User;

public interface ServerInterface {
    void logout(User u, INotificationService o) throws Exception;

    User login(String username, String password, INotificationService o) throws Exception;

    long getNrChildrenForRound(String name) throws Exception;

    Iterable<Round> findAllRounds() throws Exception;

    Enrollment FindEnrollmentByChildAndRound(String firstname, String lastname, String roundName) throws Exception;

    Child SaveChild(String firstname, String lastname, int age) throws Exception;

    Iterable<Child> findChildrenForRound(String roundName) throws Exception;

    Child FindChildByName(String firstname, String lastname) throws Exception;

    Iterable<Child> FindChildrenByAgeGroup(String ageGroup) throws Exception;

    Enrollment SaveEnrollment(String firstname, String lastname, int age, String roundName) throws Exception;

    long FindNumberOfEnrollmentsForChild(String firstname, String lastname) throws Exception;

}
