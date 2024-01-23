using System;
using System.Data.Entity;
using System.Linq;

namespace CodeFirst
{
    public class QLSV : DbContext
    {
        public QLSV()
            : base("name=QLSV")
        {
            Database.SetInitializer<QLSV>(new CreateDB());
        }
        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            //cho phép thay đổi cấu trúc CSDL
            base.OnModelCreating(modelBuilder);
        }
        public virtual DbSet<LSH> LSHes { get; set; }
        public virtual DbSet<SV> SVs { get; set; }

    }

}