using AthleticsCompetition.controller;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AthleticsCompetition
{
    public partial class FirstPage : Form
    {
        private Controller controller;
        public FirstPage()
        {
            InitializeComponent();
        }

        public void setController(Controller controller)
        {
            this.controller = controller;
        }

        private void FirstPage_Load(object sender, EventArgs e)
        {

        }

        private void searchChildButton_Click(object sender, EventArgs e)
        {
            ChildSearchPage childSearchPage = new ChildSearchPage();
            childSearchPage.setController(controller);
            this.Hide();
            childSearchPage.ShowDialog();
            this.Show();
        }

        private void enrollChildButton_Click(object sender, EventArgs e)
        {
            ChildEnrollmentPage childEnPage = new ChildEnrollmentPage();
            childEnPage.setController(controller);
            this.Hide();
            childEnPage.ShowDialog();
            this.Show();
        }
    }
}
