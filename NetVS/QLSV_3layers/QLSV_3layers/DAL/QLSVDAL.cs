using QLSV_3layers.BLL;
using QLSV_3layers.DTO;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLSV_3layers.DAL
{
    internal class QLSVDAL
    {
        private static QLSVDAL instance;
        public static QLSVDAL Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new QLSVDAL();
                }
                return instance;
            }
            private set { }
        }
        public  LSH GetLSHByDataRow(DataRow i)
        {
            return new LSH
            {
                IDLop = Convert.ToInt32(i["IDLop"].ToString()),
                NameLop = i["NameLop"].ToString()
            };
        }
        public List<LSH> GetAllLSH()
        {
            List<LSH> result = new List<LSH>();
            string query = "SELECT * FROM LSH";
            foreach(DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                result.Add(GetLSHByDataRow(i));
            }
            return result;
        }

        public SV GetSVByDataRow(DataRow i)
        {
            return new SV
            {
                MSSV = Convert.ToInt32(i["MSSV"].ToString()),
                HoTen = i["HoTen"].ToString(),
                IDLop = Convert.ToInt32(i["IDLop"].ToString()),
                NgaySinh = Convert.ToDateTime(i["NgaySinh"].ToString()),
                DTB = Convert.ToDouble(i["DTB"].ToString()),
                GioiTinh = Convert.ToBoolean(i["GioiTinh"].ToString()),
                Anh = Convert.ToBoolean(i["Anh"].ToString()),
                HB = Convert.ToBoolean(i["HB"].ToString()),
                CCCD = Convert.ToBoolean(i["CCCD"].ToString())
            };
        }
        public List<SV> GetAllSV()
        {
            List<SV> result = new List<SV>();
            string query = "SELECT * FROM SV";
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                result.Add(GetSVByDataRow(i));
            }
            return result;
        }
        public void DelSVDAL(string mssv)
        {
            SqlParameter[] p = new SqlParameter[1];
            p[0] = new SqlParameter("@MSSV", mssv);
            string query = "DELETE FROM SV WHERE MSSV = @MSSV";
            DBHelper.Instance.ExecuteDB(query, p);
        }
        public void Add(SV s)
        {
            SqlParameter[] p = new SqlParameter[9];
            p[0] = new SqlParameter("@MSSV", s.MSSV);
            p[1] = new SqlParameter("@HOTEN", s.HoTen);
            p[2] = new SqlParameter("@LSH", s.IDLop);
            p[3] = new SqlParameter("@NS", s.NgaySinh);
            p[4] = new SqlParameter("@DTB", s.DTB);
            p[5] = new SqlParameter("@GT", s.GioiTinh);
            p[6] = new SqlParameter("@ANH", s.Anh);
            p[7] = new SqlParameter("@HB", s.HB);
            p[8] = new SqlParameter("@CCCD", s.CCCD);

            string query = "INSERT INTO SV (MSSV, HoTen, IDLop, NgaySinh, DTB, GioiTinh, Anh, HB, CCCD) " +
                "VALUES (@MSSV, @HOTEN, @LSH, @NS, @DTB, @GT, @ANH, @HB, @CCCD)";

            DBHelper.Instance.ExecuteDB(query, p);
        }
        public void Edit(SV s)
        {
            SqlParameter[] p = new SqlParameter[9];
            p[0] = new SqlParameter("@MSSV", s.MSSV);
            p[1] = new SqlParameter("@HOTEN", s.HoTen);
            p[2] = new SqlParameter("@LSH", s.IDLop);
            p[3] = new SqlParameter("@NS", s.NgaySinh);
            p[4] = new SqlParameter("@DTB", s.DTB);
            p[5] = new SqlParameter("@GT", s.GioiTinh);
            p[6] = new SqlParameter("@ANH", s.Anh);
            p[7] = new SqlParameter("@HB", s.HB);
            p[8] = new SqlParameter("@CCCD", s.CCCD);

            string query = "UPDATE SV SET HoTen = @HOTEN, IDLop = @LSH, NgaySinh = @NS, DTB = @DTB, " +
                            "GioiTinh = @GT, Anh = @ANH, HB = @HB, CCCD = @CCCD where MSSV = @MSSV ";

            DBHelper.Instance.ExecuteDB(query, p);
        }

        public List<SV> SortDAL(string txt)
        {
            List<SV> result = new List<SV>();
            string query = "SELECT * FROM SV ORDER BY " + txt + " ASC";
            foreach (DataRow i in DBHelper.Instance.GetRecords(query).Rows)
            {
                result.Add(GetSVByDataRow(i));
            }
            return result;         
        }
    }
}
