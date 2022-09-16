using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition.repository
{
    public interface IEnrollments : IRepository<domain.Enrollment, Tuple<long, long>>
    {
        /// <summary>
        /// finds children for round
        /// </summary>
        /// <returns>all children for a round</returns>
        List<domain.Child> FindChildrenForRound(long id_round);

        /// <summary>
        /// finds rounds for child
        /// </summary>
        /// <returns>all rounds for a child</returns>
        List<domain.Round> FindRoundsForChild(long id_child);

    }
}
