using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab5_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            string elem = TextBox.Text.ToString();
            if (elem.Trim().Equals(""))
            {
                MessageBox.Show("Introduceti un text!");
                TextBox.Text = "";
                return;
            }
            ListBox.Items.Add(elem);
            TextBox.Text = "";
        }

        private void DeleteItem(object sender, EventArgs e)
        {
            if (ListBox.SelectedItem == null)
            {
                return;
            }
            ListBox.Items.Remove(ListBox.SelectedItem);
        }
    }
}
