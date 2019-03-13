using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment9.Controllers
{
    public class ArtistController : Controller
    {
        private Manager m = new Manager();
        // GET: Artist
        public ActionResult Index()
        {
            var c = m.ArtistGetAll();
            return View(c);
        }

        // GET: Artist/Details/5
        public ActionResult Details(int? id)
        {
            var o = m.ArtistGetOneWithMediaInfo(id.GetValueOrDefault());
            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(o);
            }
        }

        [Route("artist/{id}/addalbum"), ValidateInput(false)]
        public ActionResult AddAlbum(int? id)
        {
            var a = m.ArtistGetById(id.GetValueOrDefault());

            if (a == null)
            {
                return HttpNotFound();
            }
            else
            {
                var o = new AlbumAddForm();
                a.Name = o.Name;
                o.GenreList = new SelectList(m.GenreGetAll(), "Id", "Name");

                return View(o);
            }
        }

        [HttpPost]
        public ActionResult AddAlbum(AlbumAddForm newItem)
        {
            // Validate the input
            if (!ModelState.IsValid)
            {
                return View(newItem);
            }

            // Process the input
            var addedItem = m.AlbumAdd(newItem);

            if (addedItem == null)
            {
                return View(newItem);
            }
            else
            {
                return RedirectToAction("details", new { id = addedItem.Id });
            }
        }

        [Route("artist/{id}/addmediaitem")]
        public ActionResult AddMediaItem(int? id)
        {
            var a = m.ArtistGetById(id.GetValueOrDefault());

            if (a == null)
            {
                return HttpNotFound();
            }
            else
            {
                var o = new MediaItemAddForm();

                return View(o);
            }
        }

        [HttpPost]
        public ActionResult AddMediaItem(MediaItemAdd newItem)
        {
            // Validate the input
            if (!ModelState.IsValid)
            {
                return View(newItem);
            }

            // Process the input
            var addedItem = m.MediaAdd(newItem);

            if (addedItem == null)
            {
                return View(newItem);
            }
            else
            {
                return RedirectToAction("details", new { id = addedItem.Id });
            }
        }

        // GET: Artist/Create
        [ValidateInput(false)]
        public ActionResult Create()
        {
            var form = new ArtistAddForm();
            form.GenreList = new SelectList(m.GenreGetAll(), "Id", "Name");
            return View(form);
        }   

        // POST: Artist/Create
        [HttpPost]
        public ActionResult Create(ArtistAddForm newItem)
        {
            // Validate the input
            if (!ModelState.IsValid)
            {
                return View(newItem);
            }

            // Process the input
            var addedItem = m.ArtistAdd(newItem);

            if (addedItem == null)
            {
                return View(newItem);
            }
            else
            {
                return RedirectToAction("details", new { id = addedItem.Id });
            }
        }

        // GET: Artist/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Artist/Edit/5
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

        // GET: Artist/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Artist/Delete/5
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
