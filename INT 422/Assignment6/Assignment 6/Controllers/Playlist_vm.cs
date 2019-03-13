using Assignment_6.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Diagnostics;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_6.Controllers
{
    public class Playlistbase
    {
        [StringLength(120)]
        public string Name { get; set; }
    }
    public class PlaylistEditTracks
    {

        public int Id { get; set; }

        public IEnumerable<int> TrackIds { get; set; }
    }

    public class PlaylistEditTracksForm
    {

        public int TrackId { get; set; }
        public String Name { get; set; }

        [Display(Name = "AllTracks")]
        public MultiSelectList TrackList { get; set; }
    }

    public class PlaylistWithDetail : Playlistbase
    {
        public PlaylistWithDetail() {
            Tracks = new List<Trackbase>();
        }
        [Key]
        public int PlaylistId { get; set; }
        public int TracksCount { get; set; }
        public IEnumerable<Trackbase> Tracks { get; set; }

    }
}