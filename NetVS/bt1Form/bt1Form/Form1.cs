using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace bt1Form
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void thoat_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        private double TT()
        {
            double s = 0;
            if (caovoi.Checked)
                s += 100;
            if (taytrang.Checked)
                s += 1200;
            if (chuphinhrang.Checked)
                s += 200;
            if(slrang.SelectedIndex > 0)
            {
                int sr = Convert.ToInt32(slrang.SelectedItem.ToString());
                s += sr * 80;
            }
            return s;
            
        }
        private void tinhtien_Click(object sender, EventArgs e)
        {
            if(textName.Text == "")
            {
                MessageBox.Show("Nhap ten vo");
            }
            else
            {
                txttong.Text = TT().ToString();
            }
        }
    }
}
