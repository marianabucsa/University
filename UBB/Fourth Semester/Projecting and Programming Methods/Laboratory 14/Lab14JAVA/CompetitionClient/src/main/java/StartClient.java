import competition.client.Controller;
import competition.client.NotificationReceiver;
import competition.services.INotificationReceiver;
import competition.services.ServerInterface;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.io.IOException;

public class StartClient extends Application {

    ServerInterface service;
    NotificationReceiver notificationReceiver;

    public static void main(String[] args) {
        Application.launch();
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("spring-client.xml");
        service = context.getBean("server", ServerInterface.class);
        notificationReceiver = context.getBean("notificationReceiver", NotificationReceiver.class);
        initView(primaryStage);
        primaryStage.show();
    }

    private void initView(Stage primaryStage) throws IOException {

        FXMLLoader startupLoader = new FXMLLoader();
        startupLoader.setLocation(getClass().getResource("/competition/Login.fxml"));

        Controller controller = new Controller();
        controller.setService(service, notificationReceiver);
        startupLoader.setController(controller);
        AnchorPane startTaskLayout = startupLoader.load();
        primaryStage.setScene(new Scene(startTaskLayout));

        primaryStage.setResizable(false);

    }
}