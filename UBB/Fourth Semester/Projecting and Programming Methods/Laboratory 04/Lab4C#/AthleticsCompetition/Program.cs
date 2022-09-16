using AthleticsCompetition.domain;
using AthleticsCompetition.repository;
using log4net.Config;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition
{
    class Program
    {

        static string GetConnectionStringByName(string name)
        {
            // Assume failure.
            string returnValue = null;

            // Look for the name in the connectionStrings section.
            ConnectionStringSettings settings = ConfigurationManager.ConnectionStrings[name];

            // If found, return the connection string.
            if (settings != null)
                returnValue = settings.ConnectionString;

            return returnValue;
        }
        static void Main(string[] args)
        {

            XmlConfigurator.Configure(new System.IO.FileInfo("log4j.xml"));

            IDictionary<String, string> props = new SortedList<String, String>();
            props.Add("ConnectionString", GetConnectionStringByName("AthleticsCompetition"));

            /*
            UsersRepo usersRepo = new UsersRepo(props);


            User user = new User("yyy", "uuu", "jjj", "kkk");
            user.Id = 15;

            ChildrenRepo childrenRepo = new ChildrenRepo(props);
            Child child = new Child("ccc", "uuu", 7);
            child.Id = 10;
            childrenRepo.Save(child);

             foreach (Child c in childrenRepo.FindAll())
             {
                 Console.WriteLine(c.FirstName);
             }

            RoundsRepo roundsRepo = new RoundsRepo(props);
            Round round = new Round("kkk");
            round.Id = 4;
            roundsRepo.Save(round);
            foreach (Round r in roundsRepo.FindAll())
            {
                Console.WriteLine(r.Name);
            }
            //Console.WriteLine(roundsRepo.FindOneName("gggt").Id);

            EnrollmentsRepo enrollmentsRepo = new EnrollmentsRepo(props);
            // Enrollment enrollment = new Enrollment(child, round);
            //enrollment.Id = 4;
            //Tuple<long, long> tuple = new Tuple<long, long>(10, 4);

            foreach (Round e in enrollmentsRepo.FindRoundsForChild(10))
            {
                Console.WriteLine(e.Name);
            }
            Console.ReadLine();
            */
        }
    }
}
