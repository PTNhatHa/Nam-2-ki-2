using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLSV
{
    public partial class TTCN : Form
    {
        public TTCN()
        {
            InitializeComponent();
        }

        public delegate void MyDel(DataTable data);
        public MyDel d { get; set; }
        private void buttonOK_Click(object sender, EventArgs e)
        {
            DataTable data = new DataTable();
            data.Columns.AddRange(new DataColumn[]
            {
                new DataColumn {ColumnName = "MSSV", DataType = typeof(string)},
                new DataColumn {ColumnName = "Họ Tên", DataType = typeof(string)},
                new DataColumn {ColumnName = "Lớp SH", DataType = typeof(string)},
                new DataColumn {ColumnName = "Ngày Sinh", DataType = typeof(DateTime)},
                new DataColumn {ColumnName = "DTB", DataType = typeof(double)},
                new DataColumn {ColumnName = "Giới Tính", DataType = typeof(bool)},
                new DataColumn {ColumnName = "Ảnh", DataType = typeof(bool)},
                new DataColumn {ColumnName = "Học Bạ", DataType = typeof(bool)},
                new DataColumn {ColumnName = "CCCD", DataType = typeof(bool)}
            });

            string mssv = txtMSSV.Text.ToString();
            string ht = txtHoTen.Text.ToString();
            string lop = comboBoxLopSH.SelectedItem.ToString();
            DateTime ns = Convert.ToDateTime(dateTimePicker1.Value.ToString());
            double dtb = Convert.ToDouble(txtDTB.Text.ToString());
            bool gt = ButNu.Checked;
            bool anh = checkAnh.Checked;
            bool hb = checkHB.Checked;
            bool cccd = checkCCCD.Checked;

            data.Rows.Add(new object[]
            {
                mssv, ht, lop, ns, dtb, gt, anh, hb, cccd
            });
            d(data);
            
        }
        private void buttonCancel_Click(object sender, EventArgs e)
        {
           this.Close();
        }
    }
}
