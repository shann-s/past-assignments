using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_4.Models;
namespace Assignment_4.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            // If necessary, add constructor code here
        }

        public IEnumerable<Invoicebase> Invoicegetall()
        {
            return Mapper.Map<IEnumerable<Invoice>, IEnumerable<Invoicebase>>(ds.Invoices);
        }

        public Invoicebase InvoiceGetById(int Invoiceid)
        {
            var o = ds.Invoices.Find(Invoiceid);
            return (o == null) ? null : Mapper.Map<Invoice, Invoicebase>(o);
        }

        public InvoiceWithDetail InvoiceGetByIdWithDetail(int id)
        {
            var o = ds.Invoices.Include("Customer.Employee").Include("InvoiceLines").SingleOrDefault(c => c.InvoiceId == id);
            return (o == null) ? null : Mapper.Map<Invoice, InvoiceWithDetail>(o);
        }


        // Add methods below
        // Controllers will call these methods
        // Ensure that the methods accept and deliver ONLY view model objects and collections
        // The collection return type is almost always IEnumerable<T>

        // Suggested naming convention: Entity + task/action
        // For example:
        // ProductGetAll()
        // ProductGetById()
        // ProductAdd()
        // ProductEdit()
        // ProductDelete()
    }
}