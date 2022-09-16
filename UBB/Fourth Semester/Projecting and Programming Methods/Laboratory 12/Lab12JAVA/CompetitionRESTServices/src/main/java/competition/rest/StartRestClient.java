package competition.rest;

import competition.model.Round;
import competition.rest.client.RoundClient;
import org.springframework.web.client.RestClientException;

public class StartRestClient {

    private final static RoundClient roundsClient = new RoundClient();
    public static final String URL = "http://localhost:8081/competition/rounds";

    public static void main(String[] args) {
        Round round = new Round("345 m Round");
        try {
           /* //create
            show(() -> {
                System.out.println("Round added " + roundsClient.save(round));
            });*/

            //update
/*            round.setName("1001 m Round");
            round.setId(56L);
            show(() -> System.out.println("Updating  round ..." + round));
            show(() -> System.out.println("Round update result: " + roundsClient.update(round)));*/
            //getById
            /*show(() -> System.out.println("Round with id 46: " + roundsClient.getById(46L)));*/
            //getAll
           /* show(() -> {
                Round[] rounds = roundsClient.getAll();
                for (Round r : rounds) {
                    System.out.println(r.toString());
                }
            });*/

            //delete
            System.out.println("Deleting round with id 36");
            show(() -> System.out.println("Round deleted: " + roundsClient.delete(54L)));
        } catch (RestClientException e) {
            System.out.println("Exception ... " + e);
        }
    }


    private static void show(Runnable task) {
        try {
            task.run();
        } catch (Exception e) {
            System.out.println("Exception" + e);
        }
    }
}

