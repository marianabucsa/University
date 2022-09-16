using CompetitionModel.domain;
using log4net;
using System;
using System.Collections.Generic;
using System.Data;


namespace CompetitionPersistance.repository
{
    public class ChildrenRepo : IChildren
    {
        private static readonly ILog log = LogManager.GetLogger("ChildrenRepository");
        IDictionary<String, String> props;
        public ChildrenRepo(IDictionary<String, String> props)
        {
            log.Info("Creating ChildrenRepo");
            this.props = props;
        }
        public Child Delete(long id)
        {
            log.InfoFormat("Deleting child {0}", id);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "delete from children where id = @id ";
                IDbDataParameter idpar = comm.CreateParameter();
                idpar.ParameterName = "@id";
                idpar.Value = id;
                Child child = FindOne(id);
                comm.Parameters.Add(idpar);
                comm.ExecuteNonQuery();
                log.InfoFormat("Child deleted successfully");
                return child;
            }
        }

        public List<Child> FindAll()
        {
            log.InfoFormat("Entering findAll");
            IDbConnection con = DBUtils.getConnection(props);
            List<Child> children = new List<Child>();
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select * from children ";

                using (var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        long idV = (long)dataR.GetValue(0);
                        String firstname = dataR.GetString(1);
                        String lastname = dataR.GetString(2);
                        int age = dataR.GetInt32(3);
                        Child child = new Child(firstname, lastname, age);
                        child.Id = idV;
                        children.Add(child);

                    }
                    log.InfoFormat("Exiting findAll ");
                    return children;
                }
            }
        }

        public Child FindOne(long id)
        {
            log.InfoFormat("Entering findOne with value {0}", id);
            IDbConnection con = DBUtils.getConnection(props);

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select * from children where id=@id";
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
                        int age = dataR.GetInt32(3);
                        Child child = new Child(firstname, lastname, age);
                        child.Id = idV;
                        log.InfoFormat("Exiting findOne with value {0}", child);
                        return child;
                    }
                }
            }
            log.InfoFormat("Exiting findOne with value {0}", null);
            return null;
        }

        public Child FindOneName(string firstName, string lastName)
        {
            log.InfoFormat("Entering findOneName with value {0,1}", firstName, lastName);
            IDbConnection con = DBUtils.getConnection(props);

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select * from children where firstname=@firstname and lastname = @lastname";
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
                        int age = dataR.GetInt32(3);
                        Child child = new Child(firstname1, lastname1, age);
                        child.Id = idV;
                        log.InfoFormat("Exiting findOneName with value {0}", child);
                        return child;
                    }
                }
            }
            log.InfoFormat("Exiting findOne with value {0}", null);
            return null;
        }

        public Child Save(Child entity)
        {
            log.InfoFormat("Saving child {0}", entity);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "insert into children(firstname, lastname, age) values(@firstname,@lastname,@age)";
                IDbDataParameter firstname = comm.CreateParameter();
                IDbDataParameter lastname = comm.CreateParameter();
                IDbDataParameter age = comm.CreateParameter();
                firstname.ParameterName = "@firstname";
                firstname.Value = entity.FirstName;
                comm.Parameters.Add(firstname);
                lastname.ParameterName = "@lastname";
                lastname.Value = entity.LastName;
                comm.Parameters.Add(lastname);
                age.ParameterName = "@age";
                age.Value = entity.Age;
                comm.Parameters.Add(age);
                var result = comm.ExecuteNonQuery();
                log.InfoFormat("Child inserted successfully");
                return null;
            }
        }

        public Child Update(Child entity)
        {
            log.InfoFormat("Updating child {0}", entity);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "update children set firstname=@firstname, lastname=@lastname, age=@age where id=@id ";
                IDbDataParameter firstname = comm.CreateParameter();
                IDbDataParameter lastname = comm.CreateParameter();
                IDbDataParameter age = comm.CreateParameter();
                IDbDataParameter idpar = comm.CreateParameter();
                firstname.ParameterName = "@firstname";
                firstname.Value = entity.FirstName;
                comm.Parameters.Add(firstname);
                lastname.ParameterName = "@lastname";
                lastname.Value = entity.LastName;
                comm.Parameters.Add(lastname);
                age.ParameterName = "@age";
                age.Value = entity.Age;
                comm.Parameters.Add(age);
                idpar.ParameterName = "@id";
                idpar.Value = entity.Id;
                comm.Parameters.Add(idpar);
                var result = comm.ExecuteNonQuery();
                log.InfoFormat("Child updated successfully");
                return null;
            }
        }
    }
}
