using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Test_3Layers.BLL;
using Test_3Layers.DTO;

namespace Test_3Layers
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public void SetCBBLSH()
        {
            QLSVBLL bll = new QLSVBLL();
            cbbLSH.Items.AddRange(bll.GetCBB().ToArray());
        }
        private void button1_Click(object sender, EventArgs e)
        {
            //int ID_Lop = ((CBBItem)cbbLSH.SelectedItem).Value;
            //QLSVBLL bll = new QLSVBLL();
            //dataGridView1.DataSource = bll.GetSVByIDLop(ID_Lop);
            QLSVBLL bll = new QLSVBLL();
            dataGridView1.DataSource = bll.GetSVView();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SV s = new SV()
            {
                MSSV = "109",
                NameSV = "abc",
                Gender = true,
                DTB = 1.0,
                ID_Lop = 1
            };
            QLSVBLL bll = new QLSVBLL();
            bll.AddSVBLL(s);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if(dataGridView1.SelectedRows.Count == 1) 
            {
                QLSVBLL bll = new QLSVBLL();
                SV s = new SV();
                bll.UpdateSVBLL(s);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if(dataGridView1.SelectedRows.Count > 0)
            {
                QLSVBLL bll = new QLSVBLL();
                foreach(DataGridViewRow i in dataGridView1.SelectedRows)
                {
                    string MSSV = i.Cells[0].Value.ToString();
                    bll.DelSVBLL(MSSV);
                }
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            List<string> li = new List<string>();
            foreach(DataGridViewRow i in dataGridView1.SelectedRows)
            {
                li.Add(i.Cells[0].Value.ToString());
            }
            QLSVBLL bll = new QLSVBLL();
            dataGridView1.DataSource = bll.SortBy(li, "...");
        }
    }
}
