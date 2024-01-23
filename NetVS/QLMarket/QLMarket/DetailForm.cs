using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ProgressBar;

namespace QLMarket
{
    public partial class DetailForm : Form
    {
        string MSP;
        public DetailForm(string mSP)
        {
            InitializeComponent();
            SetCBB();
            if (mSP != null) 
            {
                MSP = mSP;
                txtMSP.Text = MSP;
                txtMSP.ReadOnly = true;
            }
        }

        private void SetCBB()
        {
            string query = "SELECT TMH FROM MẶT_HÀNG";
            List<string> MH = new List<string>();
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                MH.Add(i["TMH"].ToString());
            }
            cbbMH.Items.AddRange(MH.Distinct().ToArray());
        }
        private void cbbMH_SelectedIndexChanged(object sender, EventArgs e)
        {
            cbbNSX.Items.Clear();
            cbbNSX.Text = string.Empty;
            string query = "SELECT SX FROM MẶT_HÀNG WHERE TMH = N'" + cbbMH.SelectedItem.ToString() + "'";
            List<string> SX = new List<string>();
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                SX.Add(i["SX"].ToString());
            }
            cbbNSX.Items.AddRange(SX.Distinct().ToArray());
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            string s = "error";
            bool check = true;
            if (cbbMH.SelectedItem != null || cbbNSX.SelectedItem != null)
            {
                string q = "SELECT MMH FROM MẶT_HÀNG " +
                                "WHERE TMH = N'" + cbbMH.SelectedItem.ToString() + "' AND SX = N'" + cbbNSX.SelectedItem.ToString() + "'";

                foreach (DataRow i in DBHelper.Instance.GetRecords(q).Rows)
                {
                    s = i["MMH"].ToString();
                }
            }    
            if (MSP == null)
            {
                if (txtMSP.Text == null || txtTSP.Text == null || (radioButton1.Checked == false && radioButton2.Checked == false))
                {
                    MessageBox.Show("Vui lòng điền đầy đủ thông tin!");
                    check = false;
                }
                else
                {
                    string query = "SELECT MSP FROM SẢN_PHẨM";
                    foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
                    {
                        if (i["MSP"].ToString() == txtMSP.Text)
                        {
                            MessageBox.Show("Vui lòng không nhập trùng MSP!");
                            check = false;
                        }
                    }

                }
                if (check)
                {
                    //SqlParameter[] p = new SqlParameter[5];
                    //p[0] = new SqlParameter("@MSH", txtMSP.Text);
                    //p[1] = new SqlParameter("@TENSP", txtTSP.Text);
                    //p[2] = new SqlParameter("@NGAY", Convert.ToDateTime(dateTimePicker1.Value.ToString()));
                    //p[3] = new SqlParameter("@TT", Convert.ToBoolean(radioButton1.Checked.ToString()));
                    //p[4] = new SqlParameter("@MMH", s);
                    //string query = "INSERT INTO SẢN_PHẨM (MSP, [Tên sản phẩm], [Ngày nhập], [Tình trạng], MMH) " +
                    //                "VALUES (@MSH, @TENSP, @NGAY, @TT, @MMH)";
                    //DBHelper.Instance.ExecuteDB(query, p);
                    //MessageBox.Show("Add thành công!");
                    //this.Close();

                }
            }

            if (MSP != null)
            {
                if (txtTSP.Text == null || cbbMH.SelectedItem == null || cbbNSX.SelectedItem == null || (radioButton1.Checked == false && radioButton2.Checked == false))
                {
                    MessageBox.Show("Vui lòng điền đầy đủ thông tin!");
                    check = false;
                }
                if (check)
                {
                    //SqlParameter[] p = new SqlParameter[5];
                    //p[0] = new SqlParameter("@MSH", txtMSP.Text);
                    //p[1] = new SqlParameter("@TENSP", txtTSP.Text);
                    //p[2] = new SqlParameter("@NGAY", Convert.ToDateTime(dateTimePicker1.Value.ToString()));
                    //p[3] = new SqlParameter("@TT", Convert.ToBoolean(radioButton1.Checked.ToString()));
                    //p[4] = new SqlParameter("@MMH", s);
                    //string query = "UPDATE SẢN_PHẨM SET [Tên sản phẩm] = @TENSP, [Ngày nhập] = @NGAY, [Tình trạng] = @TT, MMH = @MMH WHERE MSP = @MSH";
                    //DBHelper.Instance.ExecuteDB(query, p);
                    //MessageBox.Show("Update thành công!");
                    //this.Close();

                }
            }
        }
    }
}
