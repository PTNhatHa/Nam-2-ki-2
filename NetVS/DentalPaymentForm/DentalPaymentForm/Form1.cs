using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DentalPaymentForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            comboBox1.SelectedIndex= 0;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close(); //khi đóng form tự động giải phóng
           // this.Dispose(); //khi đóng tự mình giải phóng
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "") 
            {
                MessageBox.Show("Vui lòng nhập tên");
            }
            else
            {
                textBox2.Text = Total().ToString();
            }    
            
        }
        private double Total()
        {
            double s = 0;
            if (checkBox1.Checked)
                s += 100;
            if (checkBox2.Checked)
                s += 1200;
            if (checkBox3.Checked)
                s+= 200;

            //c1: string select = comboBox1.SelectedItem.ToString();
            //c2: int index = comboBox1.SelectedIndex;
            //    string select = comboBox1.Items[index].ToString();
            //int r = Convert.ToInt32(select); //số răng trám
            s += Convert.ToInt32(comboBox1.SelectedItem.ToString())*80;

            return s;
        }
    }
}
