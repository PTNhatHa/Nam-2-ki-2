namespace CodeFirst.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class InitialCreate : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.LopSH",
                c => new
                    {
                        ID_Lop = c.Int(nullable: false, identity: true),
                        NameLop = c.String(),
                    })
                .PrimaryKey(t => t.ID_Lop);
            
            CreateTable(
                "dbo.SinhVien",
                c => new
                    {
                        MSSV = c.String(nullable: false, maxLength: 100),
                        NameSV = c.String(),
                        DTB = c.Double(nullable: false),
                        ID_Lop = c.Int(nullable: false),
                    })
                .PrimaryKey(t => t.MSSV)
                .ForeignKey("dbo.LopSH", t => t.ID_Lop, cascadeDelete: true)
                .Index(t => t.ID_Lop);
            
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.SinhVien", "ID_Lop", "dbo.LopSH");
            DropIndex("dbo.SinhVien", new[] { "ID_Lop" });
            DropTable("dbo.SinhVien");
            DropTable("dbo.LopSH");
        }
    }
}
