using CompetitionNetworking;
using CompetitionPersistance.repository;
using CompetitionServices;
using log4net.Config;
using System;
using System.Collections.Generic;
using System.Configuration;

namespace CompetitionServer
{
    class StartServer
    {
        static void Main(string[] args)
        {
            XmlConfigurator.Configure(new System.IO.FileInfo("log4j.xml"));

            IDictionary<String, string> props = new SortedList<String, String>();
            props.Add("ConnectionString", GetConnectionStringByName("AthleticsCompetition"));

            IUsers users_repo = new UsersRepo(props);
            IRounds rounds_repo = new RoundsRepo(props);
            IChildren children_repo = new ChildrenRepo(props);
            IEnrollments enrollments_repo = new EnrollmentsRepo(props);

            IServer serverImpl = new Server(users_repo, rounds_repo, children_repo, enrollments_repo);
            SerialServer server = new SerialServer("127.0.0.1", 55555, serverImpl);
            server.Start();
            Console.WriteLine("Server starter ...");
            Console.ReadLine();
        }
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
    }
}
