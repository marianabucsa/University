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
        /// <param name="id"> integer </param>
        /// <param name="name" > string </param>
        public Round(int id, string name)
        {
            this.Id = id;
            this.Name = name;
        }

        /// <summary>
        /// getter and setter for round id
        /// </summary>
        protected int Id { get; set; }

        /// <summary>
        /// getter and setter for round id
        /// </summary>
        protected string Name { get; set; }

    }
}
