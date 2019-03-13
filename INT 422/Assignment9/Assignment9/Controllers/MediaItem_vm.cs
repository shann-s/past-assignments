using Assignment9.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment9.Controllers
{
    public class MediaItembase
    {
        public string Caption { get; set; }
        public byte[] Content { get; set; }
        public string ContentType { get; set; }
        public int Id { get; set; }
        public string StringId { get; set; }
        public DateTime Timestamp { get; set; }
        public Artist Artist { get; set; }
    }

    public class MediaItemContent
    {
        public byte[] Content { get; set; }
        public string ContentType { get; set; }
        public string StringId { get; set; }
        public int Id { get; set; }
    }

    public class MediaItemAddForm
    {
        public string Caption { get; set; }

        [Required]
        [Display(Name = "Sample Clip")]
        [DataType(DataType.Upload)]
        public string ClipUpload { get; set; }
        public Artist Artist { get; set; }
    }

    public class MediaItemAdd
    {
        public string ContentType { get; set; }
        public HttpPostedFileBase Content { get; set; }
        public Artist Artist { get; set; }
    }
}