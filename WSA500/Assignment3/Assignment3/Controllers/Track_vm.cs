using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment3.Controllers
{
    public class TrackBase
    {
        public TrackBase()
        {
            InvoiceLines = new List<InvoiceLineWithTrack>();
        }
        public int InvoiceLineId { get; set; }
        public int TrackId { get; set; }
        public string Name { get; set; }

        public int? AlbumId { get; set; }

        public int MediaTypeId { get; set; }

        public int? GenreId { get; set; }
        public string Composer { get; set; }

        public int Milliseconds { get; set; }

        public int? Bytes { get; set; }
        public decimal UnitPrice { get; set; }

        public virtual AlbumBase Album { get; set; }
        public IEnumerable<InvoiceLineWithTrack> InvoiceLines { get; set; }

        public MediaTypeBase MediaType { get; set; }
    }
}