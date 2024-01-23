using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLSV_cuaThay
{
    public partial class DetailForm : Form
    {
        public delegate void MyDel(string LSH, string txt);
        public MyDel d { get; set; }
        private string MSSV;
        public DetailForm(string m)
        {
            MSSV = m;
            InitializeComponent();
        }
        private void SetGUI()
        {
            if(MSSV != null) 
            {
                QLSV db = new QLSV();
                //db.GetSVByMSSV(MSSV) -> doi tuong SV can Update
            }
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            //khởi tạo đối tượng SV từ thông tin GUI
            SV s = new SV();
            QLSV db = new QLSV();
            //db.AddUpdate(s);
            d("All", "");
        }
    }
}
