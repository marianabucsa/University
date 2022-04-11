using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _5._2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void LoginButton_Click(object sender, EventArgs e)
        {
            string user = UserText.Text;
            string pass = PassText.Text;
            if (user.Trim().Equals("") || pass.Trim().Equals(""))
            {
                MessageBox.Show("Introduceti username si parola!");
                return;
            }
            if (user.Contains(" "))
            {
                MessageBox.Show("Introduceti un username valid!");
                return;
            }
            Form2 form2 = new Form2(user);
            form2.Show();
        }
    }
}
