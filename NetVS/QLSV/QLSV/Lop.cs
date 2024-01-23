using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Tab;

namespace QLSV
{
    public partial class Lop : Form
    {
        SV DataSV { get; set; }
        public Lop()
        {
            InitializeComponent();
            //DataSV = new SV();
            //GetLopSH();
        }

        private void GetLopSH()
        {
            comboLopSH.Items.Clear();
            comboLopSH.Items.Add("All");
            comboLopSH.Items.AddRange(DataSV.GetLopSH().Distinct().ToArray());
        }
        private void comboLopSH_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(comboLopSH.SelectedIndex >= 0) 
            {
                dataGridView1.DataSource = DataSV.GetSV_LopSH(comboLopSH.SelectedItem.ToString());
            }
        }
        private void Search_Click(object sender, EventArgs e)
        {
                dataGridView1.DataSource = DataSV.GetSV_MSSV(txtSearch.Text.ToString());
        }
        private void buttonDel_Click(object sender, EventArgs e)
        {
            foreach (DataGridViewRow i in this.dataGridView1.SelectedRows)
            {
                dataGridView1.Rows.RemoveAt(i.Index);
            }
        }
        public void Add(DataTable data)
        {
            int j = 0;
            String[] s = new string[10];
            foreach (DataRow i in data.Rows)
            {
                s[0] = i[0].ToString();
                s[1] = i[1].ToString();
                s[2] = i[2].ToString();
                s[3] = i[3].ToString();
                s[4] = i[4].ToString();
                s[5] = i[5].ToString();
                s[6] = i[6].ToString();
                s[7] = i[7].ToString();
                s[8] = i[8].ToString();
            }
         
            string mssv = s[0];
            string ht = s[1];
            string lop = s[2];
            DateTime ns = Convert.ToDateTime(s[3]);
            double dtb = Convert.ToDouble(s[4]);
            bool gt = Convert.ToBoolean(s[5]);
            bool anh = Convert.ToBoolean(s[6]);
            bool hb = Convert.ToBoolean(s[7]);
            bool cccd = Convert.ToBoolean(s[8]);
            
            //DataSV.DT.Rows.Add(new object[]
            //{
            //    mssv, ht, lop, ns, dtb, gt, anh, hb, cccd
            //});

            //dataGridView1.DataSource = DataSV.DT;
        }
        private void buttonAdd_Click(object sender, EventArgs e)
        {
            TTCN tt = new TTCN();
            tt.d += new TTCN.MyDel(Add);
            tt.Show();
        }
        public void Edit(DataTable data)
        {
            int j = 0;
            String[] s = new string[10];
            foreach (DataRow i in data.Rows)
            {
                s[0] = i[0].ToString();
                s[1] = i[1].ToString();
                s[2] = i[2].ToString();
                s[3] = i[3].ToString();
                s[4] = i[4].ToString();
                s[5] = i[5].ToString();
                s[6] = i[6].ToString();
                s[7] = i[7].ToString();
                s[8] = i[8].ToString();
            }

            string mssv = s[0];
            string ht = s[1];
            string lop = s[2];
            DateTime ns = Convert.ToDateTime(s[3]);
            double dtb = Convert.ToDouble(s[4]);
            bool gt = Convert.ToBoolean(s[5]);
            bool anh = Convert.ToBoolean(s[6]);
            bool hb = Convert.ToBoolean(s[7]);
            bool cccd = Convert.ToBoolean(s[8]);

            //foreach (DataRow i in DataSV.DT.Rows)
            //{
            //    if (i["MSSV"].ToString() == mssv)
            //    {
            //        i["Họ Tên"] = ht;
            //        i["Lớp SH"] = lop;
            //        i["Ngày Sinh"] = ns;
            //        i["DTB"] = dtb;
            //        i["Giới Tính"] = gt;
            //        i["Ảnh"] = anh;
            //        i["Học Bạ"] = hb;
            //        i["CCCD"] = cccd;
            //    }
            //}

        }
        private void buttonEdit_Click(object sender, EventArgs e)
        {
            if (dataGridView1.SelectedRows.Count == 1)
            {
                TTCN tt = new TTCN();
                tt.d += new TTCN.MyDel(Edit);
                tt.Show();
            }
            if (dataGridView1.SelectedRows.Count == 0)
            {
                MessageBox.Show("Vui lòng chọn 1 đối tượng muốn Edit");
            }
            if (dataGridView1.SelectedRows.Count > 1)
            {
                MessageBox.Show("Chỉ chọn 1 đối tượng muốn Edit");
            }
        }
        private void buttonSort_Click(object sender, EventArgs e)
        {
            string txt = comboSort.SelectedItem.ToString();
            if(txt == "Ascending")
            {
                dataGridView1.Sort(dataGridView1.Columns["MSSV"], ListSortDirection.Ascending);
            }
            if (txt == "Descending")
            {
                dataGridView1.Sort(dataGridView1.Columns["MSSV"], ListSortDirection.Descending);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DB1DataContext db = new DB1DataContext();
            var l1 = from p in db.SVs select p; //query
            var l2 = db.SVs.Select(p => p); //method

            var l3 = from p in db.SVs
                     select new { p.MaSV, p.TenSV, p.TenLop };
            var l4 = db.SVs.Select(p => new { p.MaSV, p.TenSV, p.TenLop });

            int IDLop = ((CBBItem)comboLopSH.SelectedItem).Value;
            string txt = txtSearch.Text;

            var l11 = from p in db.SVs
                      where p.IDLop == IDLop
                      select new { p.MaSV, p.TenSV, p.TenLop };
            var l12 = db.SVs.Where(p => p.IDLop == IDLop)
                    .Select(p => new { p.MaSV, p.TenSV, p.TenLop });
            var l21 = db.SVs.Where(p => p.IDLop == IDLop && p.TenSV.Contains(txt))
                    .Select(p => new { p.MaSV, p.TenSV, p.TenLop });

            dataGridView1.DataSource = l1.ToList();
        }
    }
}
