using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UI_PBL3
{
    public partial class Form1 : Form
    {
        private Form activeform;
        public Form1()
        {
            InitializeComponent();
        }

        private void OpenChildForm(Form child)
        {
            if(activeform != null) 
            {
                activeform.Close();
            }
            activeform = child;
            child.TopLevel = false;
            child.FormBorderStyle = FormBorderStyle.None;
            child.Dock = DockStyle.Fill;
            this.panelMain.Controls.Add(child);
            this.panelMain.Tag = child;
            child.BringToFront();
            child.Show();
        }
        private void buttonPI_Click(object sender, EventArgs e)
        {
            buttonPI.BackColor = Color.FromArgb(43, 52, 103);
            buttonMark.BackColor = Color.FromArgb(235, 69, 95);
            buttonSchedule.BackColor = Color.FromArgb(235, 69, 95);

            OpenChildForm(new Forms.Teacher_PI());
        }

        private void buttonMark_Click(object sender, EventArgs e)
        {
            buttonMark.BackColor = Color.FromArgb(43, 52, 103);
            buttonPI.BackColor = Color.FromArgb(235, 69, 95);
            buttonSchedule.BackColor = Color.FromArgb(235, 69, 95);

            OpenChildForm(new Forms.Teacher_Mark());
        }

        private void buttonSchedule_Click(object sender, EventArgs e)
        {
            buttonSchedule.BackColor = Color.FromArgb(43, 52, 103);
            buttonPI.BackColor = Color.FromArgb(235, 69, 95);
            buttonMark.BackColor = Color.FromArgb(235, 69, 95);

            OpenChildForm(new Forms.Teacher_Schedule());
        }
    }
}
