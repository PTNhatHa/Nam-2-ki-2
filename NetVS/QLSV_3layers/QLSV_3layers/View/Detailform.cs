using QLSV_3layers.BLL;
using QLSV_3layers.DAL;
using QLSV_3layers.DTO;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLSV_3layers.View
{
    public partial class Detailform : Form
    {
        private string MSSV;
        public delegate void MyDel(int IDLop, string NameSV);
        public MyDel d { get; set; }
        public Detailform(string m = null)
        {
            InitializeComponent();
            MSSV = m;
            if (MSSV != null)
            {
                txtMSSV.Text = MSSV;
            }
            SetGUI();
            SetCBBLSH();
        }
        private void SetGUI()
        {
            if(QLSVBLL.Instance.GetSVByMSSV(MSSV) != null)
            {
                SV s = QLSVBLL.Instance.GetSVByMSSV(MSSV);
                txtMSSV.Text = s.MSSV.ToString();
                txtHoTen.Text = s.HoTen.ToString();
                comboBoxLopSH.SelectedItem = QLSVBLL.Instance.GetNameLop(s.IDLop);
                dateTimePicker1.Value = s.NgaySinh;
                txtDTB.Text = s.DTB.ToString();
                if(s.GioiTinh == true ) 
                {
                    butNam.Checked = true;
                }
                else
                { 
                    ButNu.Checked = true; 
                }
                checkAnh.Checked = s.Anh;
                checkHB.Checked = s.HB;
                checkCCCD.Checked = s.CCCD;
            }
        }
        public void SetCBBLSH()
        {
            comboBoxLopSH.Items.AddRange(QLSVBLL.Instance.SetCBBLSH().ToArray());
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            bool check = true;
            if (txtMSSV.Text == "" || txtHoTen.Text == "" || comboBoxLopSH.SelectedItem == null || txtDTB.Text == "")
            {
                MessageBox.Show("Vui lòng điền đầy đủ thông tin!!!");
                check = false;
            }
            if(check)
            {
                SV s = new SV
                {
                    MSSV = Convert.ToInt32(txtMSSV.Text),
                    HoTen = txtHoTen.Text.ToString(),
                    IDLop = QLSVBLL.Instance.GetIDLop(comboBoxLopSH.SelectedItem.ToString()),
                    NgaySinh = Convert.ToDateTime(dateTimePicker1.Value.ToString()),
                    DTB = Convert.ToDouble(txtDTB.Text.ToString()),
                    GioiTinh = Convert.ToBoolean(ButNu.Checked.ToString()),
                    Anh = Convert.ToBoolean(checkAnh.Checked.ToString()),
                    HB = Convert.ToBoolean(checkHB.Checked.ToString()),
                    CCCD = Convert.ToBoolean(checkCCCD.Checked.ToString())
                };
                QLSVBLL.Instance.ExecuteDB(s);
                d(0, null);
                this.Close();
            }
            
        }
    }
}
