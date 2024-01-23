using QLSV_3layers.BLL;
using QLSV_3layers.DTO;
using QLSV_3layers.View;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;

namespace QLSV_3layers
{
    public partial class Mainform : Form
    {
        public Mainform()
        {
            InitializeComponent();
            SetCBBLSH();
            SetCBBSort();
        }
        public void SetCBBLSH()
        {
            cbbLopSH.Items.Add(new CBBItem { Value = 0, Text = "ALL" });
            cbbLopSH.Items.AddRange(QLSVBLL.Instance.SetCBBLSH().ToArray());
        }

        private void SetDGV(int IDLop, string NameSV)
        {
            dataGridView1.DataSource = QLSVBLL.Instance.GetListSV(IDLop, NameSV);
        }
        private void cbbLopSH_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(cbbLopSH.SelectedItem != null) 
            {
                SetDGV(((CBBItem)cbbLopSH.SelectedItem).Value, null);
            }
        }

        private void Search_Click(object sender, EventArgs e)
        {
            if (cbbLopSH.SelectedItem != null && txtSearch.Text == null)
            {
                SetDGV(((CBBItem)cbbLopSH.SelectedItem).Value, null);
            }
            if (cbbLopSH.SelectedItem != null && txtSearch.Text != null)
            {
                SetDGV(((CBBItem)cbbLopSH.SelectedItem).Value, txtSearch.Text);
            }
            if (cbbLopSH.SelectedItem == null && txtSearch.Text != null)
            {
                SetDGV(0, txtSearch.Text);
            }

        }

        private void buttonDel_Click(object sender, EventArgs e)
        {
            if (dataGridView1.SelectedRows.Count > 0)
            {
                List<string> del = new List<string>();
                foreach (DataGridViewRow i in dataGridView1.SelectedRows)
                {
                    QLSVBLL.Instance.DelSVBLL(i.Cells["MSSV"].Value.ToString());
                }
            }
            SetDGV(0, null);
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            Detailform f = new Detailform(null);
            f.d = new Detailform.MyDel(SetDGV);
            f.Show();
        }

        private void buttonEdit_Click(object sender, EventArgs e)
        {
            if(dataGridView1.SelectedRows.Count == 1)
            {
                string MSSV = dataGridView1.SelectedRows[0].Cells["MSSV"].Value.ToString();
                Detailform f = new Detailform(MSSV);
                f.d = new Detailform.MyDel(SetDGV);
                f.Show();
            }
            if(dataGridView1.SelectedRows.Count > 1)
            {
                MessageBox.Show("Chỉ chọn 1 đối tượng!");
            }
            if (dataGridView1.SelectedRows.Count == 0)
            {
                MessageBox.Show("Vui lòng chọn 1 đối tượng!");
            }
        }

        public void SetCBBSort()
        {
            cbbSort.Items.Add("MSSV");
            cbbSort.Items.Add("HoTen");
            cbbSort.Items.Add("IDLop");
            cbbSort.Items.Add("NgaySinh");
            cbbSort.Items.Add("DTB");
        }
        private void buttonSort_Click(object sender, EventArgs e)
        {
            //List<string> li = new List<string>();
            //foreach (DataGridViewRow i in dataGridView1.Rows)
            //{
            //    li.Add(i.Cells["MSSV"].Value.ToString());
            //}
            //li.Sort();
            dataGridView1.DataSource = QLSVBLL.Instance.SortBy(cbbSort.SelectedItem.ToString());
        }
    }
}
