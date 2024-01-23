using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Test
{
    public class Classmain
    {
        static void Main()
        {
            // MyClass m = new MyClass();
            // Ifile1 f1 = (Ifile1)m;
            // m.A1(); m.B1(); m.M();
            // f1.A1(); f1.B1();

            // KClass k = new KClass();
            // Ifile1 f11 = (Ifile1)k;
            // Ifile2 f22 = (Ifile2)k;
            // f11.A1(); f11.B1();
            // f22.A2(); f22.B2();

//----------------------------------------------------------------------------------------------------------------------            
            //2 cách implement
            //c1: 2 interface có 2 method cùng tên có thể chỉ implement 1 lần để dùng chung
            KClass k = new KClass();
            Ifile1 f1 = (Ifile1)k;
            Ifile3 f3 = (Ifile3)k;
            f1.A1(); f1.B1();
            f3.A1(); f3.B3();

            //c2: 2 interface có 2 method cùng tên có thể implement 2 lần riêng để có 2 cách dùng riêng
            UClass u = new UClass();
            Ifile1 f11 = (Ifile1)u;
            Ifile3 f33 = (Ifile3)u;
            f11.A1(); f11.B1();
            f33.A1(); f33.B3();
        }
    }
}

