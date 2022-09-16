package competition.persistance;

import competition.model.Round;

public interface RoundsInterface extends Repository<Round, Long> {

    /**
     * find a round by name
     *
     * @param name- string
     * @return - a round
     * or null - if there is no entity with the given name
     * @throws Exception if name is null.
     */
    public Round findOneName(String name);

}
