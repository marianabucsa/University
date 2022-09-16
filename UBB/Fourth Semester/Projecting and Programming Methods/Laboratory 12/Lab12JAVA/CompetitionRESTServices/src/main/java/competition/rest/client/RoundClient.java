package competition.rest.client;

import competition.model.Round;
import org.springframework.web.client.HttpClientErrorException;
import org.springframework.web.client.ResourceAccessException;
import org.springframework.web.client.RestTemplate;

import java.util.concurrent.Callable;

public class RoundClient {
    public static final String URL = "http://localhost:8081/competition/rounds";

    private RestTemplate restTemplate = new RestTemplate();

    private <T> T execute(Callable<T> callable){
        try {
            return callable.call();
        } catch (ResourceAccessException | HttpClientErrorException e) { // server down, resource exception
            throw new ServiceException(e);
        } catch (Exception e) {
            throw new ServiceException(e);
        }
    }

    public Round save(Round round) {

        return execute(() -> restTemplate.postForObject(URL, round, Round.class));
    }

    public Round update(Round round){
        return execute(() -> {
             restTemplate.put(String.format("%s/%s", URL, round.getId()), round);
             return round;
        });
    }

    public Round delete(Long id){
        return execute(() -> {
            Round round = getById(id);
            restTemplate.delete(String.format("%s/%s", URL, id));
            return round;
        });
    }

    public Round getById(Long id)  {
        return execute(() -> restTemplate.getForObject(String.format("%s/%s", URL, id), Round.class));
    }

    public Round[] getAll() {
        return execute(() -> restTemplate.getForObject(URL, Round[].class));
    }

}
