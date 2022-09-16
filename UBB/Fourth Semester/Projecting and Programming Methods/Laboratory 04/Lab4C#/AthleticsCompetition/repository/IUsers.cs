using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition.repository
{
    interface IUsers : IRepository<domain.User, long>
    {
        /// <summary>
        /// find a user by name
        /// </summary>
        /// <param name="firstName">string</param>
        /// <param name="lastName">string</param>
        /// <returns>a user or null - if there is no entity with the given first or last name</returns>
        /// <throws>Exception if first or last name are null</throws>
        domain.User FindOneName(string firstName, string lastName);
    }
}
