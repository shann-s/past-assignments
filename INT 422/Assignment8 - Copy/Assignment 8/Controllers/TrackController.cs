using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_8.Controllers
{
    public class TrackController : Controller
    {
        private Manager m = new Manager();
        // GET: Track
        public ActionResult Index()
        {
            var c = m.TrackGetAll();
            return View(c);
        }

        // GET: Track/Details/5
        public ActionResult Details(int? id)
        {
            var o = m.TrackGetById(id.GetValueOrDefault());
            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(o);
            }
        }

        // GET: Track/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Track/Create
        [HttpPost]
        public ActionResult Create(FormCollection collection)
        {
            try
            {
                // TODO: Add insert logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Track/Edit/5
        public ActionResult Edit(int? id)
        {
            var o = m.TrackGetById(id.GetValueOrDefault());

            if(o == null)
            {
                return HttpNotFound();
            }
            else
            {
                var editform = AutoMapper.Mapper.Map<Trackbase, TrackEditForm>(o);

                return View(editform);
            }
        }

        // POST: Track/Edit/5
        [HttpPost]
        public ActionResult Edit(int? id, TrackEdit newItem)
        {
            // Validate the input
            if (!ModelState.IsValid)
            {
                // Our "version 1" approach is to display the "edit form" again
                return RedirectToAction("edit", new { id = newItem.Id });
            }

            if (id.GetValueOrDefault() != newItem.Id)
            {
                // This appears to be data tampering, so redirect the user away
                return RedirectToAction("index");
            }

            // Attempt to do the update
            var editedItem = m.TrackEdit(newItem);

            if (editedItem == null)
            {
                // There was a problem updating the object
                // Our "version 1" approach is to display the "edit form" again
                return RedirectToAction("edit", new { id = newItem.Id });
            }
            else
            {
                // Show the details view, which will have the updated data
                return RedirectToAction("details", new { id = newItem.Id });
            }
        }

        // GET: Track/Delete/5
        public ActionResult Delete(int? id)
        {
            var itemToDelete = m.TrackGetById(id.GetValueOrDefault());

            if (itemToDelete == null)
            {
                // Don't leak info about the delete attempt
                // Simply redirect
                return RedirectToAction("index");
            }
            else
            {
                return View(itemToDelete);
            }
        }

        // POST: Track/Delete/5
        [HttpPost]
        public ActionResult Delete(int? id, FormCollection collection)
        {
            var result = m.TrackDelete(id.GetValueOrDefault());
            return RedirectToAction("index");
        }
    }
}
