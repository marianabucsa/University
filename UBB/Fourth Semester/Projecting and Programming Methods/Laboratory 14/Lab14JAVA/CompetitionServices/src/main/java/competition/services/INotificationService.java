package competition.services;

import competition.model.Enrollment;
import competition.model.User;

public interface INotificationService {
    void addedEnrollment(Enrollment enrollment) throws Exception;
    void userLoggedIn(User user);
}

