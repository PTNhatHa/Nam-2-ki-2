using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DBFirst
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using(QLSVEntity db = new QLSVEntity()) 
            {
                dataGridView1.DataSource = 
                    db.SVs.Select(p => new { p.MaSV, p.TenSV, p.TenLop.TenLop1})
                    .ToList();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string MSSV = dataGridView1.SelectedRows[0].Cells[0].Value.ToString();
            using (QLSVEntity db = new QLSVEntity())
            {
                var s = db.SVs.Find(MSSV);
                db.SVs.Remove(s);
                db.SaveChanges();
            }
        }
    }
}
