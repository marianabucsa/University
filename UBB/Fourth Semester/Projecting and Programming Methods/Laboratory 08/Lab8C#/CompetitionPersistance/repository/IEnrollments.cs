using CompetitionModel.domain;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitionPersistance.repository
{
    public interface IEnrollments : IRepository<Enrollment, Tuple<long, long>>
    {
        /// <summary>
        /// finds children for round
        /// </summary>
        /// <returns>all children for a round</returns>
        List<Child> FindChildrenForRound(long id_round);

        /// <summary>
        /// finds rounds for child
        /// </summary>
        /// <returns>all rounds for a child</returns>
        List<Round> FindRoundsForChild(long id_child);

    }
}
