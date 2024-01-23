using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLSV
{
    internal class SV
    {
        
        private DataTable DT { get; set; }
        public SV() 
        {
            CreateDT();
        }
        public void CreateDT()
        {
            DT = new DataTable();
            DT.Columns.AddRange(new DataColumn[]
            {
                new DataColumn {ColumnName = "MSSV", DataType = typeof(string)},
                new DataColumn {ColumnName = "Họ Tên", DataType = typeof(string)},
                new DataColumn {ColumnName = "Lớp SH", DataType = typeof(string)},
                new DataColumn {ColumnName = "Ngày Sinh", DataType = typeof(DateTime)},
                new DataColumn {ColumnName = "DTB", DataType = typeof(double)},
                new DataColumn {ColumnName = "Giới Tính", DataType = typeof(bool)},
                new DataColumn {ColumnName = "Ảnh", DataType = typeof(bool)},
                new DataColumn {ColumnName = "Học Bạ", DataType = typeof(bool)},
                new DataColumn {ColumnName = "CCCD", DataType = typeof(bool)}
            });

            //DT.Rows.Add("102210159", "Phan Trần Nhật Hạ", "21TCLC_DT1", DateTime.Now, "3.4", true, true, false, true);
            DT.Rows.Add(new object[]
            {
                "102210159", "Phan Trần Nhật Hạ", "21TCLC_DT1", DateTime.Now, "3.4", true, true, false, true
            });
            DT.Rows.Add(new object[]
            {
                "102210190", "Nguyễn Hồng Ngân", "21TCLC_DT2", DateTime.Now, "2.2", true, false, false, true
            });
            DT.Rows.Add(new object[]
            {
                "102210210", "Nguyễn Vy Thảo", "21TCLC_DT3", DateTime.Now, "3.3", true, true, true, false
            });
            DT.Rows.Add(new object[]
            {
                "102210160", "Trần Lê Như Quỳnh", "21DT1", DateTime.Now, "3.1", true, false, true, false
            });
            DT.Rows.Add(new object[]
            {
                "102210170", "Nguyễn Đức Huy", "21TCLC_DT1", DateTime.Now, "2.1", false, true, false, true
            });
            DT.Rows.Add(new object[]
            {
                "102210175", "Hồ Sĩ Hoàng", "21DT2", DateTime.Now, "3.1", false, false, false, true
            });

        }

        public List<string> GetLopSH()
        {
            List<string> data = new List<string>();
            foreach (DataRow i in DT.Rows)
            {
                data.Add(i["Lớp SH"].ToString());
            }
            return data;
        }
        public DataTable GetSV_LopSH(string txtLopSH)
        {
            DataTable data = new DataTable();
            data = DT.Clone();
            if (txtLopSH == "All")
            {
                data = DT;
            }
            else
            {
                foreach (DataRow i in DT.Rows)
                {
                    if (i["Lớp SH"].ToString() == txtLopSH)
                    {
                        data.Rows.Add(new object[]
                        {
                            i["MSSV"], i["Họ Tên"], i["Lớp SH"], i["Ngày Sinh"], i["DTB"], i["Giới Tính"], i["Ảnh"], i["Học Bạ"], i["CCCD"]
                        });
                    }
                }
            }
            return data;
        }
        public DataTable GetSV_MSSV(string MSSV)
        {
            DataTable data = new DataTable();
            data = DT.Clone();
            foreach (DataRow i in DT.Rows)
            {
                if (i["MSSV"].ToString() == MSSV)
                {
                    data.Rows.Add(new object[]
                    {
                            i["MSSV"], i["Họ Tên"], i["Lớp SH"], i["Ngày Sinh"], i["DTB"], i["Giới Tính"], i["Ảnh"], i["Học Bạ"], i["CCCD"]
                    });
                }
            }
            return data;
        }
    }
}
