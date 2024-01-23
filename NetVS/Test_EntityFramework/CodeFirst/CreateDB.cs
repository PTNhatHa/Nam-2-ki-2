using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeFirst
{
    internal class CreateDB :
        CreateDatabaseIfNotExists<QLSV> //nếu CSDL chưa tồn tại thì khởi tạo CSDL mới
        //DropCreateDatabaseIfModelChanges<QLSV> //nếu chỉ đổi record thì ko update, nếu đổi cấu trúc CSDL thì mới update
        //DropCreateDatabaseAlways<QLSV> //mỗi lần chạy sẽ xóa CSDL cũ và add CSDL mới vào
    {
        protected override void Seed(QLSV context) //thêm record cho table
        {
            context.LSHes.AddRange(new LSH[]
            {
                new LSH {ID_Lop = 1, NameLop = "21DT1"},
                new LSH {ID_Lop = 2, NameLop = "21DT2"},
            });
            context.SVs.AddRange(new SV[]
            {
                new SV {MSSV = "101", Name = "NVA", DTB = 1.1, ID_Lop = 1},
                new SV {MSSV = "102", Name = "NVB", DTB = 2.2, ID_Lop = 2},
            });
        }
    }
}
