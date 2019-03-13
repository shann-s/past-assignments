namespace Assignment9.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class a9Migration : DbMigration
    {
        public override void Up()
        {
            AddColumn("dbo.Tracks", "ClipName", c => c.String());
            AddColumn("dbo.Tracks", "Clip", c => c.Binary());
        }
        
        public override void Down()
        {
            DropColumn("dbo.Tracks", "Clip");
            DropColumn("dbo.Tracks", "ClipName");
        }
    }
}
