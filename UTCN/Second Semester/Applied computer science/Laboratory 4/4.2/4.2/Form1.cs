using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _4._2
{
    public partial class Form1 : Form
    {
        private bool validated = true;

        public Form1()
        {
            InitializeComponent();
        }

        private double getGrade()
        {
            if (Grade_text.Equals(""))
            {
                MessageBox.Show("Introduceti gradele!");
                validated = false;
            }
            double grade;
            if (Double.TryParse(Grade_text.Text.ToString(), out grade) == false)
            {
                MessageBox.Show("Introduceti un numar real!");
                validated = false;
                
            }
            return grade;
        }

        private void FtoC_Click(object sender, EventArgs e)
        {
            double grade = getGrade();
            if (!validated)
                return; 
            double celsius = (grade - 32) * 5 / 9;
            Rez_text.Text = celsius.ToString();
            validated = true;
        }

        private void CtoF_Click(object sender, EventArgs e)
        {
            double grade = getGrade();
            if (!validated)
                return;
            double fahrenheit = (grade * 9 / 5) + 32;
            Rez_text.Text = fahrenheit.ToString();
            validated = true;
        }
    }
}
