using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace OOPNET
{
    public class SVmain
    {
        static void Main()
        {
            // SV s1 = new SV();
            // SV s2 = new SV("2", "SV2", 2.2);
            // SV s3 = new SV(s1);
            // s3.SetName(s2.GetName());
            // s3.DTB = s2.DTB;
            // s1.Show();
            // s2.Show();
            // s3.Show();

            SV s1 = new SV //dùng hàm dựng mặc định để khởi tạo và dùng property để khởi gán giá trị
            {
                MSSV = "1", Name = "SV1", DTB = 3.3
            };
            s1.Show();
            Console.WriteLine(s1.ToString());
            SVCNTT s2 = new SVCNTT
            {
                MSSV = "2", Name = "SV2", DTB = 4.4,
                LT = true
            };
            s2.Show();
            Console.WriteLine(s2.ToString());
        }
    }
}