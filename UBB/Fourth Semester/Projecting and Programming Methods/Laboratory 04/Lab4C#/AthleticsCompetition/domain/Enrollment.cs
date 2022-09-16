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
        /// <param name="child"> child </param>
        /// <param name="round"> child </param>
        public Enrollment(Child child, Round round)
        {
            this.Child = child;
            this.Round = round;
        }

        /// <summary>
        /// getter and setter for child
        /// </summary>
        public Child Child { get; set; }

        /// <summary>
        /// getter and setter for id 
        /// </summary>
        public long Id { get; set; }

        /// <summary>
        /// getter and setter for round 
        /// </summary>
        public Round Round { get; set; }

    }
}
