using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition.domain
{
    class Round
    {
        /// <summary>
        /// constructor for round
        /// </summary>
        /// <param name="name" > string </param>
        public Round(string name)
        {
            this.Name = name;
        }

        /// <summary>
        /// getter and setter for round id
        /// </summary>
        public long Id { get; set; }

        /// <summary>
        /// getter and setter for round id
        /// </summary>
        public string Name { get; set; }

    }
}
