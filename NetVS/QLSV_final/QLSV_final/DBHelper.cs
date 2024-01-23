using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLSV_final
{
    internal class DBHelper
    {
        private SqlConnection _cnn;
        private static DBHelper instance;
        public static DBHelper Instance 
        {
            get
            {
                if(instance == null)
                {
                    instance = new DBHelper("Data Source=NHATHA;Initial Catalog=QLSV_final;Integrated Security=True");
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
        public void ExecuteDB(string query, SqlParameter[] p)
        {
            SqlCommand cmd = new SqlCommand(query, _cnn);
            foreach (SqlParameter i in p) 
            {
                cmd.Parameters.Add(i);
            }
            
            _cnn.Open();
            cmd.ExecuteNonQuery();
            _cnn.Close();
        }
    }
}
