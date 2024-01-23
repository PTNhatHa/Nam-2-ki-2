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

namespace GKNET
{
    public partial class DetailForm : Form
    {
        string MGV;
        public DetailForm(string mGV)
        {
            InitializeComponent();
            SetCBBKhoa();
            SetCBBHH();
            SetCBBHV();
            SetCBBHP();
        }

        private void SetCBBKhoa()
        {
            string query = "SELECT Khoa FROM Giảng_Viên";
            List<string> li = new List<string>();
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                li.Add(i["Khoa"].ToString());
            }
            cbbKhoa.Items.AddRange(li.Distinct().ToArray());
        }
        private void SetCBBHH()
        {
            string query = "SELECT [Học hàm] FROM Giảng_Viên";
            List<string> li = new List<string>();
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                li.Add(i["Học hàm"].ToString());
            }
            cbbHH.Items.AddRange(li.Distinct().ToArray());
        }
        private void SetCBBHV()
        {
            string query = "SELECT [Học vị] FROM Giảng_Viên";
            List<string> li = new List<string>();
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                li.Add(i["Học vị"].ToString());
            }
            cbbHV.Items.AddRange(li.Distinct().ToArray());
        }
        private void SetCBBHP()
        {
            string query = "SELECT [Tên học phần] FROM Học_phần";
            List<string> li = new List<string>();
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                li.Add(i["Tên học phần"].ToString());
            }
            cbbHP.Items.AddRange(li.Distinct().ToArray());
        }

        private void Cancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private string MGVnew()
        {
            string query = "SELECT Giảng_Viên.[Mã giảng viên] FROM Giảng_Viên";
            List<string> li = new List<string>();
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                li.Add(i["Mã giảng viên"].ToString());
            }
            int ms = Convert.ToInt32(li[li.Count - 1]) + 1;
            return Convert.ToString(ms);
        }
        private void OK_Click(object sender, EventArgs e)
        {

            bool check = true;
            if (txtTGV.Text == null || cbbKhoa.SelectedItem == null || Male.Checked == Female.Checked || cbbHH.SelectedItem == null || cbbHV.SelectedItem == null || cbbHP.SelectedItem == null)
            {
                MessageBox.Show("Vui lòng điền đầy đủ thông tin!");
                check = false;
            }
            if (check)
            {
                SqlParameter[] p = new SqlParameter[7];
                p[0] = new SqlParameter("@TGV", txtTGV.Text);
                p[1] = new SqlParameter("@KHOA", cbbKhoa.SelectedItem.ToString());
                p[2] = new SqlParameter("@HH", cbbHH.SelectedItem.ToString());
                p[3] = new SqlParameter("@HV", cbbHV.SelectedItem.ToString());
                p[4] = new SqlParameter("@HP", cbbHV.SelectedItem.ToString());
                p[5] = new SqlParameter("@GT", Male.Checked);
                p[6] = new SqlParameter("@MGV", MGVnew());
                p[7] = new SqlParameter("@NS", Convert.ToDateTime(dateTimePicker1.Text.ToString()));
                string query = "INSERT INTO Giảng_Viên ([Mã giảng viên], [Tên giảng viên], [Ngày sinh], Khoa, [Học hàm], [Học vị], [Giới tính] ) " +
                                "VALUES (@MGV, @TGV, @N)";
            }
        }
    }
}
