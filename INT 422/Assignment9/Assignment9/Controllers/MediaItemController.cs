﻿using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment9.Controllers
{
    public class MediaItemController : Controller
    {
        private Manager m = new Manager();
        // GET: MediaItem
        public ActionResult Index()
        {
            return View();
        }

        // GET: MediaItem/Details/5
        [Route("MediaItem/{stringId}")]
        public ActionResult Details(string stringId = "")
        {
            // Attempt to get the matching object
            var o = m.MediaItemGetById(stringId);

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                // Return a file content result
                // Set the Content-Type header, and return the photo bytes
                return File(o.Content, o.ContentType);
            }
        }

        [Route("MediaItem/{stringId}/download")]
        public ActionResult DetailsDownload(string stringId = "")
        {
            // Attempt to get the matching object
            var o = m.MediaItemGetById(stringId);

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                // Get file extension, assumes the web server is Microsoft IIS based
                // Must get the extension from the Registry (which is a key-value storage structure for configuration settings, for the Windows operating system and apps that opt to use the Registry)

                // Working variables
                string extension;
                RegistryKey key;
                object value;

                // Open the Registry, attempt to locate the key
                key = Registry.ClassesRoot.OpenSubKey(@"MIME\Database\Content Type\" + o.ContentType, false);
                // Attempt to read the value of the key
                value = (key == null) ? null : key.GetValue("Extension", null);
                // Build/create the file extension string
                extension = (value == null) ? string.Empty : value.ToString();

                // Create a new Content-Disposition header
                var cd = new System.Net.Mime.ContentDisposition
                {
                    // Assemble the file name + extension
                    FileName = $"img-{stringId}{extension}",
                    // Force the media item to be saved (not viewed)
                    Inline = false
                };
                // Add the header to the response
                Response.AppendHeader("Content-Disposition", cd.ToString());

                return File(o.Content, o.ContentType);
            }
        }

        // GET: MediaItem/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: MediaItem/Create
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

        // GET: MediaItem/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: MediaItem/Edit/5
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

        // GET: MediaItem/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: MediaItem/Delete/5
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
