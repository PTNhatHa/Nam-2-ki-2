using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Test
{
    // public class KClass : Ifile1, Ifile2
    // {
    //     public void A1()
    //     {
    //         Console.WriteLine("I1-A1");
    //     }
    //     public void A2()
    //     {
    //         Console.WriteLine("I2-A2");
    //     }
    //     public void B1()
    //     {
    //         Console.WriteLine("I1-B1");
    //     }
    //     public void B2()
    //     {
    //         Console.WriteLine("I2-B2");
    //     }
    public class KClass : Ifile1, Ifile3
    {
        public void A1()
        {
            System.Console.WriteLine("I1-I3-A1");
        }

        public void B1()
        {
            System.Console.WriteLine("I1-B1");
        }

        public void B3()
        {
            System.Console.WriteLine("I3-B3");
        }
    }
}
