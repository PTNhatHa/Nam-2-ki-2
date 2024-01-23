using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLSV_cuaThay
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            SetCCBLSH();
        }

        public void SetCCBLSH()
        {
            //cbbLSH.Items.Add("All");
            //QLSV db = new QLSV();
            //cbbLSH.Items.AddRange(db.GetAllLSH().ToArray());
            SqlConnection cnn = new SqlConnection("Data Source=NHATHA;Initial Catalog=NET1;Integrated Security=True");
            string query = "select * from TenLop";
            SqlCommand cmd = new SqlCommand(query, cnn);
            SqlDataReader r;
            List<string> li = new List<string>();
            cnn.Open();
            r = cmd.ExecuteReader();
            while (r.Read())
            {
                li.Add(r["TenLop"].ToString());
            }
            cnn.Close();
            cbbLSH.Items.AddRange(li.ToArray());
        }

        private void Search_Click(object sender, EventArgs e)
        {
            //string LSH = cbbLSH.SelectedItem.ToString();
            //string txt = txtSearch.Text;
            //ShowDGV(LSH, txt);
            SqlConnection cnn = new SqlConnection("Data Source=NHATHA;Initial Catalog=NET1;Integrated Security=True");
            SqlParameter p1 = new SqlParameter("@Name", txtSearch.Text);
            string query = "select * from SV where TenSV = @Name";
            SqlCommand cmd = new SqlCommand(query, cnn);
            cmd.Parameters.Add(p1);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            DataTable dt = new DataTable();
            cnn.Open();
            da.Fill(dt);
            cnn.Close();
            dataGridView1.DataSource = dt;
        }

        public void ShowDGV(string LSH, string txt)
        {
            QLSV db = new QLSV();
            dataGridView1.DataSource = db.GetSVDGV(LSH, txt);
        }

        private void buttonDel_Click(object sender, EventArgs e)
        {
            if(dataGridView1.SelectedRows.Count > 0) 
            {
                //List<string> del = new List<string>();
                //foreach(DataGridViewRow i in dataGridView1.SelectedRows)
                //{
                //    del.Add(i.Cells["MSSV"].Value.ToString());
                //}
                //ShowDGV(cbbLSH.SelectedItem.ToString(), txtSearch.Text);

            }
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            DetailForm f = new DetailForm(null);
            f.d += new DetailForm.MyDel(ShowDGV);
            f.Show();
        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            if(dataGridView1.SelectedRows.Count == 1)
            {
                string MSSV = dataGridView1.SelectedRows[0].Cells["MSSV"].Value.ToString();
                DetailForm f = new DetailForm(MSSV);
                f.d += new DetailForm.MyDel(ShowDGV);
                f.Show();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string s = @"Data Source=NHATHA;Initial Catalog=NET1;Integrated Security=True";
            SqlConnection cnn = new SqlConnection(s);
            //SqlConnection cnn = new SqlConnection();
            //cnn.ConnectionString = @"Data Source=NHATHA;Initial Catalog=NET1;Integrated Security=True";

            //string query = "select count (*) from SV";
            //string query = "...";
            string query = "select * from SV"; //tên table 
            SqlCommand cmd = new SqlCommand(query, cnn);
            SqlDataReader r;
            List<SV1> li = new List<SV1>();

            cnn.Open();
            //int n = (int)cmd.ExecuteScalar();
            //MessageBox.Show(n.ToString());
            cmd.ExecuteNonQuery();
            r = cmd.ExecuteReader();
            while (r.Read())
            {
                li.Add(new SV1
                {
                    MSSV = r["MaSV"].ToString(),
                    Name = r["TenSV"].ToString(),
                    Gender = Convert.ToBoolean(r["Gender"].ToString()),
                    DTB = Convert.ToDouble(r["DTB"].ToString()),
                    ID_Lop = Convert.ToInt32(r["IDLop"].ToString())
                });
            }
            cnn.Close();
            //MessageBox.Show(cnn.State.ToString());
            dataGridView1.DataSource = li;
        }
        private void button2_Click(object sender, EventArgs e)
        {
            string s = @"Data Source=NHATHA;Initial Catalog=NET1;Integrated Security=True";
            SqlConnection cnn = new SqlConnection(s);
            string query = "select * from SV";
            SqlDataAdapter da = new SqlDataAdapter(query, cnn);
            DataSet ds = new DataSet();
            DataTable dt = new DataTable();
            cnn.Open();
            //da.Fill(ds);
            //da.Fill(ds, "SV"); //đặt tên cho 1 datatable của ds
            da.Fill(dt);
            cnn.Close();
            //dataGridView1.DataSource = ds.Tables[0];
            //dataGridView1.DataSource = ds.Tables["SV"];
            dataGridView1.DataSource = dt;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            string query = "select * from SV";
            dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            string query = "insert into SV (MaSV, TenSV, Gender, DTB, IDLop) values ('600', 'NVI', 0, 4.4, 1)";
            DBHelper.Instance.ExecuteDB(query);
            //dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            NET01DataContext db = new NET01DataContext();

            var l1 = from p in db.SVs select p; //query
            var l2 = db.SVs.Select(p => p); //method

            var l3 = from p in db.SVs
                     select new { p.MaSV, p.Name, p.LSH };
            var l4 = db.SVs.Select(p => new { p.MaSV, p.Name, p.LSH });

            int IDLop = ((CBBItem)cbbLSH.SelectedItem).Value;
            string txt = txtSearch.Text;

            var l11 = from p in db.SVs
                      where p.IDLop == IDLop
                      select new { p.MaSV, p.Name, p.LSH };
            var l12 = db.SVs.Where(p => p.IDLop == IDLop)
                    .Select(p => new { p.MaSV, p.Name, p.TenLop });
            var l21 = db.SVs.Where(p => p.IDLop == IDLop && p.Name.Contains(txt))
                    .Select(p => new { p.MaSV, p.Name, p.TenLop });

            dataGridView1.DataSource = l1.ToList();
        }
    }
}
