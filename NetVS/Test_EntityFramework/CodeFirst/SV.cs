using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CodeFirst
{
    [Table("SinhVien")] //đặt tên bảng khác tên class, ko có thì mặc định trùng tên class
    public class SV
    {
        [Key]
        [Required] //Not allow null
        [StringLength(100)]
        public string MSSV { get; set; }

        [Column("NameSV")] //tự đặt tên column khác tên thuộc tính
        public string Name { get; set; }
        public double DTB { get; set; }
        public int ID_Lop { get; set; }

        [ForeignKey("ID_Lop")] //thuộc tính quan hệ LSH đc khởi tạo thông qua khóa ngoại ID_Lop
        public virtual LSH LSH { get; set; }

    }
}
