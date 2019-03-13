using Assignment_8.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_8.Controllers
{
    public class Albumbase
    {
        public string Coordinator { get; set; }
        public string Genre { get; set; }
        public int Id { get; set; }
        [Required, StringLength(100)]
        public string Name { get; set; }
        public DateTime ReleaseDate { get; set; }
        public string UrlAlbum { get; set; }

        public ICollection<Track> Tracks { get; set; }
        public ICollection<Artist> Artists { get; set; }
    }

    public class AlbumAddForm
    {
        public string Genre { get; set; }
        [Required, StringLength(100)]
        public string Name { get; set; }
        public DateTime ReleaseDate { get; set; }
        public string UrlAlbum { get; set; }

        public ICollection<Track> Tracks { get; set; }
        public ICollection<Artist> Artists { get; set; }

        public SelectList select { get; set; }
    }
}