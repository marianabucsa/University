using CompetitionClient.controller;
using CompetitionNetworking;
using CompetitionServices;
using System;
using System.Windows.Forms;

namespace CompetitionClient
{
    static class StartClient
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();

            // Application.SetCompatibleTextRenderingDefault(false);

            IServer server1 = new ServerProxy("127.0.0.1", 55555);
            Controller controller1 = new Controller(server1);
            CompetitionClient loginView1 = new CompetitionClient();
            loginView1.setAttributes(controller1);
            Application.Run(loginView1);
        }
    }
}
