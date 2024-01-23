using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Text;

namespace Test_UI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e) 
        {
            PrivateFontCollection pfc = new PrivateFontCollection();
            pfc.AddFontFile(@"D:\LEARNING\HK4\NetVS\Test_UI\Test_UI\Resources\Itim-Regular.ttf");
            foreach (Control c in this.Controls) 
            {
                c.Font = new Font(pfc.Families[0], 20, FontStyle.Regular);            
            }
        }

    }
}
