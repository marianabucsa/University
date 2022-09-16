package competition.persistance;

import competition.model.Child;

public interface ChildrenInterface extends Repository<Child, Long> {

    /**
     * find a child by name
     *
     * @param firstName - string
     * @param lastName  - string
     * @return - a child
     * or null - if there is no entity with the given first or last name
     * @throws Exception if first or last name are null.
     */
    public Child findOneName(String firstName, String lastName);

}
