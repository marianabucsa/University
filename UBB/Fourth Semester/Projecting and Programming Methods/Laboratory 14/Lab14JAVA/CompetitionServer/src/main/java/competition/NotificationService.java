package competition;

import competition.model.Enrollment;
import competition.model.Notification;
import competition.model.NotificationType;
import competition.model.User;
import competition.services.INotificationService;
import org.springframework.jms.core.JmsOperations;

public class NotificationService implements INotificationService {
    private JmsOperations jmsOperations;

    public NotificationService(JmsOperations jmsOperations) {
        this.jmsOperations = jmsOperations;
    }

    @Override
    public void userLoggedIn(User user) {
        System.out.println("user logged in notification");
        Notification notification=new Notification(NotificationType.USER_LOGGED_IN, user.getUsername());
        jmsOperations.convertAndSend(notification);
        System.out.println("Sent logged in notification ActiveMQ... " +notification);
    }

    @Override
    public void addedEnrollment(Enrollment enrollment) {
        System.out.println("Added enrollment notification ..."+ enrollment);
        Notification notification = new Notification(NotificationType.ADDED_ENROLLMENT, enrollment.getRound().getName());
        jmsOperations.convertAndSend(notification);
        System.out.println("Send added enrollment notification to ActiveMq ...");

    }
}
