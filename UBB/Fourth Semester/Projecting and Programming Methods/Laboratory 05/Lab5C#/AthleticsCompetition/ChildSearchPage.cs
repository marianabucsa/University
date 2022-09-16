using AthleticsCompetition.controller;
using AthleticsCompetition.domain;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AthleticsCompetition
{
    public partial class ChildSearchPage : Form
    {
        private Controller controller;
        public ChildSearchPage()
        {
            InitializeComponent();
        }

        internal void setController(Controller controller)
        {
            this.controller = controller;

        }

        private void searchByNameButton_Click(object sender, EventArgs e)
        {
            try
            {
                String firstname = textFirstNameChild.Text;
                String lastname = textLastNameChild.Text;
                if (firstname == "" || lastname == "")
                    throw new Exception("Enter information for child!");
                searchChildTable.DataSource = controller.SearchForChildren(firstname, lastname);
                searchChildTable.Refresh();
            }
            catch (Exception ve)
            {
                MessageBox.Show(ve.Message);
            }

        }

        private void roundsComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                String roundName = roundsComboBox.Text;
                if (roundName == "")
                    throw new Exception("Enter information for child!");

                searchChildTable.DataSource = controller.SearchChildrenInRounds(roundName);

                searchChildTable.Refresh();
            }
            catch (Exception ve)
            {
                MessageBox.Show(ve.Message);
            }
        }

        private void ageGroupsComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                String ageGroup = ageGroupsComboBox.Text;
                if (ageGroup == "")
                    throw new Exception("Enter information for child!");

                searchChildTable.DataSource = controller.SearchAgeGroup(ageGroup);
                searchChildTable.Refresh();
            }
            catch (Exception ve)
            {
                MessageBox.Show(ve.Message);
            }
        }
    }
}
