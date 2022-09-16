package competition.rest.controller;

import competition.model.Round;
import competition.persistance.RoundsDBRepo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;

@CrossOrigin
@RestController
@RequestMapping("/competition/rounds")
public class RoundRestController {
    @Autowired
    private RoundsDBRepo roundsDBRepo;


    @RequestMapping(method = RequestMethod.POST, consumes = "application/json")
    public ResponseEntity<?> addRound(@RequestBody Round round) {
        try {
            Round round1 = roundsDBRepo.save(round);
            if (round != null)
                return new ResponseEntity<>(round1, HttpStatus.OK);
            throw new Exception("Could not save round!");
        } catch (Exception e) {
            return new ResponseEntity<>("Could not save round!", HttpStatus.BAD_REQUEST);
        }
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.PUT)
    public ResponseEntity<?> updateRound(@RequestBody Round round, @PathVariable Long id) {
        try {
            round.setId(id);
            Round round1 = roundsDBRepo.update(round);
            if (round1 != null)
                return new ResponseEntity<>(round1, HttpStatus.OK);
            throw new Exception("Could not update round!");
        } catch (Exception e) {
            return new ResponseEntity<>("Could not update round!", HttpStatus.BAD_REQUEST);
        }
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public ResponseEntity<?> deleteRound(@PathVariable Long id) {
        try {
            Round round = roundsDBRepo.delete(id);
            if (round != null)
                return new ResponseEntity<>(round, HttpStatus.OK);
            throw new Exception("Could not delete round!");
        } catch (Exception e) {
            return new ResponseEntity<>("Could not delete round!", HttpStatus.BAD_REQUEST);
        }
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    public ResponseEntity<?> findRoundById(@PathVariable Long id) {
        try {
            Round round = roundsDBRepo.findOne(id);
            if (round != null)
                return new ResponseEntity<>(round, HttpStatus.OK);
            throw new Exception("Could not find round!");
        } catch (Exception e) {
            return new ResponseEntity<>("Could not find round!", HttpStatus.NOT_FOUND);
        }

    }

    @RequestMapping(method = RequestMethod.GET)
    public ResponseEntity<?> findAllRounds() {

        try {
            List<Round> rounds = new ArrayList<>();
            roundsDBRepo.findAll().forEach(rounds::add);
            if (rounds.size() != 0)
                return new ResponseEntity<>(rounds, HttpStatus.OK);
            throw new Exception("Could not find rounds!");
        } catch (Exception e) {
            return new ResponseEntity<>("Could not find rounds!", HttpStatus.NOT_FOUND);
        }
    }
}

