package competition.persistance;


import competition.model.Child;
import competition.model.Enrollment;
import competition.model.Round;

public interface EnrollmentsInterface extends Repository<Enrollment, Pair> {
    /**
     * find children for round
     *
     * @param roundId - long
     * @return - iterable of children
     * or null - if there is no entity with the given round
     * @throws Exception if the id is null.
     */
    public Iterable<Child> findChildrenForRound(Long roundId);

    /**
     * find rounds for child
     *
     * @param childId - long
     * @return - iterable of rounds
     * or null - if there is no entity with the given child
     * @throws Exception if the id is null.
     */
    public Iterable<Round> findRoundsForChild(Long childId);
}
