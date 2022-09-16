package competition.persistance;

import competition.model.Bug;

public interface BugsInterface extends Repository<Integer, Bug> {
    Iterable<Bug> findAllForProgrammer(String username);
}
