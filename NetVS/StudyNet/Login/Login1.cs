using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Login
{
    public partial class Login1: UserControl
    {
        private string _User;
        private string _Pw;

        public string User
        {
            get { return txtUser.Text; }
            private set { }
        }
        public string Pw
        {
            get { return txtPw.Text; }
            private set { }
        }
        public Login1()
        {
            InitializeComponent();
        }
    }
}
