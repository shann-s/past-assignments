using Assignment9.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment9.Controllers
{
    public class Artistbase
    {
        public Artistbase()
        {
            BirthOrStartDate = DateTime.Now;
        }
        public int Id { get; set; }
        [Required, StringLength(100)]
        public string BirthName { get; set; }
        [DataType(DataType.Date)]
        public DateTime BirthOrStartDate { get; set; }
        public string Genre { get; set; }
        [Required, StringLength(100)]
        public string Name { get; set; }
        public string UrlArtist { get; set; }

        public string Portrayal { get; set; }
        public IEnumerable<Album> Albums { get; set; }
    }

    public class ArtistAddForm
    {
        public ArtistAddForm()
        {
            BirthOrStartDate = DateTime.Now;
        }

        [Required, StringLength(100)]
        public string Name { get; set; }
        [Required, StringLength(100)]
        public string BirthName { get; set; }
        public DateTime BirthOrStartDate { get; set; }
        public string UrlArtist { get; set; }
        public SelectList GenreList { get; set; }

        [DataType(DataType.MultilineText)]
        public string Portrayal { get; set; }
    }

    public class ArtistAdd
    {
        public string Genre { get; set; }
    }

    public class ArtistWithMediaInfo : Artistbase
    {
        public ArtistWithMediaInfo()
        {
            MediaItems = new List<MediaItembase>();
        }

        public IEnumerable<MediaItembase> MediaItems { get; set; }
    }
}