using System;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Laborator3
{
    public class Service
    {
        private SqlConnection connection1 = new SqlConnection("Data Source=DESKTOP-1S9740Q\\DDDD;Initial Catalog=Inchirieri_auto;Integrated Security=True");
        private SqlConnection connection2 = new SqlConnection("Data Source=DESKTOP-1S9740Q\\DDDD;Initial Catalog=Inchirieri_auto;Integrated Security=True");
        int count1 = 10, count2 = 10;

        public void ProcedureTables1()
        {
            while (count1 != 0)
            {
                try
                {
                    Console.WriteLine("1-Start");
                    SqlCommand cmd = new SqlCommand("deadlock_scenario1", connection1);
                    cmd.CommandType = CommandType.StoredProcedure;
                    cmd.Parameters.AddWithValue("@name", "Mihai");
                    cmd.Parameters.AddWithValue("@status", "incheiat");
                    connection1.Open();
                    cmd.ExecuteNonQuery();
                    connection1.Close();
                    count1 = 0;
                    Console.WriteLine("1-Succes");
                }
                catch (Exception e)
                {
                    Console.WriteLine("1-Fail" + e.Message);
                    connection1.Close();
                    count1--;
                }
            }
        }

        public void ProcedureTables2()
        {
            while (count2 != 0)
            {
                try
                {
                    Console.WriteLine("2-Start");
                    SqlCommand cmd = new SqlCommand("deadlock_scenario2", connection2);
                    cmd.CommandType = CommandType.StoredProcedure;
                    cmd.Parameters.AddWithValue("@status", "in curs");
                    cmd.Parameters.AddWithValue("@name", "Andrei");
                    connection2.Open();
                    cmd.ExecuteNonQuery();
                    connection2.Close();
                    count2 = 0;
                    Console.WriteLine("2-Succes");
                }
                catch (Exception e)
                {
                    Console.WriteLine("2-Fail" + e.Message);
                    connection2.Close();
                    count2--;
                }
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Service s = new Service();
            Thread t1 = new Thread(s.ProcedureTables1);
            Thread t2 = new Thread(s.ProcedureTables2);
            t1.Start();
            t2.Start();
            t1.Join();
            t2.Join();
            Console.Read();
        }
    }
}
