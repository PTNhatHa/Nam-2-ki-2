using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StudyNet
{
    //code chức năng của form1
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            //MessageBox.Show(textBox1.Text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            /*
            //bấm vào button1 -> get chuỗi trong textBox1 -> hiện thị ra messagebox
            //MessageBox.Show(textBox1.Text);
            string txt = textBox1.Text;
            //kiểm tra nếu trùng -> trả về  vị trí item trùng trong listbox
            //nếu ko trùng -> trả về -1
            if (txt != "")
            {
                if (listBox1.Items.IndexOf(txt) < 0)
                {
                    listBox1.Items.Add(txt);
                }
                else
                {
                    MessageBox.Show("Trùng rùi");
                }
            }
            else
            {
                MessageBox.Show("Text rỗng");
            }
            */
            string txt = textBox1.Text;
            if (txt != "")
            {
                if (comboBox1.Items.IndexOf(txt) < 0)
                {
                    comboBox1.Items.Add(txt);
                }
                else
                {
                    MessageBox.Show("Trùng rùi");
                }
            }
            else
            {
                MessageBox.Show("Text rỗng");
            }

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //trả về giá trị nguyên là vị trí item đc lựa chọn
            if (listBox1.SelectedIndex >= 0)
            {
                listBox1.Items.RemoveAt(listBox1.SelectedIndex);
            }    
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //dù có chỉnh sửa trên texBox1 sau khi get thì nó vẫn trả về đc chuỗi của Item[index]
            int index = comboBox1.SelectedIndex;
            textBox1.Text = comboBox1.Items[index].ToString();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            MessageBox.Show(checkBox1.Checked.ToString());
        }
        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            MessageBox.Show(checkBox2.Checked.ToString());

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            MessageBox.Show(radioButton1.Checked.ToString());
        }
               
    }
}
