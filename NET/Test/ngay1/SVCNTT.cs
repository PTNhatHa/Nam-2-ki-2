using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace OOPNET
{
    public class SVCNTT : SV
    {
        public bool LT {get; set;}
        public override string ToString()
        {
            return base.ToString() + ", LT = " + LT;
        }
        public override void Show()
        {
            base.Show();
            Console.WriteLine("LT = {0}", LT);
        }
    }
}