using Assignment_5.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment_5.Controllers
{
    public class Albumbase
    {
        public int AlbumId { get; set; }

        [Required]
        [StringLength(160)]
        public string Title { get; set; }

        public int ArtistId { get; set; }

        public virtual Artist Artist { get; set; }
    }


}