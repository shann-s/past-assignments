using Assignment_2.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment_2.Controllers
{
    public class ArtistAdd
    {
        public string Name { get; set; }
    }

    public class ArtistBase : ArtistAdd
    {
        public ArtistBase()
        {
            Albums = new List<AlbumBase>();
        }
        public int ArtistId { get; set; }
        public IEnumerable<AlbumBase> Albums { get; set; }
    }
}