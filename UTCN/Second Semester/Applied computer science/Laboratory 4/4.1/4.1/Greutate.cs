using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _4._1
{
    public partial class Greutate : Form
    {



        public Greutate()
        {
            InitializeComponent();

        }

        private void WomanBtn_Click(object sender, EventArgs e)
        {
            int inaltime = Int32.Parse(heightField.Text.ToString());
            int varsta= Int32.Parse(ageField.Text.ToString());
            double greutate = inaltime - 100 - ((inaltime - 150) / 4) + ((varsta - 20) / 4);
            weightField.Text = greutate.ToString();
            weightLbl.Visible = true;
            weightField.Visible = true;
        }

        private void ManBtn_Click(object sender, EventArgs e)
        {
            int inaltime = Int32.Parse(heightField.Text.ToString());
            int varsta = Int32.Parse(ageField.Text.ToString());
            double greutate = inaltime - 100 - ((inaltime - 150) / 2.5) + ((varsta - 20) / 6);
            weightField.Text = greutate.ToString();
            weightLbl.Visible = true;
            weightField.Visible = true;
        }

        private void StopBtn_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
