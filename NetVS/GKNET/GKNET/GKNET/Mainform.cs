using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GKNET
{
    public partial class Mainform : Form
    {
        public Mainform()
        {
            InitializeComponent();
            SetDGV();
            SetCBBKhoa();
            SetCBBSort();
        }

        private void SetDGV()
        {
            string query = "SELECT Giảng_Viên.[Mã giảng viên], Học_phần.[Mã học phần], [Tên giảng viên], [Ngày sinh], [Giới tính], [Học hàm], [Học vị], Khoa, [Tên học phần] " +
                            "FROM Giảng_Viên, Học_phần, GV_HP " +
                            "WHERE Giảng_Viên.[Mã giảng viên] = GV_HP.[Mã giảng viên] " +
                            "AND Học_phần.[Mã học phần] = GV_HP.[Mã học phần] ";
            dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
            dataGridView1.Columns["Mã giảng viên"].Visible = false;
            dataGridView1.Columns["Mã học phần"].Visible = false;
        }

        private void SetCBBKhoa()
        {
            string query = "SELECT Khoa FROM Giảng_Viên";
            List<string> li = new List<string>();
            li.Add("All");
            foreach(DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                li.Add(i["Khoa"].ToString());
            }
            cbbKhoa.Items.AddRange(li.Distinct().ToArray());
        }

        private void SetCBBSort()
        {
            cbbSort.Items.Add("Tên giảng viên");
            cbbSort.Items.Add("Ngày sinh");
            cbbSort.Items.Add("Tên học phần");
        }

        private void buttonSearch_Click(object sender, EventArgs e)
        {
            if(txtSearch != null && cbbKhoa.SelectedItem != null)
            {
                string query;
                if (cbbKhoa.SelectedItem.ToString() == "All" )
                {
                    
                    query = "SELECT Giảng_Viên.[Mã giảng viên], Học_phần.[Mã học phần], [Tên giảng viên], [Ngày sinh], [Giới tính], [Học hàm], [Học vị], Khoa, [Tên học phần] " +
                                    "FROM Giảng_Viên, Học_phần, GV_HP " +
                                    "WHERE Giảng_Viên.[Mã giảng viên] = GV_HP.[Mã giảng viên] " +
                                    "AND Học_phần.[Mã học phần] = GV_HP.[Mã học phần] " +
                                    "AND Giảng_Viên.[Tên giảng viên] = N'" + txtSearch.Text + "' ";


                }
                else
                {

                    query = "SELECT Giảng_Viên.[Mã giảng viên], Học_phần.[Mã học phần], [Tên giảng viên], [Ngày sinh], [Giới tính], [Học hàm], [Học vị], Khoa, [Tên học phần] " +
                                    "FROM Giảng_Viên, Học_phần, GV_HP " +
                                    "WHERE Giảng_Viên.[Mã giảng viên] = GV_HP.[Mã giảng viên] " +
                                    "AND Học_phần.[Mã học phần] = GV_HP.[Mã học phần] " +
                                    "AND Giảng_Viên.[Tên giảng viên] = N'" + txtSearch.Text + "' " +
                                    "AND Giảng_Viên.Khoa = N'" + cbbKhoa.SelectedItem.ToString() + "'";
                }
                dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
            }    

        }

        private void buttonSort_Click(object sender, EventArgs e)
        {
            string query = "";
            if(cbbSort.SelectedItem != null) 
            {
                query = "SELECT Giảng_Viên.[Mã giảng viên], Học_phần.[Mã học phần], [Tên giảng viên], [Ngày sinh], [Giới tính], [Học hàm], [Học vị], Khoa, [Tên học phần] " +
                            "FROM Giảng_Viên, Học_phần, GV_HP " +
                            "WHERE Giảng_Viên.[Mã giảng viên] = GV_HP.[Mã giảng viên] " +
                            "AND Học_phần.[Mã học phần] = GV_HP.[Mã học phần] " +
                            "ORDER BY [" + cbbSort.SelectedItem.ToString() + "] ASC";
                dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
            }

        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            string query = "";
            if (dataGridView1.SelectedRows.Count > 0)
            {
                List<string> del1 = new List<string>();
                List<string> del2 = new List<string>();
                foreach (DataGridViewRow i in dataGridView1.SelectedRows)
                {
                    del1.Add(i.Cells["Mã giảng viên"].Value.ToString());
                    del2.Add(i.Cells["Mã học phần"].Value.ToString());
                }
                for(int i = 0; i < dataGridView1.SelectedRows.Count; i++) 
                {
                    SqlParameter[] p = new SqlParameter[2];
                    p[0] = new SqlParameter("@MGV", del1[i]);
                    p[1] = new SqlParameter("@MHP", del2[i]);
                    query = "DELETE FROM GV_HP " +
                            "WHERE GV_HP.[Mã giảng viên] = @MGV " +
                            "AND GV_HP.[Mã học phần] = @MHP";
                    DBHelper.Instance.ExecuteDB(query, p);
                }
                SetDGV();
            }
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            DetailForm f = new DetailForm(null);
            f.Show();
        }
    }
}
