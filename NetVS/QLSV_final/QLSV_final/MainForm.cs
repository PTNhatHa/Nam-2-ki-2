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

namespace QLSV_final
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            SetCBBLSH();
        }
        public void SetCBBLSH()
        {
            string query = "select LSH from Information";
            List<string> li = new List<string>();
            li.Add("All");
            foreach(DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                li.Add(i["LSH"].ToString());
            }
            cbbLopSH.Items.AddRange(li.Distinct().ToArray());
        }

        private void cbbLopSH_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(cbbLopSH.SelectedItem != null ) 
            {
                string lsh = cbbLopSH.SelectedItem.ToString();
                string query = "";
                if (lsh == "All")
                {
                    query = "select * from Information";
                }
                else
                {
                    query = "select * from Information where LSH = '" + lsh + "'";
                }
                dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
            }
        }

        private void Search_Click(object sender, EventArgs e)
        {
            string query = "select * from Information where HoTen = '" + txtSearch.Text + "'";
            dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
        }

        private void buttonDel_Click(object sender, EventArgs e)
        {
            string query = "";
            if(dataGridView1.SelectedRows.Count > 0) 
            {
                List<string> del = new List<string>(); 
                foreach(DataGridViewRow i in dataGridView1.SelectedRows) 
                {
                    del.Add(i.Cells["MSSV"].Value.ToString());
                }
                foreach(string i in del)
                {
                    SqlParameter[] p = new SqlParameter[1];
                    p[0] = new SqlParameter("@MSSV", i);
                    query = "delete from Information where MSSV = @MSSV";
                    DBHelper.Instance.ExecuteDB(query, p);
                }
                string query1 = "select * from Information";
                dataGridView1.DataSource = DBHelper.Instance.GetRecords(query1);

            }
        }

        public void SetCBBSort()
        {
            cbbSort.Items.Add("Ascending");
            cbbSort.Items.Add("Descending");
        }
        private void buttonSort_Click(object sender, EventArgs e)
        {
            string query = "";
            string txt = cbbSort.SelectedItem.ToString();
            if (cbbSort.SelectedItem != null)
            {
                if (txt == "Ascending")
                {
                    query = "select * from Information order by MSSV asc";
                }
                if (txt == "Descending")
                {
                    query = "select * from Information order by MSSV desc";
                }
                dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
            }
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            Information info = new Information(null);
            info.Show();
            string query = "select * from Information";
            dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);

        }
        private void buttonEdit_Click(object sender, EventArgs e)
        {
            if(dataGridView1.SelectedRows.Count == 1) 
            {
                DataGridViewRow dt = dataGridView1.SelectedRows[0];
                string mssv = dt.Cells["MSSV"].Value.ToString();
                Information info = new Information(mssv);
                info.Show();
                string query = "select * from Information";
                dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
            }
        }

    }
}
