using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Namespace
{
    public class Program
    {
        static void HV(ref int a, ref int b) //biến tham chiếu
        {
            int temp = a;
            a=b;
            b=temp;
        }
        static void A(out int c)
        {
            c=10;
        }

        static void m1c()
        {
            int n;
            Console.Write("So pt m1c n = ");
            n = Convert.ToInt32(Console.ReadLine());
            string[] a = new string[n];
            for (int i=0; i<n; i++)
            {
                Console.Write("a[{0}] = ", i);
                a[i]=Console.ReadLine();
            }

            Console.WriteLine("Mang vua nhap la: ");
            for (int i=0; i<n; i++)
            {
                Console.WriteLine("a[{0}] = {1}", i, a[i]);
            }

            Console.WriteLine("Mang vua nhap la (foreach): ");
            foreach (string i in a) //i là phần tử của mảng a //gặp NULL sẽ out
            {
                Console.Write(" {0} ", i);
            }
        }

        static void m2c()
        {
            string[,] arr = new string[3,2]
            {
                {"A","B"},
                {"1","2"},
                {"c","d"}
            };

            Console.WriteLine("Mang 2 chieu: ");
            for (int h=0; h<3; h++)
            {
                for (int c=0; c<2; c++)
                {
                    Console.Write(" {0} ", arr[h,c]);
                }
                Console.WriteLine();
            }

            foreach (string i in arr)
            {
                Console.Write(" {0} ", i);
            }
        }

        static void JuggedArray()
        {
            string[][] JA =
            {
                new string[] {"abc","123"},
                new string[] {"hello"},
                new string[] {"aaaaa","ahahahah","hihihihih"}
            };

            Console.WriteLine("Jugged Array: ");
            for (int i=0; i < JA.GetLength(0); i++)
            {
                for (int j=0; j < JA[i].GetLength(0); j++)
                     Console.Write(" {0} ", JA[i][j]);
                Console.WriteLine();
            }

            foreach (string[] a in JA)
                foreach (string arr in a)
                    Console.Write(" {0} ", arr);
        }

        static int tong(params int[] a) //params có thể tính các giá trị riêng lẻ
        {
            int s=0;
            for (int i = 0; i < a.Length; i++)
            {
                s+=a[i];
            }
            return s;
        }
        //Console.WriteLine(tong(a));
        //Console.WriteLine(tong(3,4,5)); //tự chuyển thành mảng và tính tổng nhờ params

        static void Main()
        {
            // int x, y, z; //chưa nhận giá trị ban đầu, đang nhận giá trị ngẫu nhiên
            // Console.Write("x= ");
            // x = Convert.ToInt32(Console.ReadLine());
            // //x = int.Parse(Console.ReadLine());
            // Console.Write("y= ");
            // y = Convert.ToInt32(Console.ReadLine());
            // HV(ref x, ref y); //x,y đã đc khởi tạo giá trị
            // A(out z); //z chưa đc khởi tạo giá trị, z đang nhận gt ngẫu nhiên từ hệ thống
            // Console.WriteLine("x = {0}, y = {1}, z = {2}", x, y, z);

            //m1c();
            //m2c();
            //JuggedArray();

            int[] a = new int[3];
            for (int i=0; i<a.Length; i++)
            {
                Console.Write("a[{0}] = ", i);
                a[i]=Convert.ToInt32(Console.ReadLine());
            }
            Console.WriteLine(tong(a));
            Console.WriteLine(tong(3,4,5)); //tự chuyển thành mảng và tính tổng nhờ params
            string[] b = new string[3];
            for (int i=0; i<b.Length; i++)
            {
                Console.Write("b[{0}] = ", i);
                b[i]=Console.ReadLine();
            }
            for (int i = 0; i < b.Length; i++)
            {
                Console.WriteLine("{0} ",b[i]);
            }
            Console.WriteLine();
            foreach (string i in b)
            {
                Console.WriteLine("{0} ",i);
            }
            Console.ReadKey();
        }
    }
}

//sd foreach nhanh hơn for nhưng ko thể dùng để nhập gtri