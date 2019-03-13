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
        public Albumbase()
        {
            ReleaseDate = DateTime.Now;
        }
        public int Id { get; set; }
        [Required, StringLength(100)]
        public string Name { get; set; }
        public DateTime ReleaseDate { get; set; }
        public string UrlAlbum { get; set; }

        public IEnumerable<Track> Tracks { get; set; }
        public IEnumerable<Artist> Artists { get; set; }
    }

    public class AlbumAddForm
    {
        public AlbumAddForm()
        {
            ReleaseDate = DateTime.Now;
        }
        [Required, StringLength(100)]
        public string Name { get; set; }
        public DateTime ReleaseDate { get; set; }
        public string UrlAlbum { get; set; }

        public IEnumerable<Track> Tracks { get; set; }
        public IEnumerable<Artist> Artists { get; set; }

        public SelectList GenreList { get; set; }
        public MultiSelectList AllTracks { get; set; }
        public MultiSelectList AllArtist { get; set; }
    }
}