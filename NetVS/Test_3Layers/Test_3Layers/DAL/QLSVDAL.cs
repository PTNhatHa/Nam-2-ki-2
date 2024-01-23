using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Test_3Layers.DTO;

namespace Test_3Layers.DAL
{
    internal class QLSVDAL
    {
        public SV GetSVByDataRow(DataRow r)
        {
            return new SV
            {
                MSSV = r["MaSV"].ToString(),
                NameSV = r["TenSV"].ToString(),
                Gender = Convert.ToBoolean(r["Gender"].ToString()),
                DTB = Convert.ToDouble(r["DTB"].ToString()),
                ID_Lop = Convert.ToInt32(r["IDlop"].ToString())
            };
        }
        public List<SV> GetAllSV() 
        {
            List<SV> result = new List<SV>();
            string query = "select * from SV";
            foreach(DataRow i in DBHelper.Instance.GetRecords(query).Rows) 
            {
                result.Add(GetSVByDataRow(i));
            }
            return result;
        }
        public LSH GetLSHByDataRow(DataRow r)
        {
            return new LSH
            {
                ID_Lop = Convert.ToInt32(r["IDlop"].ToString()),
                NameLop = r["TenLop"].ToString()
            };
        }
        public List<LSH> GetAllLSH() 
        {
            List<LSH> result = new List<LSH>();
            string query = "select * from TenLop";
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                result.Add(GetLSHByDataRow(i));
            }
            return result;
        }
        public void AddSVDAL(SV sV) 
        {
            string query = "insert into SV (MaSV, TenSV, Gender, DTB, IDLop) values ('600', 'NVI', 0, 4.4, 1)";
            DBHelper.Instance.ExecuteDB(query);
        }
        public void UpdateSVDAL(SV sV)
        {
            string query = "update ...";
            DBHelper.Instance.ExecuteDB(query);
        }
        public void DelSVDAL(string mssv)
        {
            string query = "delete ...";
            DBHelper.Instance.ExecuteDB(query);
        }
    }
}
