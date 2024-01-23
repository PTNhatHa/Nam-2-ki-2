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
    public partial class Information : Form
    {
        string MSSV;
        public Information(string mssv)
        {
            InitializeComponent();
            MSSV = mssv;
            SetCBB();
            if(MSSV != null) 
            {
                txtMSSV.Text = MSSV;
            }
        }
        public void SetCBB()
        {
            comboBoxLopSH.Items.Add("21DT1");
            comboBoxLopSH.Items.Add("21DT2");
            comboBoxLopSH.Items.Add("21DT3");
            comboBoxLopSH.Items.Add("21DT4");
            comboBoxLopSH.Items.Add("21DT5");
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            if(MSSV == null)
            {
                bool check = true;
                if (txtMSSV.Text == "" || txtHoTen.Text == "" || comboBoxLopSH.SelectedItem == null || txtDTB.Text == "")
                {
                    MessageBox.Show("Vui lòng điền đầy đủ thông tin!!!");
                    check = false;
                }
                else
                {
                    string query1 = "select * from Information";
                    foreach (DataRow i in DBHelper.Instance.GetRecords(query1).Rows)
                    {
                        if (i["MSSV"].ToString() == txtMSSV.Text)
                        {
                            MessageBox.Show("Vui lòng nhập MSSV không trùng!!!");
                            check = false;
                        }
                    }
                }
                if (check == true)
                {
                    SqlParameter[] p = new SqlParameter[9];
                    p[0] = new SqlParameter("@MSSV", txtMSSV.Text);
                    p[1] = new SqlParameter("@HOTEN", txtHoTen.Text);
                    p[2] = new SqlParameter("@LSH", comboBoxLopSH.SelectedItem.ToString());
                    p[3] = new SqlParameter("@NS", Convert.ToDateTime(dateTimePicker1.Value.ToString()));
                    p[4] = new SqlParameter("@DTB", Convert.ToDouble(txtDTB.Text.ToString()));
                    p[5] = new SqlParameter("@GT", Convert.ToBoolean(ButNu.Checked.ToString()));
                    p[6] = new SqlParameter("@ANH", Convert.ToBoolean(checkAnh.Checked.ToString()));
                    p[7] = new SqlParameter("@HB", Convert.ToBoolean(checkHB.Checked.ToString()));
                    p[8] = new SqlParameter("@CCCD", Convert.ToBoolean(checkCCCD.Checked.ToString()));

                    string query = "insert into Information (MSSV, HoTen, LSH, NgaySinh, DTB, GioiTinh, Anh, HB, CCCD) " +
                        "values (@MSSV, @HOTEN, @LSH, @NS, @DTB, @GT, @ANH, @HB, @CCCD)";

                    DBHelper.Instance.ExecuteDB(query, p);
                }
            }

            if (MSSV != null)
            {
                bool check = true;
                if (txtHoTen.Text == "" || comboBoxLopSH.SelectedItem == null || txtDTB.Text == "")
                {
                    MessageBox.Show("Vui lòng điền đầy đủ thông tin!!!");
                    check = false;
                }
                if (MSSV != txtMSSV.Text)
                {
                    MessageBox.Show("Vui lòng không thay đổi MSSV!!!");
                    check = false;
                }
                if (check == true)
                {
                    SqlParameter[] p = new SqlParameter[9];
                    p[0] = new SqlParameter("@MSSV", txtMSSV.Text);
                    p[1] = new SqlParameter("@HOTEN", txtHoTen.Text);
                    p[2] = new SqlParameter("@LSH", comboBoxLopSH.SelectedItem.ToString());
                    p[3] = new SqlParameter("@NS", Convert.ToDateTime(dateTimePicker1.Value.ToString()));
                    p[4] = new SqlParameter("@DTB", Convert.ToDouble(txtDTB.Text.ToString()));
                    p[5] = new SqlParameter("@GT", Convert.ToBoolean(ButNu.Checked.ToString()));
                    p[6] = new SqlParameter("@ANH", Convert.ToBoolean(checkAnh.Checked.ToString()));
                    p[7] = new SqlParameter("@HB", Convert.ToBoolean(checkHB.Checked.ToString()));
                    p[8] = new SqlParameter("@CCCD", Convert.ToBoolean(checkCCCD.Checked.ToString()));

                    string query = "update Information set HoTen = @HOTEN, LSH = @LSH, NgaySinh = @NS, DTB = @DTB, " +
                                    "GioiTinh = @GT, Anh = @ANH, HB = @HB, CCCD = @CCCD where MSSV = @MSSV ";

                    DBHelper.Instance.ExecuteDB(query, p);
                }
            }
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
