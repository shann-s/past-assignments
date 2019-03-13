using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment1.Controllers
{
    public class Phonebase
    {
        public Phonebase()
        {

        }

        public int Id { get; set; }
        public string PhoneName { get; set; } = "";
        public string Manufacturer { get; set; } = "";
        public DateTime DateReleased { get; set; } = DateTime.Now;
        public int MSRP { get; set; }
        public double ScreenSize { get; set; }
    }
}