using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition.domain
{
    class Child : Person
    {
        /// <summary>
        /// getter and setter for child age
        /// </summary>
        public int Age { get; set; }

        /// <summary>
        /// constructor for child
        /// </summary>
        /// <param name="firstName"> string </param>
        /// <param name="lastName"> string </param>
        /// <param name="age"> integer </param>
        public Child(string firstName, string lastName, int age) : base(firstName, lastName)
        {
            this.Age = age;
        }

        /// <summary>
        /// gets the age group for a child
        /// </summary>
        /// <returns> string representing the group name </returns>
        public string GetAgeGroup()
        {
            if (this.Age >= 6 && this.Age <= 8)
                return "6-8 years";
            if (this.Age >= 9 && this.Age <= 11)
                return "9-11 years";
            else
                return "12-15 years";
        }
    }
}
