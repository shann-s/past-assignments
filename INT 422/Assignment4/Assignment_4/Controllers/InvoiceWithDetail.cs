using Assignment_4.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment_4.Controllers
{
    public class InvoiceWithDetail : Invoicebase
    {
        public IEnumerable<InvoiceLine> InvoiceLines { get; set; }
        [Required]
        [StringLength(20)]
        public String CustomerFirstName { get; set; }
        [Required]
        [StringLength(20)]
        public String CustomerLastName { get; set; }
        [StringLength(40)]
        public String CustomerCity { get; set; }
        [StringLength(40)]
        public string CustomerState { get; set; }

        [Required]
        [StringLength(20)]
        public String EmployeeCustomerFirstName { get; set; }
        [Required]
        [StringLength(20)]
        public String EmployeeCustomerLastName { get; set; }
}
}