using Assignment3.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment3.Controllers
{
    public class InvoiceBase
    {
        public InvoiceBase()
        {
            InvoiceDate = DateTime.Now;
        }

        public int InvoiceId { get; set; }

        public DateTime InvoiceDate { get; set; }
        public string BillingAddress { get; set; }
        public string BillingCity { get; set; }
        public string BillingState { get; set; }
        public string BillingCountry { get; set; }
        public string BillingPostalCode { get; set; }
        public decimal Total { get; set; }
    }

    public class InvoiceWithRelatedObjects : InvoiceBase
    {
        public InvoiceWithRelatedObjects()
        {
            InvoiceLines = new List<InvoiceLineWithTrack>();
        }
        public int CustomerId { get; set; }

        public CustomerBase Customer { get; set; }

        public IEnumerable<InvoiceLineWithTrack> InvoiceLines { get; set; }
    }
}