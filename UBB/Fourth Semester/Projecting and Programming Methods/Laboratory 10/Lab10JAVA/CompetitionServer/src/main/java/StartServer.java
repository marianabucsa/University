import competition.Server;
import competition.model.Round;
import competition.persistance.ChildrenDBRepo;
import competition.persistance.EnrollmentsDBRepo;
import competition.persistance.RoundsDBRepo;
import competition.persistance.UsersDBRepo;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;
import org.hibernate.query.Query;
import utils.AbstractServer;
import utils.RpcConcurrentServer;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.rmi.ServerException;
import java.util.List;
import java.util.Properties;

public class StartServer {

    private static SessionFactory sessionFactory;
    private static final int defaultPort = 55555;

    public static void main(String[] args) {
        final StandardServiceRegistry registry = new StandardServiceRegistryBuilder()
                .configure() // configures settings from hibernate.cfg.xml
                .build();
        try {
            sessionFactory= new MetadataSources( registry ).buildMetadata().buildSessionFactory();
        }
        catch (Exception e) {
            System.err.println("Exceptie "+e);
            StandardServiceRegistryBuilder.destroy( registry );
        }

        Properties props = new Properties();
        try {
            File f = new File("C:\\Users\\Vasile Mirza\\Desktop\\MPP\\Lab10-lastversion\\Lab7JAVA\\CompetitionServer\\src\\main\\resources\\bd.config");
            props.load(new FileReader(f));
        } catch (IOException e) {
            System.out.println("Cannot find bd.config " + e);
        }

        ChildrenDBRepo childrenDBRepo = new ChildrenDBRepo(props);
        EnrollmentsDBRepo enrollmentsDBRepo = new EnrollmentsDBRepo(props);
        RoundsDBRepo roundsDBRepo = new RoundsDBRepo(props, sessionFactory);
        UsersDBRepo usersDBRepo = new UsersDBRepo(props);
        Server service = new Server(usersDBRepo, roundsDBRepo, childrenDBRepo, enrollmentsDBRepo);
        int serverPort = defaultPort;
        try {
            serverPort = Integer.parseInt(props.getProperty("server.port"));
        } catch (NumberFormatException nef) {
            System.err.println("Wrong  Port Number " + nef.getMessage());
            System.err.println("Using default port " + defaultPort);
        }
        System.out.println("Starting server on port: " + serverPort);
        AbstractServer server = new RpcConcurrentServer(defaultPort, service);
        try {
            server.start();
        } catch (ServerException e) {
            System.err.println("Error starting the server" + e.getMessage());
        }
    }

/*
    public static void main(String[] args) {
        int defaultPort = 55555;
        ApplicationContext springJavaConfig = new AnnotationConfigApplicationContext(AthleticsCompetitionConfig.class);
        ServerInterface server = springJavaConfig.getBean(Server.class);
        AbstractServer appserver = new RpcConcurrentServer(defaultPort, server);
        try {
            appserver.start();
        } catch (ServerException e) {
            System.out.println("Error at server opening\n");
        }
        JdbcUtils.closeConnection();
    }

 */
}
