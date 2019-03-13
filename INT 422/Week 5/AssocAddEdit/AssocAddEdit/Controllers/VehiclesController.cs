﻿using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace AssocAddEdit.Controllers
{
    public class VehiclesController : Controller
    {
        // Reference to the data manager
        private Manager m = new Manager();

        // GET: Vehicles
        public ActionResult Index()
        {
            return View(m.VehicleGetAllWithDetail());
        }

        // GET: Vehicles/Details/5
        public ActionResult Details(int? id)
        {
            // Attempt to get the matching object
            var o = m.VehicleGetByIdWithDetail(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                // Pass the object to the view
                return View(o);
            }
        }

        // GET: Vehicles/Create
        public ActionResult Create()
        {
            // Create a form
            var form = new VehicleAddForm();
            // Configure the SelectList for the item-selection element on the HTML Form
            form.ManufacturerList = new SelectList(m.ManufacturerGetAll(), "Id", "Name");
            
            return View(form);
        }

        // POST: Vehicles/Create
        [HttpPost]
        public ActionResult Create(VehicleAdd newItem)
        {
            // Validate the input
            if (!ModelState.IsValid)
            {
                return View(newItem);
            }

            // Process the input
            var addedItem = m.VehicleAdd(newItem);

            if (addedItem == null)
            {
                return View(newItem);
            }
            else
            {
                return RedirectToAction("details", new { id = addedItem.Id });
            }
        }

        // GET: Vehicles/Edit/5
        public ActionResult Edit(int? id)
        {
            // Attempt to fetch the matching object
            var o = m.VehicleGetByIdWithDetail(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                // Create and configure an "edit form"

                // Notice that o is a CustomerBase object
                // We must map it to a CustomerEditContactInfoForm object
                // Notice that we can use AutoMapper anywhere, 
                // and not just in the Manager class!
                var form = Mapper.Map<VehicleWithDetail, VehicleEditForm>(o);

                return View(form);
            }
        }

        // POST: Vehicles/Edit/5
        [HttpPost]
        public ActionResult Edit(int? id, VehicleEdit newItem)
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
            var editedItem = m.VehicleEditMSRP(newItem);

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

        // GET: Vehicles/Delete/5
        public ActionResult Delete(int? id)
        {
            var itemToDelete = m.VehicleGetByIdWithDetail(id.GetValueOrDefault());

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

        // POST: Vehicles/Delete/5
        [HttpPost]
        public ActionResult Delete(int? id, FormCollection collection)
        {
            var result = m.VehicleDelete(id.GetValueOrDefault());

            // "result" will be true or false
            // We probably won't do much with the result, because 
            // we don't want to leak info about the delete attempt

            // In the end, we should just redirect to the list view
            return RedirectToAction("index");
        }
    }
}
