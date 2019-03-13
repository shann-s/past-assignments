using Assignment_8.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_8.Controllers
{
    public class Artistbase
    {
        [Required, StringLength(100)]
        public string BirthName { get; set; }
        public DateTime BirthOrStartDate { get; set; }
        public string Executive { get; set; }
        public string Genre { get; set; }
        public int Id { get; set; }
        [Required, StringLength(100)]
        public string Name { get; set; }
        public string UrlArtist { get; set; }

        public ICollection<Album> Albums { get; set; }
    }

    public class ArtistAddForm
    {
        [Required, StringLength(100)]
        public string Name { get; set; }
        [Required, StringLength(100)]
        public string BirthName { get; set; }
        public DateTime BirthOrStartDate { get; set; }
        public SelectList GenreList { get; set; }
        public string UrlArtist { get; set; }
    }

    public class ArtistAdd
    {
        public string Genre { get; set; }
    }
}