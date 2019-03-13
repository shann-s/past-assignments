using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_5.Controllers
{
    public class TrackController : Controller
    {
        private Manager m = new Manager();
        // GET: Track
        public ActionResult Index()
        {
            var c = m.TrackGetAllWithDetail();
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
            // Create a form
            var form = new TrackAddForm();
            // Configure the SelectList for the item-selection element on the HTML Form
            form.AlbumList = new SelectList(m.AlbumGetAll(), "AlbumId", "Title");
            form.MediaTypeList = new SelectList(m.MediatypeGetAll(), "MediaTypeId", "Name");
            return View(form);
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
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Track/Edit/5
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

        // GET: Track/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Track/Delete/5
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
        }
    }
}
