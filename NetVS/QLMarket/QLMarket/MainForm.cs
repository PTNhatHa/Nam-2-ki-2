using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLMarket
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            SetDGV();
            SetCBBSort();
        }

        private void SetCBBDGV()
        {
            string query = "SELECT TMH FROM MẶT_HÀNG";
            List<string> MH = new List<string>();
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                MH.Add(i["TMH"].ToString());
            }
            DataGridViewComboBoxColumn cbbcl = (DataGridViewComboBoxColumn)dataGridView1.Columns[5];
            if(cbbcl != null)
            {
                cbbcl.Items.Clear();
            }
            cbbcl.Items.AddRange(MH.Distinct().ToArray());
        }
        private void SetDGV()
        {
            string query = "SELECT MSP, TSP, SX, NN, TMH, TT " +
                            "FROM MẶT_HÀNG, SẢN_PHẨM " +
                            "WHERE MẶT_HÀNG.MMH = SẢN_PHẨM.MMH ";
            dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
            SetCBBDGV();
        }

        private void butDelete_Click(object sender, EventArgs e)
        {
            if(dataGridView1.SelectedRows.Count > 0) 
            {
                DialogResult d = MessageBox.Show("Bạn có muốn xóa sản phẩm?", "Xác nhận Delete", MessageBoxButtons.OKCancel);
                if (d == DialogResult.OK)
                {
                    string query = "";
                    if (dataGridView1.SelectedRows.Count > 0)
                    {
                        List<string> del = new List<string>();
                        SqlParameter[] p = new SqlParameter[1];
                        foreach (DataGridViewRow i in dataGridView1.SelectedRows)
                        {
                            del.Add(i.Cells["MSP"].Value.ToString());
                        }
                        foreach (string i in del)
                        {
                            p[0] = new SqlParameter("@MSP", i);
                            query = "delete from SẢN_PHẨM where SẢN_PHẨM.MSP = @MSP";
                            DBHelper.Instance.ExecuteDB(query, p);
                        }
                        string query1 = "SELECT MSP, TSP, SX, NN, TMH, TT " +
                            "FROM MẶT_HÀNG, SẢN_PHẨM " +
                            "WHERE MẶT_HÀNG.MMH = SẢN_PHẨM.MMH ";
                        dataGridView1.DataSource = DBHelper.Instance.GetRecords(query1);
                    }
                }
            }
        }

        private void butSearch_Click(object sender, EventArgs e)
        {
            string query = "";
            if (txtSearch.Text != "") 
            {
                query = "SELECT MSP, TSP, SX, NN, TMH, TT " +
                            "FROM MẶT_HÀNG, SẢN_PHẨM " +
                            "WHERE MẶT_HÀNG.MMH = SẢN_PHẨM.MMH " +
                            "AND (MẶT_HÀNG.TMH = N'" + txtSearch.Text.ToString() + "' OR SẢN_PHẨM.TSP = N'" + txtSearch.Text.ToString() + "')";
            }
            if(txtSearch.Text == "")
            {
                query = "SELECT MSP, TSP, SX, NN, TMH, TT " + "FROM MẶT_HÀNG, SẢN_PHẨM " + "WHERE MẶT_HÀNG.MMH = SẢN_PHẨM.MMH ";
            }
            dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
        }

        public void SetCBBSort()
        {
            cbbSort.Items.Add("TSP A->Z");
            cbbSort.Items.Add("TSP Z->A");
            cbbSort.Items.Add("TMH A->Z");
            cbbSort.Items.Add("TMH Z->A");
        }
        private void butSort_Click(object sender, EventArgs e)
        {
            string query = "";
            string txt = cbbSort.SelectedItem.ToString();
            if (cbbSort.SelectedItem != null)
            {
                if (txt == "TSP A->Z")
                {
                    query = "SELECT MSP, TSP, SX, NN, TMH, TT " + "FROM MẶT_HÀNG, SẢN_PHẨM " + "WHERE MẶT_HÀNG.MMH = SẢN_PHẨM.MMH " +
                            "ORDER BY TSP ASC";
                }
                if (txt == "TSP Z->A")
                {
                    query = "SELECT MSP, TSP, SX, NN, TMH, TT " + "FROM MẶT_HÀNG, SẢN_PHẨM " + "WHERE MẶT_HÀNG.MMH = SẢN_PHẨM.MMH " +
                            "ORDER BY TSP DESC";
                }
                if (txt == "TMH A->Z")
                {
                    query = "SELECT MSP, TSP, SX, NN, TMH, TT " + "FROM MẶT_HÀNG, SẢN_PHẨM " + "WHERE MẶT_HÀNG.MMH = SẢN_PHẨM.MMH " +
                            "ORDER BY TMH ASC";
                }
                if (txt == "TMH Z->A")
                {
                    query = "SELECT MSP, TSP, SX, NN, TMH, TT " + "FROM MẶT_HÀNG, SẢN_PHẨM " + "WHERE MẶT_HÀNG.MMH = SẢN_PHẨM.MMH " +
                            "ORDER BY TMH DESC";
                }
                dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
            }
        }

        private void butAdd_Click(object sender, EventArgs e)
        {
            DetailForm f = new DetailForm(null);
            f.Show();
            string query = "SELECT MSP, TSP, SX, NN, TMH, TT " + "FROM MẶT_HÀNG, SẢN_PHẨM " + "WHERE MẶT_HÀNG.MMH = SẢN_PHẨM.MMH ";
            dataGridView1.DataSource = DBHelper.Instance.GetRecords(query);
        }

        private void butUpdate_Click(object sender, EventArgs e)
        {
            if (dataGridView1.SelectedRows.Count == 1)
            {
                DataGridViewRow dt = dataGridView1.SelectedRows[0];
                string msp = dt.Cells["MSP"].Value.ToString();
                DetailForm f = new DetailForm(msp);
                f.Show();
                
            }
            else
                if (dataGridView1.SelectedRows.Count == 0)
                {
                    MessageBox.Show("Vui lòng chọn 1 đối tượng muốn Update");
                }
                else
                    {
                        MessageBox.Show("Vui lòng chỉ chọn 1 đối tượng muốn Update");
                    }
        }

        //private void dataGridView1_DataError(object sender, DataGridViewDataErrorEventArgs e)
        //{
        //    e.Cancel= true;
        //}
    }
}
