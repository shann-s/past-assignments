using Assignment_8.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_8.Controllers
{
    public class Trackbase
    {
        public string Clerk { get; set; }
        public string Composers { get; set; }
        public string Genre { get; set; }
        public int Id { get; set; }
        [Required, StringLength(100)]
        public string Name { get; set; }

        public ICollection<Album> Albums { get; set; }
    }

    public class TrackAddForm
    {
        public string Composers { get; set; }
        [Required, StringLength(100)]
        public string Name { get; set; }

        public SelectList genre { get; set; }
    }

    public class TrackEdit
    {
        public string Clerk { get; set; }
        public string Composers { get; set; }
        public string Genre { get; set; }
        public int Id { get; set; }
        [Required, StringLength(100)]
        public string Name { get; set; }

        public ICollection<Album> Albums { get; set; }
    }

    public class TrackEditForm
    {
        [Required, StringLength(100)]
        public string Name { get; set; }
        public string Composers { get; set; }
        public string Genre { get; set; }
        public ICollection<Album> Albums { get; set; }
    }
}