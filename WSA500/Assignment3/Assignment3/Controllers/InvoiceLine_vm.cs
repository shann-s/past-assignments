using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment3.Controllers
{
    public class InvoiceLineBase
    {
        public InvoiceLineBase(){
        }

        public int InvoiceLineId { get; set; }

        public int InvoiceId { get; set; }
        public decimal UnitPrice { get; set; }

        public int Quantity { get; set; }
    }

    public class InvoiceLineWithTrack : InvoiceLineBase
    {
        public int TrackId { get; set; }
        public TrackBase Track { get; set; }
    }
}