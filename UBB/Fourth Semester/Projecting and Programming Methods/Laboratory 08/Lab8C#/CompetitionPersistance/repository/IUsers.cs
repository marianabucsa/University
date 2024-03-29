﻿using CompetitionModel.domain;
using CompetitionPersistance.repository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitionPersistance.repository
{
    public interface IUsers : IRepository<User, long>
    {
        /// <summary>
        /// find a user by name
        /// </summary>
        /// <param name="firstName">string</param>
        /// <param name="lastName">string</param>
        /// <returns>a user or null - if there is no entity with the given first or last name</returns>
        /// <throws>Exception if first or last name are null</throws>

        User FindOneName(string firstName, string lastName);

        /// <summary>
        /// find a user by username
        /// </summary>
        /// <param name="firstName">string</param>
        /// <returns>a user or null - if there is no entity with the given username</returns>
        /// <throws>Exception if username is null</throws>
        User FindUser(string username, string password);
    }
}
