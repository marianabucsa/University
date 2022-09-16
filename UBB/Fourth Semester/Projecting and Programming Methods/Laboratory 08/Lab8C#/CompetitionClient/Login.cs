using CompetitionClient.controller;
using CompetitionModel.domain;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CompetitionClient
{
    public partial class CompetitionClient : Form
    {
        private Controller controller;
        public CompetitionClient()
        {
            InitializeComponent();
        }

        public void setAttributes(Controller c)
        {
            this.controller = c;
        }

        private void onLoginClick(object sender, EventArgs e)
        {
            String username = textUsename.Text;
            String password = textPassword.Text;
            try
            {
                User user = controller.FindUser(username, password);
                if (user != null)
                {
                    FirstPage firstPage = new FirstPage();
                    firstPage.setController(controller);
                    this.ClearFields();
                    this.Hide();
                    firstPage.ShowDialog();
                    this.Show();
                }
                else
                {
                    this.ClearFields();
                    throw new Exception("User not found!");
                }
            }
            catch (Exception re)
            {
                MessageBox.Show(re.Message);
                this.Show();
            }
        }

        private void ClearFields()
        {
            textUsename.Text = "";
            textPassword.Text = "";
        }

        private void LoginView_Load(object sender, EventArgs e)
        {
            textPassword.PasswordChar = '*';
        }

    }
}
