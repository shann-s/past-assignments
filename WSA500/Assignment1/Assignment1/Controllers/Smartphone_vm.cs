using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment1.Controllers
{
    public class SmartphoneBase
    {
        public int Id { get; set; }
    }

    public class SmartphoneAdd : SmartphoneBase
    {
        public SmartphoneAdd()
        {
            ReleaseDate = DateTime.Now;
        }
        public String Manufacturer { get; set; }
        public String ModelName { get; set; }
        public DateTime ReleaseDate { get; set; }
        public double ScreenSize { get; set; }
        public int SellPrice { get; set; }
    }
}