using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DemoNet
{
    public class Program
    {
        /*
                public delegate void MyDel(int a, int b);
                static void Sum(int a, int b)
                {
                    Console.WriteLine(a + b);
                }
                static void Sub(int a, int b)
                {
                    Console.WriteLine(a - b);
                }
                static void TT(int a, int b, MyDel d)
                {
                    d(a, b);
                }
//
        public delegate bool Compare(object o1, object o2);
        static void Sort(object[] A, Compare cmp)
        {
            for (int i = 0; i < A.Length - 1; i++) 
            {
                for (int j = i + 1; j < A.Length; j++)
                {
                    //if (SV.CompareName(A[i], A[j])

                    if (cmp(A[i], A[j]))
                    {
                        object temp = A[i];
                        A[i] = A[j];
                        A[j] = temp;    
                    }
                }
            }
        }
*/
        static void Main(string[] args)
        {
/*
            
                        MyDel d1 = new MyDel(Sum); ; //int x;
                        d1 += new MyDel(Sub);
                        d1 += new MyDel(Sub);
                        d1 -= new MyDel(Sub);
                        d1(2, 1);
            
            SV[] A = new SV[]
            {
                new SV {MSSV = "1", Name = "NVA", DTB = 2.2},
                new SV {MSSV = "2", Name = "NVB", DTB = 1.1},
                new SV {MSSV = "3", Name = "NVC", DTB = 3.3}
            };
            Sort(A, SV.CompareDTB);
            foreach(SV i in A)
            {
                Console.WriteLine(i.ToString());
            }
            Console.ReadKey();
*/
        
            Clock c = new Clock();
            AnalogClock ac = new AnalogClock();
            DigitalClock dc = new DigitalClock();

            c.OnSecondChange += new Clock.SecondHandler(ac.ShowAC);
            c.OnSecondChange += new Clock.SecondHandler(dc.ShowDC);

            c.Run();

        }
    }
}
