using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Test
{
    public class MyClass : Ifile1
    {
        public void A1() //implement
        {
            Console.WriteLine("I1-A1");
        }
        public void B1()
        {
            Console.WriteLine("I1-B1");
        }
        public void M()
        {
            Console.WriteLine("MyClass");
        }
    }
}