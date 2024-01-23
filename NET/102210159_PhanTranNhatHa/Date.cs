using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace QLKS
{
    public class Date
    {
        public int d {get; set;}
        public int m {get; set;}
        public int y {get; set;}

        public void ToString()
        {
            System.Console.WriteLine(" {0} / {1} / {2} ",d,m,y); 
        }

    }
}