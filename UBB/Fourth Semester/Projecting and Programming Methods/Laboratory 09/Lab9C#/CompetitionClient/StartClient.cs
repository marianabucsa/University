using CompetitionClient.controller;
using System;
using System.Windows.Forms;
using Thrift.Protocol;
using Thrift.Transport;

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
            Application.SetCompatibleTextRenderingDefault(false);

            //being client
            TTransport transport = new TSocket("localhost", 9090);
            transport.Open();

            TProtocol protocol = new TBinaryProtocol(transport);

            IServer.Client client = new IServer.Client(protocol);
            Controller controller = new Controller(client);
            CompetitionClient loginView1 = new CompetitionClient();
            loginView1.setAttributes(controller);
            Application.Run(loginView1);
        }
    }
}
