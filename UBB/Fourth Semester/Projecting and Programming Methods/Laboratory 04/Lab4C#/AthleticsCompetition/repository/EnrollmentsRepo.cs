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
    class EnrollmentsRepo : IEnrollments
    {

        private static readonly ILog log = LogManager.GetLogger("EnrollmentsRepository");
        IDictionary<String, String> props;
        public EnrollmentsRepo(IDictionary<String, String> props)
        {
            log.Info("Creating EnrollmentsRepo");
            this.props = props;
        }

        public Enrollment Delete(Tuple<long, long> id)
        {
            log.InfoFormat("Deleting enrollment {0}", id);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "delete from enrollments where idchild = @idchild and idround = @idround";
                IDbDataParameter idchild = comm.CreateParameter();
                IDbDataParameter idround = comm.CreateParameter();
                idchild.ParameterName = "@idchild";
                idchild.Value = id.Item1;
                comm.Parameters.Add(idchild);
                idround.ParameterName = "@idround";
                idround.Value = id.Item2;
                comm.Parameters.Add(idround);
                Enrollment enrollment = FindOne(id);
                comm.ExecuteNonQuery();
                log.InfoFormat("Enrollment deleted successfully");
                return enrollment;
            }
        }

        public List<Enrollment> FindAll()
        {
            log.InfoFormat("Entering findAll");
            IDbConnection con = DBUtils.getConnection(props);
            List<Enrollment> enrollments = new List<Enrollment>();
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select E.id,C.id,C.firstname,C.lastname,C.age,R.id,r.name from children C inner join enrollments E on E.idChild=C.id inner join rounds R on E.idRound=r.id ";

                using (var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        long idE = (long)dataR.GetValue(0);
                        long idC = (long)dataR.GetValue(1);
                        String firstname = dataR.GetString(2);
                        String lastname = dataR.GetString(3);
                        int age = dataR.GetInt32(4);
                        long idR = (long)dataR.GetValue(5);
                        String name = dataR.GetString(6);
                        Child child = new Child(firstname, lastname, age);
                        child.Id = idC;
                        Round round = new Round(name);
                        round.Id = idR;
                        Enrollment enrollment = new Enrollment(child, round);
                        enrollment.Id = idE;
                        enrollments.Add(enrollment);

                    }
                    log.InfoFormat("Exiting findAll ");
                    return enrollments;
                }
            }
        }

        public List<Child> FindChildrenForRound(long id_round)
        {
            log.InfoFormat("Entering FindChildrenForRound");
            IDbConnection con = DBUtils.getConnection(props);
            List<Child> children = new List<Child>();
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select C.id,C.firstname,C.lastname,C.age from children C inner join enrollments E on E.idChild=C.id inner join rounds R on E.idround=R.id  where idround = @idround ";
                IDbDataParameter idround = comm.CreateParameter();
                idround.ParameterName = "@idround";
                idround.Value = id_round;
                comm.Parameters.Add(idround);
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
                    log.InfoFormat("Exiting FindChildrenForRound ");
                    return children;
                }
            }
        }

        public Enrollment FindOne(Tuple<long, long> id)
        {
            IDbConnection con = DBUtils.getConnection(props);

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select E.id,C.firstname,C.lastname,C.age,R.name from children C inner join enrollments E on E.idChild=C.id inner join Rounds r on E.idRound=R.id  where idChild = @idchild and idRound=@idround";
                IDbDataParameter idround = comm.CreateParameter();
                idround.ParameterName = "@idround";
                idround.Value = id.Item2;
                comm.Parameters.Add(idround);
                IDbDataParameter idchild = comm.CreateParameter();
                idchild.ParameterName = "@idchild";
                idchild.Value = id.Item1;
                comm.Parameters.Add(idchild);
                using (var dataR = comm.ExecuteReader())
                {
                    if (dataR.Read())
                    {
                        long idE = (long)dataR.GetValue(0);
                        String firstname = dataR.GetString(1);
                        String lastname = dataR.GetString(2);
                        int age = dataR.GetInt32(3);
                        String name = dataR.GetString(4);
                        Child child = new Child(firstname, lastname, age);
                        child.Id = id.Item1;
                        Round round = new Round(name);
                        round.Id = id.Item2;
                        Enrollment enrollment = new Enrollment(child, round);
                        enrollment.Id = idE;
                        log.InfoFormat("Exiting findOne with value {0}", null);
                        return enrollment;
                    }
                }
            }
            log.InfoFormat("Exiting findOne with value {0}", null);
            return null;
        }

        public List<Round> FindRoundsForChild(long id_child)
        {
            log.InfoFormat("Entering FindRoundsForchild");
            IDbConnection con = DBUtils.getConnection(props);
            List<Round> rounds = new List<Round>();
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select R.id,R.name from rounds R inner join enrollments E on E.idRound=R.id inner join children C on E.idChild=C.id where idChild = @idchild ";
                IDbDataParameter idchild = comm.CreateParameter();
                idchild.ParameterName = "@idchild";
                idchild.Value = id_child;
                comm.Parameters.Add(idchild);
                using (var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        long idV = (long)dataR.GetValue(0);
                        String name = dataR.GetString(1);
                        Round round = new Round(name);
                        round.Id = idV;
                        rounds.Add(round);

                    }
                    log.InfoFormat("Exiting FindRoundsForchild ");
                    return rounds;
                }
            }
        }

        public Enrollment Save(Enrollment entity)
        {
            log.InfoFormat("Saving enrollment {0}", entity);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "insert into enrollments(idchild,idround) values(@idchild,@idround)";
                IDbDataParameter idround = comm.CreateParameter();
                idround.ParameterName = "@idround";
                idround.Value = entity.Round.Id;
                comm.Parameters.Add(idround);
                IDbDataParameter idchild = comm.CreateParameter();
                idchild.ParameterName = "@idchild";
                idchild.Value = entity.Child.Id;
                comm.Parameters.Add(idchild);
                var result = comm.ExecuteNonQuery();
                log.InfoFormat("Enrollment inserted successfully");
                return null;
            }
        }

        public Enrollment Update(Enrollment entity)
        {
            log.InfoFormat("Updating enrollment {0}", entity);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "update enrollments set idchild=@idchild, idround=@idround where id=@id ";
                IDbDataParameter idround = comm.CreateParameter();
                idround.ParameterName = "@idround";
                idround.Value = entity.Round.Id;
                comm.Parameters.Add(idround);
                IDbDataParameter idchild = comm.CreateParameter();
                idchild.ParameterName = "@idchild";
                idchild.Value = entity.Child.Id;
                comm.Parameters.Add(idchild);
                IDbDataParameter id = comm.CreateParameter();
                id.ParameterName = "@id";
                id.Value = entity.Id;
                comm.Parameters.Add(id);
                var result = comm.ExecuteNonQuery();
                log.InfoFormat("Erollment updated successfully");
                return null;
            }
        }
    }
}
