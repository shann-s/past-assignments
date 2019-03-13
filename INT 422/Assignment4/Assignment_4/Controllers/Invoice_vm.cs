using Assignment_4.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Assignment_4.Controllers
{
    public class Invoicebase
    {
        public Invoicebase() { }
        [Key]
        public int InvoiceId { get; set; }
        [Required]
        public int CustomerId { get; set; }

        public DateTime InvoiceDate { get; set; }

        [StringLength(70)]
        public string BillingAddress { get; set; }

        [StringLength(40)]
        public string BillingCity { get; set; }

        [StringLength(40)]
        public string BillingState { get; set; }

        [StringLength(40)]
        public string BillingCountry { get; set; }

        [StringLength(10)]
        public string BillingPostalCode { get; set; }

        [Column(TypeName = "numeric")]
        public decimal Total { get; set; }


        public virtual Customer Customer { get; set; }
    }

    public class InvoiceWithDetail : Invoicebase
    {
        [StringLength(20)]
        public String CustomerFirstName { get; set; }
        [StringLength(20)]
        public String CustomerLastName { get; set; }
        [StringLength(40)]
        public String CustomerCity { get; set; }
        [StringLength(40)]
        public string CustomerState { get; set; }


        [StringLength(20)]
        public String EmployeeCustomerFirstName { get; set; }
        [StringLength(20)]
        public String EmployeeCustomerLastName { get; set; }
        public virtual InvoiceLinebase InvoiceLinebase { get; set; }
    }

    public class InvoiceLinebase
    {
        public InvoiceLinebase() { }
        public int InvoiceLineId { get; set; }

        public int InvoiceId { get; set; }

        public int TrackId { get; set; }

        [Column(TypeName = "numeric")]
        public decimal UnitPrice { get; set; }

        public int Quantity { get; set; }

        public virtual Invoice Invoice { get; set; }

        public virtual Track Track { get; set; }
    }

    public class InvoiceLineWithDetail : InvoiceLinebase
    {
        InvoiceLineWithDetail() { }
        [StringLength(40)]
        public string Name { get; set; }
    }
}