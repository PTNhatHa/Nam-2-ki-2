using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace QLKS
{
    public class PhongKS
    {
        public string MP {get; set;}
        public int SLTD{get; set;}
        public bool tt{get; set;}
        private Date ngaynhan;
        private Date ngaytra;
        public double gia{get; set;}

        public void Show()
        {
            System.Console.WriteLine("MP = {0}, SLTD = {1}, ",MP,SLTD);
            if (tt==true) System.Console.WriteLine("tinhtrang = trong, ");
            else 
            {
                ngaynhan.ToString();
                ngaytra.ToString();
            }
            System.Console.WriteLine("gia = {0}",gia);
        }

        

    }
}