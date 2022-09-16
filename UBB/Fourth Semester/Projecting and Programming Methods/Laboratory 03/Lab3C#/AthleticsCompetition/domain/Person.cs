using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition.domain
{
    class Person
    {
        /// <summary>
        /// getter and setter for person ID
        /// </summary>
        protected int Id { get; set; }

        /// <summary>
        /// getter and setter for person first name
        /// </summary>
        protected string FirstName { get; set; }

        /// <summary>
        /// getter and getter for person last name
        /// </summary>
        protected string LastName { get; set; }

        /// <summary>
        /// constructor for preson
        /// </summary>
        /// <param name="firstName"> string </param>
        /// <param name="lastName"> string </param>
        public Person(string firstName, string lastName)
        {
            this.FirstName = firstName;
            this.LastName = lastName;
        }

    }
}
