using AthleticsCompetition.controller;
using AthleticsCompetition.domain;
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
    public partial class ChildEnrollmentPage : Form
    {
        private Controller controller;

        public ChildEnrollmentPage()
        {
            InitializeComponent();
        }

        internal void setController(Controller controller)
        {
            this.controller = controller;
            addDataToTable();
        }

        private void addDataToTable()
        {
            tableNumberChildrenPerRound.DataSource = controller.getRoundsNumberChildren();
        }

        private void enrollButton_Click(object sender, EventArgs e)
        {
            try
            {
                if (textFirstNameChild.Text == "" || textLastNameChild.Text == "" || textAgeChild.Text == "")
                    throw new Exception("Enter information for child!");
                String firstname = textFirstNameChild.Text;
                String lastname = textLastNameChild.Text;
                int age = Int32.Parse(textAgeChild.Text);
                if (RoundsCheckBox.CheckedItems.Count == 0 || RoundsCheckBox.CheckedItems.Count > 2)
                {
                    throw new Exception("Please select 1 or 2 rounds!");
                }
                Child child = controller.FindChild(firstname, lastname);
                if (child == null)
                {
                    controller.SaveChild(firstname, lastname, age);
                }
                else
                {
                    int numberEnrollments = controller.FindNumberOfEnrollments(firstname, lastname);
                    if (numberEnrollments >= 2)
                        throw new Exception("Child is already enrolled to 2 rounds!");
                    if (numberEnrollments + RoundsCheckBox.CheckedItems.Count > 2)
                        throw new Exception("To many rounds selected!");
                    for (int x = 0; x < RoundsCheckBox.CheckedItems.Count; x++)
                    {
                        Enrollment enrollment = controller.FindExistingEnrollment(firstname, lastname, RoundsCheckBox.CheckedItems[x].ToString());
                        if (enrollment != null)
                        {
                            throw new Exception(" The enrollment to " + RoundsCheckBox.CheckedItems[x].ToString() + " already exists!");
                        }
                    }
                }
                for (int x = 0; x < RoundsCheckBox.CheckedItems.Count; x++)
                {
                    if ((RoundsCheckBox.CheckedItems[x].ToString() == "1000 m Round" || RoundsCheckBox.CheckedItems[x].ToString() == "1500 m Round") && age < 9)
                        throw new Exception("Child is too small for that round!");
                    else { Enrollment enrollment = controller.SaveEnrollment(firstname, lastname, age, RoundsCheckBox.CheckedItems[x].ToString()); }
                }
                addDataToTable();
                tableNumberChildrenPerRound.Refresh();
                this.ClearFields();
            }
            catch (Exception re)
            {
                MessageBox.Show(re.Message);
                this.Show();
            }
        }
        private void ClearFields()
        {
            textFirstNameChild.Text = "";
            textLastNameChild.Text = "";
            textAgeChild.Text = "";
            RoundsCheckBox.ClearSelected();
        }
    }
}
