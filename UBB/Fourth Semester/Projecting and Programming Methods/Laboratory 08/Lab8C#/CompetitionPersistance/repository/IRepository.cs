using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitionPersistance.repository
{
    public interface IRepository<E, Id>
    {
        /// <summary>
        /// finds an entity by id
        /// </summary>
        /// <param name="id"> the id of the entity to be returned, id must not be null</param>
        /// <returns>the entity with the specified id or null - if there is no entity with the given id</returns>
        /// <throws>Exception  if id is null.</throws>
        E FindOne(Id id);

        /// <summary>
        /// finds all entities in the database
        /// </summary>
        /// <returns>all entities</returns>
        List<E> FindAll();

        /// <summary>
        /// saves the entity in the database
        /// </summary>
        /// <param name="entity"> entity must not be null</param>
        /// <returns>null- if the given entity is saved otherwise returns the entity(id already exists)</returns>
        E Save(E entity);

        /// <summary>
        /// removes the entity with the specified id
        /// </summary>
        /// <param name="id">must be not null</param>
        /// <returns>the removed entity or null if there is no entity with the given id</returns>
        /// <throws>Exception if the given id is null.</throws>
        E Delete(Id id);

        /// <summary>
        /// updates the entity
        /// </summary>
        /// <param name="entity">entity must not be null</param>
        /// <returns>if the entity is updated, otherwise returns the entity  - (e.g.id does not exist).</returns>
        /// <throws>Exception if the given entity is null or not valid</throws>
        E Update(E entity);
    }
}
