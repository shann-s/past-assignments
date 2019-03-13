namespace Assignment3.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class employeemediaadded : DbMigration
    {
        public override void Up()
        {
            AddColumn("dbo.Employee", "MediaContentType", c => c.String(maxLength: 127));
        }
        
        public override void Down()
        {
            AddColumn("dbo.Employee", "MediaContentType", c => c.String());
        }
    }
}
