import competition.Server;
import competition.model.*;
import competition.persistance.BugsDBRepo;
import competition.persistance.StepsDBRepo;
import competition.persistance.UsersDBRepo;
import org.hibernate.SessionFactory;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;
import utils.AbstractServer1;
import utils.RpcConcurrentServer;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.rmi.ServerException;
import java.util.Properties;

public class StartServer {

    private static SessionFactory sessionFactory;
    private static final int defaultPort = 55555;

    public static void main(String[] args) {
        final StandardServiceRegistry registry = new StandardServiceRegistryBuilder()
                .configure() // configures settings from hibernate.cfg.xml
                .build();
        try {
            sessionFactory = new MetadataSources(registry).buildMetadata().buildSessionFactory();
        } catch (Exception e) {
            System.err.println("Exceptie " + e);
            StandardServiceRegistryBuilder.destroy(registry);
        }
        Properties props = new Properties();
        try {
            File f = new File("C:\\Users\\Vasile Mirza\\Desktop\\MPP\\UrmarireBugsIss\\Lab7JAVA\\CompetitionServer\\src\\main\\resources\\bd.config");
            props.load(new FileReader(f));
        } catch (IOException e) {
            System.out.println("Cannot find bd.config " + e);
        }
        UserValidator userValidator = new UserValidator();
        BugValidator bugValidator = new BugValidator();
        BugsDBRepo bugsDBRepo = new BugsDBRepo(sessionFactory, bugValidator);
        UsersDBRepo usersDBRepo = new UsersDBRepo(sessionFactory, userValidator);
        StepsDBRepo stepsDBRepo = new StepsDBRepo(sessionFactory);
        Server service = new Server(usersDBRepo, bugsDBRepo, stepsDBRepo);
        int serverPort = defaultPort;
        try {
            serverPort = Integer.parseInt(props.getProperty("server.port"));
        } catch (NumberFormatException nef) {
            System.err.println("Wrong  Port Number " + nef.getMessage());
            System.err.println("Using default port " + defaultPort);
        }
        System.out.println("Starting server on port: " + serverPort);
        AbstractServer1 server = new RpcConcurrentServer(defaultPort, service);
        try {
            server.start();
        } catch (ServerException e) {
            System.err.println("Error starting the server" + e.getMessage());
        }
    }
}
