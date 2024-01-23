using Login;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Text;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StudyNet
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            LV();
            DGV();
        }
              

        private void button1_Click(object sender, EventArgs e)
        {
            /*
            //truyền dl giữa 2 form
            Form3 f = new Form3();
            f.d += new Form3.MyDel(ShowText);
            f.Show();
            */
            //MessageBox.Show(textBox1.Text);
            /*
            string s = textBox1.Text;
            if (comboBox1.Items.IndexOf(s) >= 0)
            {
                MessageBox.Show("Trùng rùi");
            }
            else
            {
                comboBox1.Items.Add(s);
            }    
            */

            MessageBox.Show(login11.User + ", " + login11.Pw );
        }
        public void ShowText(string s)
        {
            textBox1.Text= s;   
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedItems.Count > 0) 
            {
                string s = "";
                foreach(object i in listBox1.SelectedItems) 
                {
                    s += i.ToString() + "\n";
                }
                MessageBox.Show(s);
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex >= 0)
            {
                string s = comboBox1.SelectedItem.ToString();
                //int index = comboBox1.SelectedIndex;
                //string s = comboBox1.Items[index].ToString();
                //string s = comboBox1.Text;
                MessageBox.Show(s);
            }    
        }

        

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //trả về các row được lựa chọn
            if (listView1.SelectedItems.Count > 0)
            {
                string s = "";
                foreach(ListViewItem i in listView1.SelectedItems)
                {
                    string MSSV = i.Text;
                    string Name = i.SubItems[1].Text;
                    double DTB = Convert.ToDouble(i.SubItems[2].Text);
                    s += MSSV + " " + Name + " " + DTB.ToString() + "\n";
                }
                MessageBox.Show(s);
            }
        }
        private void LV()
        {
            //thêm 3 cột tiêu đề
            listView1.Columns.AddRange(new ColumnHeader[]
            {
                new ColumnHeader { Text = "MSSV"},
                new ColumnHeader { Text = "Name"},
                new ColumnHeader { Text = "DTB"}
            });

            //thêm hàng
            ListViewItem i1 = new ListViewItem { Text = "101" };
            i1.SubItems.AddRange(new ListViewItem.ListViewSubItem[]
            {
                new ListViewItem.ListViewSubItem { Text = "NVA"},
                new ListViewItem.ListViewSubItem { Text = "1.1"}
            });
            ListViewItem i2 = new ListViewItem { Text = "102" };
            i2.SubItems.AddRange(new ListViewItem.ListViewSubItem[]
            {
                new ListViewItem.ListViewSubItem { Text = "NVB"},
                new ListViewItem.ListViewSubItem { Text = "2.2"}
            });
            //ListView1.Item.Add(i1);
            listView1.Items.AddRange(new ListViewItem[] { i1, i2 });
        }

        private void DGV() //DataGridView
        {
            SV[] A = new SV[]
            {
                new SV {MSSV = "101", Name = "NVA", Gender = true, DTB = 1.1},
                new SV {MSSV = "102", Name = "NVB", Gender = false, DTB = 2.2},
                new SV {MSSV = "103", Name = "NVC", Gender = true, DTB = 3.3}
            };

            //DataSource
            List<SV> li = new List<SV>();
            li.AddRange(A);

            //DataTable
            DataTable dt = new DataTable();
            dt.Columns.AddRange(new DataColumn[]
            {
                new DataColumn {ColumnName = "MSSV", DataType = typeof(string)},
                new DataColumn {ColumnName = "Name", DataType = typeof(string)},
                new DataColumn {ColumnName = "Gender", DataType = typeof(bool)},
                new DataColumn {ColumnName = "DTB", DataType = typeof(double)}
            });
            foreach(SV i in A)
            {
                dt.Rows.Add(i.MSSV, i.Name, i.Gender, i.DTB);
            }

            //cách 2 
            //DataRow dr = dt.NewRow();
            //dr[0] = "101";
            //dr[1] = "NVA";
            //dr[2] = false;
            //dr[3] = "1.1";
            //dt.Rows.Add(dr);

            dataGridView1.DataSource = dt;
        }

        private void dataGridView1_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            if(dataGridView1.SelectedRows.Count > 0) 
            {
                string s = "";
                foreach(DataGridViewRow i in dataGridView1.SelectedRows)
                {
                    string MSSV = i.Cells[0].Value.ToString();
                    string Name = i.Cells["Name"].Value.ToString();
                    bool Gender = Convert.ToBoolean(i.Cells[2].Value.ToString());
                    double DTB = Convert.ToDouble(i.Cells["DTB"].Value.ToString());
                    s += MSSV + ", " + Name + ", " + Gender + ", " + DTB + "\n";
                }
                MessageBox.Show(s);
            }
        }
    }
}
