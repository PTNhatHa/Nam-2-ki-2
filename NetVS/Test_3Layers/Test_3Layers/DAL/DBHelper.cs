using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_3Layers.DAL
{
    internal class DBHelper
    {
        private SqlConnection _cnn;
        private static DBHelper instance;
        public static DBHelper Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new DBHelper("Data Source=NHATHA;Initial Catalog=NET1;Integrated Security=True");
                }
                return instance;
            }
            private set { }
        }
        public DBHelper(string s)
        {
            _cnn = new SqlConnection(s);
        }

        public DataTable GetRecords(string query)
        {
            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(query, _cnn);
            _cnn.Open();
            da.Fill(dt);
            _cnn.Close();
            return dt;
        }
        public void ExecuteDB(string query)
        {
            SqlCommand cmd = new SqlCommand(query, _cnn);
            _cnn.Open();
            cmd.ExecuteNonQuery();
            _cnn.Close();
        }
    }
}
