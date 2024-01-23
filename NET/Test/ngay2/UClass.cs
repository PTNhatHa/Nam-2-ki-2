using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Test
{
    public class UClass : Ifile1, Ifile3
    {
        void Ifile1.A1()
        {
            System.Console.WriteLine("I1-A1");
        }
        void Ifile1.B1()
        {
            System.Console.WriteLine("I1-B1");
        }
        void Ifile3.A1()
        {
            System.Console.WriteLine("I3-A1");
        }
        void Ifile3.B3()
        {
            System.Console.WriteLine("I3-B3");
        }
    }
}