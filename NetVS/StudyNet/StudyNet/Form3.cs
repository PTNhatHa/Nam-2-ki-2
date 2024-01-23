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
    public partial class Form3 : Form
    {
        private Point ps;
        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_MouseDown(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                ps = e.Location;
            }
        }

        private void Form3_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                Graphics g = this.CreateGraphics();
                Pen p = new Pen(Color.Azure, 0.2f); //tạo đối tượng bút vẽ, độ dày 0.2f
                g.DrawLine(p, ps, e.Location); //p -> đối tượng bút vẽ, ps -> điểm bắt đầu, e -> điểm kết thúc
            }
        }

        private void Form3_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                Graphics g = this.CreateGraphics();
                Pen p = new Pen(Color.Aquamarine, 0.2f);
                g.DrawLine(p, ps, e.Location);
            }
        }

        private void Form3_KeyPress(object sender, KeyPressEventArgs e)
        {
            label1.Text = e.KeyChar.ToString();
        }

        private void Form3_KeyDown(object sender, KeyEventArgs e)
        {
            label2.Text = "KeyCode = " + e.KeyCode
                + ", KeyData = " + e.KeyData
                + ", KeyValue = " + e.KeyValue
                + ", Modifier = " + e.Modifiers;
        }

        private void buttonDialog_Click(object sender, EventArgs e)
        {
            OpenFileDialog o = new OpenFileDialog();
            o.Filter = "ABC|*.cs|All|*.*";
            DialogResult r = o.ShowDialog(); //r -> open/cancel
            if(r == DialogResult.OK ) 
            {
                MessageBox.Show(o.FileName.ToString()); //Hiển thị đường dẫn của file đc chọn
            }
        }


        /*
        public delegate void MyDel(string s);
        public MyDel d { get; set; }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
           string s = textBox1.Text;
           d(s); //gọi hàm ShowText(s)
        }
        */


    }
}
