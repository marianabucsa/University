using CompetitionModel.domain;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitionPersistance.repository
{
    public interface IChildren : IRepository<Child, long>
    {
        /// <summary>
        /// find a child by name
        /// </summary>
        /// <param name="firstName">string</param>
        /// <param name="lastName">string</param>
        /// <returns>a child or null - if there is no entity with the given first or last name</returns>
        /// <throws>Exception if first or last name are null</throws>
        Child FindOneName(string firstName, string lastName);
    }
}
