using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_4.Controllers
{
    public class InvoiceController : Controller
    {
        private Manager m = new Manager();
        // GET: Invoice
        public ActionResult Index()
        {
            var c = m.Invoicegetall();
            return View(c);
        }

        // GET: Invoice/Details/5
        public ActionResult Details(int? id)
        {
            var o = m.InvoiceGetByIdWithDetail(id.GetValueOrDefault());
            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(o);
            }
        }
    }
}
