using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QLSV_cuaThay
{
    internal class QLSV
    {
        public List<SV> GetAllSV()
        {
            List<SV> data = new List<SV>();
            foreach (DataRow i in CSDL.Instance.DB.Rows) 
            {
                data.Add(GetSVByDataRow(i));
            }
            return data;
        }
        public SV GetSVByDataRow(DataRow i)
        {
            return new SV
            {
                MSSV = i["MSSV"].ToString(),
                Name = i["name"].ToString(),
                LSH = i["LSH"].ToString(),
                DTB = Convert.ToDouble(i["DTB"].ToString())
            };
        }
        public List<string> GetAllLSH() 
        {
            List<string> data = new List<string>();
            foreach(SV i in GetAllSV()) 
            {
                data.Add(i.LSH);
            }
            return data.Distinct().ToList();
        }
        public List<SV> GetSVDGV(string LSH, string txt)
        {
            List<SV> data = new List<SV>();
            if (LSH == "All")
                data = GetAllSV();
            else 
            {
                foreach(SV i in GetAllSV()) 
                {
                    if (i.LSH == LSH)
                        data.Add(i);
                }
            }
            return data;
        }
        public void DelSV(List<string> del)
        {
            foreach (string i in del)
            {
                CSDL.Instance.DelDR(i);
            }
        }
        public List<SV> GetListSV(List<string> li) 
        {
            List<SV> data = new List<SV>();
            foreach (string i in li)
            {
                foreach (SV j in GetAllSV())
                {
                    if (i == j.MSSV)
                        data.Add(j);
                }
            }
            return data;
        }
        public List<SV> SortBy(List<string> li, string s) 
        {
            List<SV> data = new List<SV>();
            
            //GetListSV(li);
            return data;
        }

    }
}
