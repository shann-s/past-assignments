using Assignment9.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment9.Controllers
{
    public class Trackbase
    {
        public int Id { get; set; }

        [Required, StringLength(100)]
        public string Name { get; set; }
        public string Composers { get; set; }
        public string ClipName { get; set; }
        public byte[] Clip { get; set; }
        public IEnumerable<Album> Albums { get; set; }
    }

    public class TrackAddForm
    {
        [Required, StringLength(100)]
        public string Name { get; set; }
        public string Composers { get; set; }
        public SelectList genre { get; set; }
        public int Id { get; set; }

        [Required]
        [Display(Name = "Sample Clip")]
        [DataType(DataType.Upload)]
        public string ClipUpload { get; set; }

        public SelectList GenreList { get; set; }
    }

    public class TrackAdd
    {
        [Required, StringLength(100)]
        public string Name { get; set; }
        public string Composers { get; set; }
        public SelectList genre { get; set; }
        public int Id { get; set; }
        public HttpPostedFileBase ClipUpload { get; set; }
    }

    public class TrackEdit
    {
        public int Id { get; set; }
        public HttpPostedFileBase ClipUpload { get; set; }
    }

    public class TrackEditForm
    {
        public int Id { get; set; }
        [Required]
        [Display(Name = "Clip")]
        [DataType(DataType.Upload)]
        public string ClipUpload { get; set; }
    }
}