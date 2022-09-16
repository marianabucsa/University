using CompetitionModel.domain;
using log4net;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitionPersistance.repository
{
    public class RoundsRepo : IRounds
    {

        private static readonly ILog log = LogManager.GetLogger("RoundsRepository");
        IDictionary<String, String> props;
        public RoundsRepo(IDictionary<String, String> props)
        {
            log.Info("Creating RoundsRepo");
            this.props = props;
        }
        public Round Delete(long id)
        {
            log.InfoFormat("Deleting round {0}", id);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "delete from rounds where id = @id ";
                IDbDataParameter idpar = comm.CreateParameter();
                idpar.ParameterName = "@id";
                idpar.Value = id;
                Round round = FindOne(id);
                comm.Parameters.Add(idpar);
                comm.ExecuteNonQuery();
                log.InfoFormat("Round deleted successfully");
                return round;
            }
        }

        public List<Round> FindAll()
        {
            log.InfoFormat("Entering findAll");
            IDbConnection con = DBUtils.getConnection(props);
            List<Round> rounds = new List<Round>();
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select * from rounds ";

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
                    log.InfoFormat("Exiting findAll ");
                    return rounds;
                }
            }
        }

        public Round FindOne(long id)
        {
            log.InfoFormat("Entering findOne with value {0}", id);
            IDbConnection con = DBUtils.getConnection(props);

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select * from rounds where id=@id";
                IDbDataParameter paramId = comm.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                comm.Parameters.Add(paramId);

                using (var dataR = comm.ExecuteReader())
                {
                    if (dataR.Read())
                    {
                        long idV = (long)dataR.GetValue(0);
                        String name = dataR.GetString(1);
                        Round round = new Round(name);
                        round.Id = idV;
                        log.InfoFormat("Exiting findOne with value {0}", round);
                        return round;
                    }
                }
            }
            log.InfoFormat("Exiting findOne with value {0}", null);
            return null;
        }

        public Round FindOneName(string name)
        {
            log.InfoFormat("Entering findOneName with value {0}", name);
            IDbConnection con = DBUtils.getConnection(props);

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select * from rounds where name=@name";
                IDbDataParameter name1 = comm.CreateParameter();
                name1.ParameterName = "@name";
                name1.Value = name;
                comm.Parameters.Add(name1);

                using (var dataR = comm.ExecuteReader())
                {
                    if (dataR.Read())
                    {
                        long idV = (long)dataR.GetValue(0);
                        String name2 = dataR.GetString(1);
                        Round round = new Round(name);
                        round.Id = idV;
                        log.InfoFormat("Exiting findOneName with value {0}", round);
                        return round;
                    }
                }
            }
            log.InfoFormat("Exiting findOne with value {0}", null);
            return null;
        }

        public Round Save(Round entity)
        {
            log.InfoFormat("Saving round {0}", entity);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "insert into rounds(name) values(@name)";
                IDbDataParameter name = comm.CreateParameter();
                name.ParameterName = "@name";
                name.Value = entity.Name;
                comm.Parameters.Add(name);
                var result = comm.ExecuteNonQuery();
                log.InfoFormat("Rounds inserted successfully");
                return null;
            }
        }

        public Round Update(Round entity)
        {
            log.InfoFormat("Updating {0}", entity);
            IDbConnection con = DBUtils.getConnection(props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "update rounds set name=@name where id=@id ";
                IDbDataParameter name = comm.CreateParameter();
                IDbDataParameter idpar = comm.CreateParameter();
                name.ParameterName = "@name";
                name.Value = entity.Name;
                comm.Parameters.Add(name);
                idpar.ParameterName = "@id";
                idpar.Value = entity.Id;
                comm.Parameters.Add(idpar);
                var result = comm.ExecuteNonQuery();
                log.InfoFormat("Round updated successfully");
                return null;
            }
        }
    }
}
