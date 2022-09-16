using AthleticsCompetition.controller;
using AthleticsCompetition.repository;
using AthleticsCompetition.service;
using log4net.Config;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AthleticsCompetition
{
    static class Program
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
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            //configurare jurnalizare folosind log4net
            XmlConfigurator.Configure(new System.IO.FileInfo("log4j.xml"));

            IDictionary<String, string> props = new SortedList<String, String>();
            props.Add("ConnectionString", GetConnectionStringByName("AthleticsCompetition"));

            IUsers users_repo = new UsersRepo(props);

            IRounds rounds_repo = new RoundsRepo(props);
            IChildren children_repo = new ChildrenRepo(props);
            IEnrollments enrollments_repo = new EnrollmentsRepo(props);
            Service service = new Service(users_repo, rounds_repo, children_repo, enrollments_repo);
            Controller controller = new Controller(service);
            AthleticsCompetiton loginView = new AthleticsCompetiton();
            loginView.setAttributes(controller);
            Application.EnableVisualStyles();
            //Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(loginView);
        }
    }
}
