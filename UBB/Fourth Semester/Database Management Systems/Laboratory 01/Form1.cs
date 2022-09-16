using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Lab1
{
    public partial class Form1 : Form
    {
        SqlConnection connection = new SqlConnection("Data Source=DESKTOP-1S9740Q\\DDDD;Initial Catalog=Inchirieri_auto;Integrated Security=True");
        SqlDataAdapter adapter1 = new SqlDataAdapter();
        SqlDataAdapter adapter2 = new SqlDataAdapter();
        DataSet dataset1 = new DataSet();
        DataSet dataset2 = new DataSet();
        int id_locatie;
        public Form1()
        {
            InitializeComponent();
        }

        private void LoadTableLocations(object sender, EventArgs e)
        {
            adapter1.SelectCommand = new SqlCommand("SELECT * FROM Locatii", connection);
            dataset1.Clear();
            adapter1.Fill(dataset1);
            tableLocations.DataSource = dataset1.Tables[0];
            tableLocations.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            tableLocations.ClearSelection();
            addBtn.Enabled = false;
            deleteBtn.Enabled = false;
            updateBtn.Enabled = false;
        }


        private void LoadEmployeesLocation(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                DataGridViewRow row = this.tableLocations.Rows[e.RowIndex];
                id_locatie = Int32.Parse(row.Cells["id_locatie"].Value.ToString());
                adapter2.SelectCommand = new SqlCommand("SELECT * from Angajati where id_locatie=@id", connection);
                adapter2.SelectCommand.Parameters.Add("@id", SqlDbType.Int).Value = id_locatie;
                dataset2.Clear();
                adapter2.Fill(dataset2);
                tableEmployees.DataSource = dataset2.Tables[0];
                tableEmployees.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
                tableEmployees.ClearSelection();
                addBtn.Enabled = true;
                if (idbox.Text == "")
                {
                    deleteBtn.Enabled = false;
                    updateBtn.Enabled = false;
                }
                return;
            }
            addBtn.Enabled = false;
            deleteBtn.Enabled = false;
            updateBtn.Enabled = false;
        }

        private void addBtn_Click(object sender, EventArgs e)
        {
            try
            {
                adapter2.InsertCommand = new SqlCommand("insert into Angajati (id_angajat, nume_angajat, prenume_angajat, salariu , pozitia_curenta, id_locatie) values (@id, @nume, @prenume, @salariu, @pozitia_curenta,@id_locatie)", connection);
                adapter2.InsertCommand.Parameters.Add("@id", SqlDbType.Int).Value = Int32.Parse(idbox.Text.ToString());
                adapter2.InsertCommand.Parameters.Add("@nume", SqlDbType.VarChar).Value = numebox.Text.ToString();
                adapter2.InsertCommand.Parameters.Add("@prenume", SqlDbType.VarChar).Value = prenumebox.Text.ToString();
                adapter2.InsertCommand.Parameters.Add("@salariu", SqlDbType.Float).Value = float.Parse(salariubox.Text.ToString());
                adapter2.InsertCommand.Parameters.Add("@pozitia_curenta", SqlDbType.VarChar).Value = pozitiacurentabox.Text.ToString();
                adapter2.InsertCommand.Parameters.Add("@id_locatie", SqlDbType.Int).Value = id_locatie;
                connection.Open();
                adapter2.InsertCommand.ExecuteNonQuery();
                connection.Close();
                dataset2.Clear();
                adapter2.Fill(dataset2);
                MessageBox.Show("Adăugare realizată cu succes!", "Informare");
                connection.Close();

            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }

        private void ClearSelections(object sender, EventArgs e)
        {
            tableLocations.ClearSelection();
            tableEmployees.ClearSelection();
            ClearFields();
        }

        private void ClearFields()
        {
            idbox.Clear();
            numebox.Clear();
            prenumebox.Clear();
            salariubox.Clear();
            pozitiacurentabox.Clear();
            addBtn.Enabled = false;
            deleteBtn.Enabled = false;
            updateBtn.Enabled = false;

        }

        private void ShowDetailesEmployees(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                DataGridViewRow row = this.tableEmployees.Rows[e.RowIndex];
                idbox.Text = row.Cells["id_angajat"].Value.ToString();
                numebox.Text = row.Cells["nume_angajat"].Value.ToString();
                prenumebox.Text = row.Cells["prenume_angajat"].Value.ToString();
                salariubox.Text = row.Cells["salariu"].Value.ToString();
                pozitiacurentabox.Text = row.Cells["pozitia_curenta"].Value.ToString();
                idbox.ReadOnly = true;
                addBtn.Enabled = false;
                deleteBtn.Enabled = true;
                updateBtn.Enabled = true;
                return;
            }
            idbox.Clear();
            numebox.Clear();
            prenumebox.Clear();
            salariubox.Clear();
            pozitiacurentabox.Clear();
            idbox.ReadOnly = false;
            deleteBtn.Enabled = false;
            updateBtn.Enabled = false;
        }

        private void ModifyBtn_Click(object sender, EventArgs e)
        {
            try
            {
                adapter2.UpdateCommand = new SqlCommand("update Angajati set nume_angajat=@nume, prenume_angajat=@prenume, salariu=@salariu, id_locatie=@id_locatie where id_angajat=@id", connection);
                adapter2.UpdateCommand.Parameters.Add("@nume", SqlDbType.VarChar).Value = numebox.Text.ToString();
                adapter2.UpdateCommand.Parameters.Add("@prenume", SqlDbType.VarChar).Value = prenumebox.Text.ToString();
                adapter2.UpdateCommand.Parameters.Add("@salariu", SqlDbType.Float).Value = float.Parse(salariubox.Text.ToString());
                adapter2.UpdateCommand.Parameters.Add("@pozitia_curenta", SqlDbType.VarChar).Value = pozitiacurentabox.Text.ToString();
                adapter2.UpdateCommand.Parameters.Add("@id_locatie", SqlDbType.Int).Value = id_locatie;
                adapter2.UpdateCommand.Parameters.Add("@id", SqlDbType.Int).Value = Int32.Parse(idbox.Text.ToString());
                connection.Open();
                adapter2.UpdateCommand.ExecuteNonQuery();
                connection.Close();
                dataset2.Clear();
                adapter2.Fill(dataset2);
                MessageBox.Show("Modificare realizată cu succes!", "Informare");
                connection.Close();
                idbox.Enabled = true;
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }

        private void DeleteBtn_Click(object sender, EventArgs e)
        {
            try
            {
                adapter2.DeleteCommand = new SqlCommand("delete from Angajati where id_angajat=@id ", connection);
                adapter2.DeleteCommand.Parameters.Add("@id", SqlDbType.Int).Value = Int32.Parse(idbox.Text.ToString());
                connection.Open();
                adapter2.DeleteCommand.ExecuteNonQuery();
                connection.Close();
                dataset2.Clear();
                adapter2.Fill(dataset2);
                MessageBox.Show("Ștergere realizată cu succes!", "Informare");
                connection.Close();
                idbox.Enabled = true;
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }
    }
}