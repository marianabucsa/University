using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition.repository
{
    public interface IRounds : IRepository<domain.Round, long>
    {
        /// <summary>
        /// finds a round by name
        /// </summary>
        /// <param name="name">string</param>
        /// <returns>a round or null - if there is no entity with the given name</returns>
        /// <throws>Exception if the name is null</throws>
        domain.Round FindOneName(string name);
    }
}
