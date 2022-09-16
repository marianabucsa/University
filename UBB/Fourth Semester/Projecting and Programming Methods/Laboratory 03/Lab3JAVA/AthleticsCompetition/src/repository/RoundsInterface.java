package repository;

import domain.Round;

public interface RoundsInterface extends Repository<Round, Integer> {

    /**
     * find a round by name
     *
     * @param name- string
     * @return - a round
     * or null - if there is no entity with the given name
     * @throws Exception if name is null.
     */
    public Round FindOneName(String name);

}
