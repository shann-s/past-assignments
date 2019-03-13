using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_2.Controllers
{
    public class ManagerController : Controller
    {
        private Manager m = new Manager();
        // GET: Manager
        public ActionResult Index()
        {
            var c = m.EmployeeGetAll();
            return View(c);
        }

        // GET: Manager/Details/5
        public ActionResult Details(int? id)
        {
            var o = m.EmployeeGetById(id.GetValueOrDefault());
            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(o);
            }
        }

        // GET: Manager/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Manager/Create
        [HttpPost]
        public ActionResult Create(EmployeeAdd newItem)
        {
            try
            {
                // TODO: Add insert logic here
                if (!ModelState.IsValid)
                {
                    return View(newItem);
                }
                var addedItem = m.EmployeeAdd(newItem);

                if (addedItem == null)
                {
                    return View(newItem);
                }
                else
                {
                    return RedirectToAction("details", new { id = addedItem.EmployeeId });
                }
                //return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Manager/Edit/5
       /* public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Manager/Edit/5
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

        // GET: Manager/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Manager/Delete/5
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
