using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DemoNet
{
    internal class SVCNTT : SV
    {
        public bool LT { get; set; }
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
