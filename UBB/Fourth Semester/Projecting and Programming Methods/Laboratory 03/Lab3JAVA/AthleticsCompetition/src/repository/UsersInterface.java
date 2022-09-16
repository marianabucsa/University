package repository;

import domain.User;

public interface UsersInterface extends Repository<User, Integer> {

    /**
     * find a user by name
     *
     * @param firstName - string
     * @param lastName  - string
     * @return - a user
     * or null - if there is no entity with the given first or last name
     * @throws Exception if first or last name are null.
     */
    public User findOneName(String firstName, String lastName);
}
