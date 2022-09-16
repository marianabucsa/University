using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition.domain
{
    class Enrollment
    {
        /// <summary>
        /// constructor for enrollment
        /// </summary>
        /// <param name="idChild"> integer </param>
        /// <param name="idRound"> integer </param>
        public Enrollment(int idChild, int idRound)
        {
            this.IdChild = idChild;
            this.IdRound = idRound;
        }

        /// <summary>
        /// getter and setter for child id
        /// </summary>
        protected int IdChild { get; set; }

        /// <summary>
        /// getter and setter for round id
        /// </summary>
        protected int IdRound { get; set; }

    }
}
