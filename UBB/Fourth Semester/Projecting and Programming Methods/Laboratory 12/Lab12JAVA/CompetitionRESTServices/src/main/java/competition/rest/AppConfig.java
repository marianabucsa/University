package competition.rest;
import competition.persistance.RoundsDBRepo;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;

import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

@Configuration
public class AppConfig {
    @Bean
    @Primary
    public Properties jdbcProps() {
        Properties serverProps = new Properties();
        try {
            serverProps.load(new FileReader("C:\\Users\\Vasile Mirza\\Desktop\\MPP\\Lab10-lastversion\\Lab7JAVA\\CompetitionRESTServices\\src\\main\\resources\\bd.config"));
            serverProps.list(System.out);
        } catch (IOException e) {
            System.out.println("Cannot find bd.config " + e);
        }
        return serverProps;
    }

    @Bean(name = "roundsRepo")
    public RoundsDBRepo roundRepository() {
        return new RoundsDBRepo(jdbcProps());
    }
}
