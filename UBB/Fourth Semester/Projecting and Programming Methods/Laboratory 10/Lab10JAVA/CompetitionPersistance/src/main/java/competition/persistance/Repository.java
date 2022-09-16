package competition.persistance;

public interface Repository<E, Id> {
    /**
     * finds an entity by id
     *
     * @param id -the id of the entity to be returned
     *           id must not be null
     * @return the entity with the specified id
     * or null - if there is no entity with the given id
     * @throws Exception if id is null.
     */
    E findOne(Id id);

    /**
     * finds all entities in the database
     *
     * @return all entities
     */
    Iterable<E> findAll();

    /**
     * @param entity entity must be not null
     * @return null- if the given entity is saved
     * otherwise returns the entity (id already exists)
     * @throws Exception if the entity is not  or is null
     */
    E save(E entity);


    /**
     * removes the entity with the specified id
     *
     * @param id must be not null
     * @return the removed entity or null if there is no entity with the given id
     * @throws Exception if the given id is null.
     */
    E delete(Id id);

    /**
     * updates the entity
     *
     * @param entity entity must not be null
     * @return null - if the entity is updated,
     * otherwise  returns the entity  - (e.g. id does not exist).
     * @throws Exception if the given entity is null or not valid.
     */
    E update(E entity);

}
