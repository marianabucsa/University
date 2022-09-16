package competition.client;

import competition.model.Notification;
import competition.services.INotificationReceiver;
import competition.services.INotificationSubscriber;
import org.springframework.jms.core.JmsOperations;

import java.rmi.RemoteException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class NotificationReceiver implements INotificationReceiver {
    private JmsOperations jmsOperations;
    private boolean running;
    private ExecutorService executor;
    private INotificationSubscriber subscriber;

    public NotificationReceiver(JmsOperations jms) {
        this.jmsOperations = jms;
    }

    @Override
    public void start(INotificationSubscriber subscriber) {
        System.out.println("Starting notification receiver...");
        running = true;
        this.subscriber = subscriber;
        executor = Executors.newSingleThreadExecutor();
        executor.submit(() -> run());
    }

    private void run() {
        try {
            while (running) {
                System.out.println("Waiting notifications...");
                Notification notification = (Notification) jmsOperations.receiveAndConvert();
                System.out.println("Received notification");
                subscriber.notificationReceived(notification);
            }
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }


    @Override
    public void stop() {
        running = false;
        try {
            executor.awaitTermination(100, TimeUnit.MILLISECONDS);
            executor.shutdown();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Stopping notification receiver...");
    }
}
