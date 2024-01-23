using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test_LINQ
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            SetCBBLSH();
        }

        public void SetCBBLSH()
        {
            DB01DataContext db = new DB01DataContext();
            cbbLSH.Items.Add(new CBBItem { Text = "ALL", Value = 0 });
            foreach(TenLop i in db.TenLops)
            {
                cbbLSH.Items.Add(new CBBItem { Text = i.TenLop1, Value = i.IDLop });
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            DB01DataContext db = new DB01DataContext();
            //var -> linh hoạt kiểu trả về (list các đối tượng khác nhau)

        //SELECT *
            var l1 = from p in db.SVs select p; //query
            var l2 = db.SVs.Select(p => p); //method

            var l3 = from p in db.SVs
                     select new { p.MaSV, p.TenSV, p.TenLop.TenLop1 };
            var l4 = db.SVs.Select(p => new { p.MaSV, p.TenSV, p.TenLop.TenLop1 });

        //SELECT ... WHERE
            var l11 = from p in db.SVs
                      where p.IDLop == 1
                      select new { p.MaSV, p.TenSV, p.TenLop.TenLop1 };
            var l12 = db.SVs.Where(p => p.IDLop == 1)
                    .Select(p => new { p.MaSV, p.TenSV, p.TenLop.TenLop1 }); //nếu bỏ đoạn này thì = SELECT *

            dataGridView1.DataSource = l4.ToList();
        }

        private void cbbLSH_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(cbbLSH.SelectedItem != null)
            {
                DB01DataContext db = new DB01DataContext();
                var l1 = db.SVs.Where(p => p.IDLop == ((CBBItem)cbbLSH.SelectedItem).Value)
                        .Select(p => new { p.MaSV, p.TenSV, p.TenLop.TenLop1 });
                dataGridView1.DataSource = l1.ToList();
                //dataGridView1.DataSource = GetListSVDGV(((CBBItem)cbbLSH.SelectedItem).Value, null);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(textBox1.Text != null)
            {
                DB01DataContext db = new DB01DataContext();
                var l1 = db.SVs.Where(p => p.IDLop == ((CBBItem)cbbLSH.SelectedItem).Value && p.TenSV.Contains(textBox1.Text))
                        .Select(p => new { p.MaSV, p.TenSV, p.TenLop.TenLop1 });
                dataGridView1.DataSource = l1.ToList();
                //dataGridView1.DataSource = GetListSVDGV(((CBBItem)cbbLSH.SelectedItem).Value, textBox1.Text);
            }    
        }
        public List<SV> GetListSVDGV(int ID, string Name)
        {
            DB01DataContext db = new DB01DataContext();
            if(ID == 0)
            {
                return db.SVs.ToList();
            }
            else
            {
                return db.SVs.Where(p => p.IDLop == ID && p.TenSV.Contains(Name)).ToList();
            }
        }

        private void button3_Click(object sender, EventArgs e) //add
        {
            //Form2 f = new Form2();
            //f.Show();

            SV s = new SV
            {
                MaSV = "123", TenSV = "ABC", Gender = false, DTB = 1.5, IDLop = 1
            };
            using(DB01DataContext db = new DB01DataContext())
            {
                db.SVs.InsertOnSubmit(s);
                db.SubmitChanges();
            }
        }

        private void button4_Click(object sender, EventArgs e) //edit
        {
            string MSSV = dataGridView1.SelectedRows[0].Cells[0].Value.ToString();
            using (DB01DataContext db = new DB01DataContext())
            {
                var s1 = db.SVs.Where(p => p.MaSV == MSSV).FirstOrDefault();
                var s2 = db.SVs.Single(p => p.MaSV == MSSV);
                s1.TenSV = "Aloooo";
                db.SubmitChanges();
            }
        }

        private void buttonDel_Click(object sender, EventArgs e)
        {
            foreach(DataGridViewRow i in dataGridView1.SelectedRows)
            {
                string MSSV = i.Cells[0].Value.ToString();
                using (DB01DataContext db = new DB01DataContext())
                {
                    var s1 = db.SVs.Where(p => p.MaSV == MSSV).FirstOrDefault();
                    var s2 = db.SVs.Single(p => p.MaSV == MSSV);
                    db.SVs.DeleteOnSubmit(s1);
                    db.SubmitChanges();
                }
            }
        }

        private void buttonSortAll_Click(object sender, EventArgs e)
        {
            using(DB01DataContext db = new DB01DataContext()) 
            {
                dataGridView1.DataSource = 
                    db.SVs.OrderBy(p => p.DTB)
                    .Select(p => new {p.MaSV, p.TenSV, p.DTB})
                    .ToList();
            }
        }

        private void buttonSortDGV_Click(object sender, EventArgs e)
        {
            List<SV> li = new List<SV>();
            foreach(DataGridViewRow i in dataGridView1.Rows)
            {
                string MSSV = i.Cells[0].Value.ToString();
                using (DB01DataContext db = new DB01DataContext())
                {
                    li.Add(db.SVs.Single(p => p.MaSV == MSSV));
                }
            }
            dataGridView1.DataSource = li.OrderBy(p => p.DTB)
                    .Select(p => new { p.MaSV, p.TenSV, p.DTB })
                    .ToList();
        }
    }
}
