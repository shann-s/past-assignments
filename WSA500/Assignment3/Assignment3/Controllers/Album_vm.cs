using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment3.Controllers
{
    public class AlbumBase
    {
        public AlbumBase()
        {
        }
        public string Title { get; set; }

        public ArtistBase Artist { get; set; }
    }
}