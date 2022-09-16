import competition.client.Controller;
import competition.services.ServerInterface;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import rpcprotocol.ServerRpcProxy;


import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

public class StartClient extends Application {
    private static int defaultPort=55555;
    private static String defaultServer="localhost";

    ServerInterface service;

    public static void main(String[] args)  {
        Application.launch();
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        Properties props=new Properties();
        try {
            File f = new File("C:\\Users\\Vasile Mirza\\Desktop\\MPP\\Lab6-gata\\Lab6JAVA\\CompetitionClient\\client.config");
            props.load(new FileReader(f));
        } catch (IOException e) {
            System.out.println("Cannot find client.config "+e);
        }

        String serverIP = props.getProperty("server.host",defaultServer);
        int serverPort = defaultPort;
        /*try{
            serverPort=Integer.parseInt(props.getProperty("server.port"));
        }catch(NumberFormatException ex){
            System.err.println("Wrong port number "+ex.getMessage());
            System.out.println("Using default port: "+defaultPort);
        }*/
        service=new ServerRpcProxy(serverIP, serverPort);
        initView(primaryStage);
        primaryStage.show();
    }

    private void initView(Stage primaryStage) throws IOException {

        FXMLLoader startupLoader = new FXMLLoader();
        startupLoader.setLocation(getClass().getResource("/competition/Login.fxml"));

        Controller controller = new Controller();
        controller.setService(service);
        startupLoader.setController(controller);
        AnchorPane startTaskLayout = startupLoader.load();
        primaryStage.setScene(new Scene(startTaskLayout));

        primaryStage.setResizable(false);

    }
}