using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test_LINQ
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SV s = new SV
            {

            };
            using (DB01DataContext db = new DB01DataContext()) //đối tượng db chỉ tồn tại trong này
            {
                
            }
        }
    }
}
