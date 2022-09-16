package competition;


import competition.persistance.*;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;


import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

@Configuration
public class AthleticsCompetitionConfig {
    @Bean
    @Primary
    public Properties jdbcProps() {
        Properties serverProps = new Properties();
        try {
            serverProps.load(new FileReader("bd.config"));
            serverProps.list(System.out);
        } catch (IOException e) {
            System.out.println("Cannot find db.config " + e);
        }
        return serverProps;
    }


    @Bean(name = "childrenRepo")
    public ChildrenDBRepo childrenDBRepo(Properties jdbcProps) {
        return new ChildrenDBRepo(jdbcProps);
    }


    @Bean(name = "enrollmentRepo")
    public EnrollmentsDBRepo enrollmentsDBRepo(Properties jdbcProps) {
        return new EnrollmentsDBRepo(jdbcProps);
    }

    @Bean(name = "roundsRepo")
    public RoundsDBRepo roundsDBRepo(Properties jdbcProps) {
        return new RoundsDBRepo(jdbcProps);
    }


    @Bean(name = "userRepo")
    public UsersDBRepo usersDBRepo(Properties jdbcProps) {
        return new UsersDBRepo(jdbcProps);
    }

    @Bean(name = "serv")
    public Server server(UsersDBRepo usersDBRepo, RoundsDBRepo roundsDBRepo, ChildrenDBRepo childrenDBRepo,EnrollmentsDBRepo enrollmentsDBRepo) {
        return new Server(usersDBRepo,roundsDBRepo,childrenDBRepo,enrollmentsDBRepo);
    }
}

