using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition.domain
{
    class User : Person
    {
        /// <summary>
        /// constructor for user
        /// </summary>
        /// <param name="firstName">  string </param>
        /// <param name="lastName">  string </param>
        /// <param name="username">  string </param>
        /// <param name="password">  string</param>
        public User(string firstName, string lastName, string username, string password) : base(firstName, lastName)
        {
            Username = username;
            Password = password;
        }

        /// <summary>
        /// getter and setter for username
        /// </summary>
        public string Username { get; set; }

        /// <summary>
        /// getter and setter for password
        /// </summary>
        public string Password { get; set; }

    }
}
