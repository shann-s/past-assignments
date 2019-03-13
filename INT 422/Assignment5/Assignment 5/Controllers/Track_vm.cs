using Assignment_5.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_5.Controllers
{
    public class Trackbase
    {
        public int TrackId { get; set; }

        [Required]
        [StringLength(200)]
        public string Name { get; set; }

        [StringLength(220)]
        public string Composer { get; set; }

        public int Milliseconds { get; set; }
        public decimal UnitPrice { get; set; }

  
    }

    public class TrackWithDetail : Trackbase
    {
        public string AlbumArtistName { get; set; }
        public string AlbumTitle { get; set; }
        public Mediatypebase MediaType { get; set; }
    }

    public class TrackAddForm
    {
        public string Name { get; set; }

        [StringLength(220)]
        public string Composer { get; set; }

        public int Milliseconds { get; set; }
        public decimal UnitPrice { get; set; }
        public SelectList AlbumList { get; set; }
        public SelectList MediaTypeList { get; set; }
    }
}