using QLSV_3layers.DAL;
using QLSV_3layers.DTO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLSV_3layers.BLL
{
    internal class QLSVBLL
    {
        private static QLSVBLL instance;
        public static QLSVBLL Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new QLSVBLL();
                }
                return instance;
            }
            private set { }
        }
        public List<CBBItem> SetCBBLSH()
        {
            List<CBBItem> data = new List<CBBItem>();
            foreach(LSH i in QLSVDAL.Instance.GetAllLSH())
            {
                data.Add(new CBBItem { Value = i.IDLop, Text = i.NameLop});
            }
            return data;
        }
        public List<SV> GetListSV(int IDLop, string NameSV)
        {
            List<SV> data = new List<SV>();
            if(IDLop == 0 && NameSV == null)
            {
                data.AddRange(QLSVDAL.Instance.GetAllSV().ToArray());
            }
            if(IDLop == 0 && NameSV != null)
            {
                foreach (SV i in QLSVDAL.Instance.GetAllSV())
                {
                    if (i.HoTen == NameSV)
                    {
                        data.Add(i);
                    }
                }
            }
            if (IDLop != 0 && NameSV != null)
            {
                foreach(SV i in QLSVDAL.Instance.GetAllSV()) 
                {
                    if(i.IDLop == IDLop && i.HoTen == NameSV) 
                    {
                        data.Add(i);
                    }
                }
            }
            if (IDLop != 0 && NameSV == null)
            {
                foreach (SV i in QLSVDAL.Instance.GetAllSV())
                {
                    if (i.IDLop == IDLop)
                    {
                        data.Add(i);
                    }
                }
            }
            return data;
        }
        public void DelSVBLL(string mssv)
        {
            QLSVDAL.Instance.DelSVDAL(mssv);
        }
        public SV GetSVByMSSV(string mssv)
        {
            SV data = null;
            foreach (SV i in QLSVDAL.Instance.GetAllSV())
            {
                if (i.MSSV.ToString() == mssv)
                {
                    data = i;
                    break;
                }
            }
            return data;
        }
        public List<SV> GetListSV(List<string> li)
        {
            List<SV> data = new List<SV>();
            foreach(string i in li)
            {
                foreach(SV j in QLSVDAL.Instance.GetAllSV()) 
                {
                    if(j.MSSV.ToString() == i)
                    {
                        data.Add(j);
                    }
                }
            }
            return data;
        }
        public string GetNameLop(int IDLop)
        {
            string l = "";
            foreach(LSH i in QLSVDAL.Instance.GetAllLSH())
            {
                if(i.IDLop == IDLop) 
                {
                    l = i.NameLop;
                }
            }
            return l;
        }
        public int GetIDLop(string NameLop)
        {
            int l = 0;
            foreach (LSH i in QLSVDAL.Instance.GetAllLSH())
            {
                if (i.NameLop == NameLop)
                {
                    l = i.IDLop;
                }
            }
            return l;
        }
        public void ExecuteDB(SV s)
        {
            bool check = true;
            foreach (SV i in QLSVDAL.Instance.GetAllSV())
            {
                if (i.MSSV == s.MSSV)
                {
                    check = false;
                }
            }
            if (check) 
            {
                QLSVDAL.Instance.Add(s);
                MessageBox.Show("Add thành công!");
            }
            else
            {
                QLSVDAL.Instance.Edit(s);
                MessageBox.Show("Edit thành công!");
            }
        }
        //public List<SV> SortBy(List<string> li, string txt)
        //{
        //    List<SV> l = new List<SV>();
        //    GetListSV(li).Sort()
        //}
        public List<SV> SortBy(string txt)
        {
            return QLSVDAL.Instance.SortDAL(txt);
        }
    }
}
