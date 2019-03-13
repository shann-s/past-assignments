using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment1.Controllers
{
    public class PhonesController : Controller
    {
        // Collection of Phones
        private List<Phonebase> Phones;

        
        public PhonesController()
        {
            Phones = new List<Phonebase>();

            var iPhone = new Phonebase();
            iPhone.Id = 1;
            iPhone.PhoneName = "iPhone 8";
            iPhone.Manufacturer = "Apple";
            iPhone.DateReleased = new DateTime(2017, 9, 1);
            iPhone.MSRP = 849;
            iPhone.ScreenSize = 5.5;
            Phones.Add(iPhone);

            var Galaxy = new Phonebase
            {
                Id = 2,
                PhoneName = "Galaxy note 8",
                Manufacturer = "Samsung",
                DateReleased = new DateTime(2017, 8, 1),
                MSRP = 749,
                ScreenSize = 5.7
            };
            Phones.Add(Galaxy);

            Phones.Add(new Phonebase
            {
                Id = 3,
                PhoneName = "Surface Phone",
                Manufacturer = "Microsoft",
                DateReleased = new DateTime(2017, 3, 1),
                MSRP = 800,
                ScreenSize = 5.5
            });


        }
        // GET: Phones
        public ActionResult Index()
        {
            return View(Phones);
        }

        // GET: Phones/Details/5
        public ActionResult Details(int id)
        {
            return View(Phones[id - 1]);
        }

        // GET: Phones/Create
        public ActionResult Create()
        {
            return View(new Phonebase());
        }

        // POST: Phones/Create
        [HttpPost]
        public ActionResult Create(FormCollection collection)
        {
            try
            {
                var newItem = new Phonebase();

                //Configure unique identifier
                newItem.Id = Phones.Count + 1;

                //Configure the string properties
                newItem.PhoneName = collection["PhoneName"];
                newItem.Manufacturer = collection["Manufacturer"];

                //Configure the date; it comes into the method of string
                newItem.DateReleased = Convert.ToDateTime(collection["DateReleased"]);

                //Configure the numbers; they come into the method  as strings
                int msrp;
                double ss;
                bool isNumber;

                //MSRP first...
                isNumber = Int32.TryParse(collection["MSRP"], out msrp);
                newItem.MSRP = msrp;

                //Next, the ScreenSize...
                isNumber = double.TryParse(collection["ScreenSize"], out ss);
                newItem.ScreenSize = ss;
                //Add to the collection
                Phones.Add(newItem);

                //Show the results, using the existing Details view
                return View("Details", newItem);
                // TODO: Add insert logic here
                //return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Phones/Edit/5
      /*  public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Phones/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add update logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Phones/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Phones/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }*/
    }
}
