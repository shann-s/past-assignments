using Assignment_2.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment_2.Controllers
{
    public class AlbumAdd
    {

        public string Title { get; set; }

        public int ArtistId { get; set; }

    }

    public class AlbumBase : AlbumAdd
    {
        public AlbumBase()
        {
            Tracks = new HashSet<Track>();
        }
        public int AlbumId { get; set; }
        public virtual Artist Artist { get; set; }

        public virtual ICollection<Track> Tracks { get; set; }
    }

    public class AlbumEdit
    {
        public int AlbumId { get; set; }

        public string Title { get; set; }

    }

   
}