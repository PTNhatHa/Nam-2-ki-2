using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Test_3Layers.DAL;
using Test_3Layers.DTO;
using Test_3Layers.View;

namespace Test_3Layers.BLL
{
    internal class QLSVBLL
    {
        public List<CBBItem> GetCBB()
        {
            List<CBBItem> r = new List<CBBItem>();
            r.Add(new CBBItem
            {
                Value= 0, 
                Text = "All"
            });
            QLSVDAL dal = new QLSVDAL();
            foreach(LSH i in dal.GetAllLSH()) 
            {
                r.Add(new CBBItem
                {
                    Value = i.ID_Lop,
                    Text = i.NameLop
                });
            }
            return r;
        }
        public List<SV> GetSVByIDLop(int ID_Lop)
        {
            List<SV> r = new List<SV>();
            QLSVDAL dal = new QLSVDAL();
            if(ID_Lop == 0 ) 
            {
                r = dal.GetAllSV();
            }
            else
            {
                foreach(SV i in dal.GetAllSV()) 
                {
                    if(ID_Lop == i.ID_Lop)
                    {
                        r.Add(i);
                    }
                }
            }
            return r;
        }
        public void AddSVBLL(SV s)
        {
            QLSVDAL dal = new QLSVDAL();
            dal.AddSVDAL(s);
        }
        public void UpdateSVBLL(SV s)
        {
            QLSVDAL dal = new QLSVDAL();
            bool check = false;
            foreach (SV i in dal.GetAllSV()) 
            {
                if(i.MSSV == s.MSSV)
                {
                    check = true;
                }
            }
            if (check)
            {
                dal.UpdateSVDAL(s);
            }
        }
        public void DelSVBLL(string MSSV)
        {
            QLSVDAL dal = new QLSVDAL();
            dal.DelSVDAL(MSSV);
        }
        public List<SV> GetListSV(List<string> li)
        {
            List<SV> r = new List<SV>();
            QLSVDAL dal = new QLSVDAL();
            foreach(string i in li)
            {
                foreach(SV j in dal.GetAllSV()) 
                {
                    if(i == j.MSSV)
                    {
                        r.Add(j);
                    }
                }
            }
            return r;
        }
        public List<SV> SortBy(List<string> li, string txt)
        {
            List<SV> l = new List<SV>();
            //GetListSV(li) -> List SV cần sắp xếp
            //sắp xếp list trên -> trả về list mới đã sx
            return l;
        }
        public List<SVView> GetSVView()
        {
            QLSVDAL dal = new QLSVDAL();
            List<SVView> li = new List<SVView>();
            foreach(SV i in dal.GetAllSV())
            {
                string NameL = "";
                foreach(LSH j in dal.GetAllLSH())
                {
                    if(j.ID_Lop== i.ID_Lop)
                    {
                        NameL = j.NameLop;
                        break;
                    }
                }
                li.Add(new SVView
                {
                    MSSV = i.MSSV,
                    NameSV = i.NameSV,
                    NameLop = NameL
                });
            }
            return li;
        }
    }
}
