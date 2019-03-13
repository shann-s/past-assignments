using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment1.Models
{
    public class DesignModelClasses
    {
    }
    public class Smartphone
    {
        public Smartphone()
        {
            ReleaseDate = DateTime.Now;
        }

        public int Id { get; set; }
        public String Manufacturer { get; set; }
        public String ModelName { get; set; }
        public DateTime ReleaseDate { get; set; }
        public double ScreenSize { get; set; }
        public int SellPrice { get; set; }

    }
}