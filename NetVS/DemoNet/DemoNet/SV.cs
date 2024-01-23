using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DemoNet
{
    internal class SV
    {
/*
        private string _MSSV;
        private string _Name;
        private double _DTB;
        public double DTB //property
        {
            get
            {
                return this._DTB;
            }
            set
            {
                this._DTB = value; //biến ảo value do C# cung cấp
            }
        }
        public SV()
        {
            _MSSV = "1"; _Name = "SV1"; _DTB = 1.1;
        }
        public SV(string m, string n, double d)
        {
            _MSSV = m; _Name = n; _DTB = d;
        }
        public SV(SV s)
        {
            _MSSV = s._MSSV;
            _Name = s._Name;
            this._DTB = s._DTB;
        }
        public void SetName(string newname)
        {
            this._Name = newname;
        }
        public string GetName()
        {
            return this._Name;
        }
 */
        public string MSSV { get; set; }
        public string Name { get; set; }
        public double DTB { get; set; }
        public virtual void Show() //từ khóa virtual nhằm thông báo cho trình biên dịch hàm này sẽ đc override lại ở lớp con
        {
            Console.WriteLine("MSSV = {0}, Name = {1}, DTB ={2}", MSSV, Name, DTB);
        }
        public override string ToString() //mọi lớp sẽ đc kế thừa từ lớp Object
        {
            return "MSSV = " + MSSV + ", Name = " + Name + ", DTB = " + DTB;
        }
        public static bool CompareDTB(object o1, object o2)
        {
            return ((SV)o1).DTB > ((SV)o2).DTB;
        }
        public static bool CompareName(object o1, object o2)
        {
            if (string.Compare(((SV)o1).Name, ((SV)o2).Name) > 0)
                return true;
            else
                return false;
        }
    }
}
