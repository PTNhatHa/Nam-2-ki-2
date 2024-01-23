using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QLSV_cuaThay
{
    internal class CSDL
    {
        private static CSDL _Instance;
        private DataTable dt;
        public DataTable DB
        {
            get { return dt; }
            private set { }
        }
        public static CSDL Instance
        {
            get
            {
                if (_Instance == null)
                    _Instance = new CSDL();
                return _Instance;
            }
            private set { }
        }
        private CSDL ()
        {
            dt = new DataTable();
            dt.Columns.AddRange(new DataColumn[]
            {
                new DataColumn {ColumnName = "MSSV", DataType= typeof(string)},
                new DataColumn {ColumnName = "Name", DataType= typeof(string)},
                new DataColumn {ColumnName = "LSH", DataType= typeof(string)},
                new DataColumn {ColumnName = "DTB", DataType= typeof(double)},
            });
            dt.Rows.Add("101", "NVA", "21T1", 1.1);
            dt.Rows.Add("102", "NVB", "21T2", 2.1);
            dt.Rows.Add("103", "NVC", "21T1", 3.1);
        }
        public void AddDR(SV s)
        {

        }
        public void DelDR(string MSSV)
        {

        }
        public void UpdateDR(SV s)
        {

        }
    }
}
