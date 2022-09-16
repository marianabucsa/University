import org.springframework.context.support.ClassPathXmlApplicationContext;
import utils.AbstractServer;
import utils.RpcConcurrentServer;

import java.rmi.ServerException;

public class StartServer {
    public static void main(String[] args) {
        ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("spring-server.xml");
        AbstractServer server=context.getBean("competitionTCPServer", RpcConcurrentServer.class);
        try {
            server.start();
        } catch (ServerException e) {
            System.err.println("Error starting the server" + e.getMessage());
        }
    }
}