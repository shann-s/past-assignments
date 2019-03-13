using Assignment_5.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
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

        [Column(TypeName = "numeric")]
        public decimal UnitPrice { get; set; }
    }

    public class TrackWithDetail : Trackbase
    {
        public TrackWithDetail()
        {
            MediaType = new List<MediaTypebase>();
        }

        public ICollection<MediaTypebase> MediaType { get; set; }

        public string AlbumName { get; set; }
    }
}