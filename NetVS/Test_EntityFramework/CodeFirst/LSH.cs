using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeFirst
{
    [Table("LopSH")]
    public class LSH
    {
        [Key]
        [Required]
        public int ID_Lop { get; set; }
        public string NameLop { get; set; }
        public virtual ICollection<SV> SVs { get; set; } //1 LSH chứa nhìu SV
        public LSH() 
        {
            //khai báo hàm dựng để trình biên dịch hiểu là luôn phải khởi tạo LSH trước rồi mới tạo SV
            this.SVs = new HashSet<SV>();
        }
    }
}
