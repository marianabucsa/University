using CompetitionModel.domain;
using CompetitionPersistance.repository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitionPersistance.repository
{
    public interface IRounds : IRepository<Round, long>
    {
        /// <summary>
        /// finds a round by name
        /// </summary>
        /// <param name="name">string</param>
        /// <returns>a round or null - if there is no entity with the given name</returns>
        /// <throws>Exception if the name is null</throws>
        Round FindOneName(string name);
    }
}
