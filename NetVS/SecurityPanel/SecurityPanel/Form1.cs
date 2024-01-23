using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace SecurityPanel
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int i = 0;
        int sl = 0;
        private void button1_Click(object sender, EventArgs e)
        {
            if (sl < 4)
            {
                textBox1.Text += ((Button)sender).Text;
                sl += 1;
            }
        }

        private void buttonC_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            sl = 0;
        }
               
        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {

        }
        private void buttonT_Click(object sender, EventArgs e)
        {
            string kq;
            switch (textBox1.Text) 
            {
                case "1645":
                case "1689":
                    kq = "Technicians";
                    break;
                case "8345":
                    kq = "Custodians";
                    break;
                case "9998":
                case "1006":
                case "1007":
                case "1008":
                    kq = "Scientist";
                    break;
                default:
                    kq = "Restricted Access";
                    break;
            }
            listAccesslog.Items.Add(DateTime.Now.ToString("dd/MM/yyyy hh:mm:ss ") + kq);

            string path;
            StreamWriter streamWriter;
            path = @"D:\LEARNING\HK4\NetVS\KQbt1.txt";
            if (!File.Exists(path))
            {
                streamWriter = new StreamWriter(path); //tạo mới file                
                streamWriter.WriteLine(listAccesslog.Items[i]);
                i++;
                streamWriter.Close();
            }
            else
            {
                streamWriter = File.AppendText(path); //ghi thêm nội dung
                streamWriter.WriteLine(listAccesslog.Items[i]);
                i++;
                streamWriter.Close();
            }

        }


        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                string kq;
                switch (textBox1.Text)
                {
                    case "1645":
                    case "1689":
                        kq = "Technicians";
                        break;
                    case "8345":
                        kq = "Custodians";
                        break;
                    case "9998":
                    case "1006":
                    case "1007":
                    case "1008":
                        kq = "Scientist";
                        break;
                    default:
                        kq = "Restricted Access";
                        break;
                }
                listAccesslog.Items.Add(DateTime.Now.ToString("dd/MM/yyyy hh:mm:ss ") + kq);
            }
            if (e.KeyCode == Keys.Back)
            {
                textBox1.Text = "";
            }
        }
    }
    
}
