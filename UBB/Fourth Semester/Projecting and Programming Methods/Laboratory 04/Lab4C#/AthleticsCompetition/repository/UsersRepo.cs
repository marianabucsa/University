using AthleticsCompetition.domain;
using log4net;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition.repository
{
    class UsersRepo : IUsers
    {
        private static readonly ILog log = LogManager.GetLogger("UsersRepository");
        IDictionary<String, String> props;
        public UsersRepo(IDictionary<String, String> props)
        {
            log.Info("Creating UsersRepo");
            this.props = props;
        }

        public User Delete(long id)
        {
            log.InfoFormat("Deleting user {0}", id);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "delete from users where id = @id ";
                IDbDataParameter idpar = comm.CreateParameter();
                idpar.ParameterName = "@id";
                idpar.Value = id;
                User user = FindOne(id);
                comm.Parameters.Add(idpar);
                comm.ExecuteNonQuery();
                log.InfoFormat("User deleted successfully");
                return user;
            }

        }

        public List<User> FindAll()
        {
            log.InfoFormat("Entering findAll");
            IDbConnection con = DBUtils.getConnection(props);
            List<User> users = new List<User>();
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select * from users ";

                using (var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        long idV = (long)dataR.GetValue(0);
                        String firstname = dataR.GetString(1);
                        String lastname = dataR.GetString(2);
                        String username = dataR.GetString(3);
                        String password = dataR.GetString(4);
                        User user = new User(firstname, lastname, username, password);
                        user.Id = idV;
                        users.Add(user);

                    }
                    log.InfoFormat("Exiting findAll ");
                    return users;
                }
            }
        }

        public User FindOne(long id)
        {
            log.InfoFormat("Entering findOne with value {0}", id);
            IDbConnection con = DBUtils.getConnection(props);

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select * from users where id=@id";
                IDbDataParameter paramId = comm.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                comm.Parameters.Add(paramId);

                using (var dataR = comm.ExecuteReader())
                {
                    if (dataR.Read())
                    {
                        long idV = (long)dataR.GetValue(0);
                        String firstname = dataR.GetString(1);
                        String lastname = dataR.GetString(2);
                        String username = dataR.GetString(3);
                        String password = dataR.GetString(4);
                        User user = new User(firstname, lastname, username, password);
                        user.Id = idV;
                        log.InfoFormat("Exiting findOne with value {0}", user);
                        return user;
                    }
                }
            }
            log.InfoFormat("Exiting findOne with value {0}", null);
            return null;
        }

        public User FindOneName(string firstName, string lastName)
        {
            log.InfoFormat("Entering findOneName with value {0,1}", firstName, lastName);
            IDbConnection con = DBUtils.getConnection(props);

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select * from users where firstname=@firstname and lastname = @lastname";
                IDbDataParameter firstname = comm.CreateParameter();
                IDbDataParameter lastname = comm.CreateParameter();
                firstname.ParameterName = "@firstname";
                firstname.Value = firstName;
                comm.Parameters.Add(firstname);
                lastname.ParameterName = "@lastname";
                lastname.Value = lastName;
                comm.Parameters.Add(lastname);

                using (var dataR = comm.ExecuteReader())
                {
                    if (dataR.Read())
                    {
                        long idV = (long)dataR.GetValue(0);
                        String firstname1 = dataR.GetString(1);
                        String lastname1 = dataR.GetString(2);
                        String username = dataR.GetString(3);
                        String password = dataR.GetString(4);
                        User user = new User(firstname1, lastname1, username, password);
                        user.Id = idV;
                        log.InfoFormat("Exiting findOneName with value {0}", user);
                        return user;
                    }
                }
            }
            log.InfoFormat("Exiting findOne with value {0}", null);
            return null;
        }

        public User Save(User entity)
        {
            log.InfoFormat("Saving user {0}", entity);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "insert into users(firstname, lastname, username, password) values(@firstname,@lastname,@username,@password)";
                IDbDataParameter firstname = comm.CreateParameter();
                IDbDataParameter lastname = comm.CreateParameter();
                IDbDataParameter username = comm.CreateParameter();
                IDbDataParameter password = comm.CreateParameter();
                firstname.ParameterName = "@firstname";
                firstname.Value = entity.FirstName;
                comm.Parameters.Add(firstname);
                lastname.ParameterName = "@lastname";
                lastname.Value = entity.LastName;
                comm.Parameters.Add(lastname);
                username.ParameterName = "@username";
                username.Value = entity.Username;
                comm.Parameters.Add(username);
                password.ParameterName = "@password";
                password.Value = entity.Password;
                comm.Parameters.Add(password);
                var result = comm.ExecuteNonQuery();
                log.InfoFormat("Users inserted successfully");
                return null;
            }
        }



        public User Update(User entity)
        {
            log.InfoFormat("Updating user {0}", entity);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "update users set firstname=@firstname, lastname=@lastname, username=@username,password=@password where id=@id ";
                IDbDataParameter firstname = comm.CreateParameter();
                IDbDataParameter lastname = comm.CreateParameter();
                IDbDataParameter username = comm.CreateParameter();
                IDbDataParameter password = comm.CreateParameter();
                IDbDataParameter idpar = comm.CreateParameter();
                firstname.ParameterName = "@firstname";
                firstname.Value = entity.FirstName;
                comm.Parameters.Add(firstname);
                lastname.ParameterName = "@lastname";
                lastname.Value = entity.LastName;
                comm.Parameters.Add(lastname);
                username.ParameterName = "@username";
                username.Value = entity.Username;
                comm.Parameters.Add(username);
                password.ParameterName = "@password";
                password.Value = entity.Password;
                comm.Parameters.Add(password);
                idpar.ParameterName = "@id";
                idpar.Value = entity.Id;
                comm.Parameters.Add(idpar);
                var result = comm.ExecuteNonQuery();
                log.InfoFormat("User updated successfully");
                return null;
            }
        }
    }
}
