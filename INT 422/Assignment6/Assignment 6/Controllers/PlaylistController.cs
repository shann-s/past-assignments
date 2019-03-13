using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_6.Controllers
{
    public class PlaylistController : Controller
    {
        private Manager m = new Manager();
        // GET: Playlist
        public ActionResult Index()
        {
            var c = m.PlaylistGetAllWithTracks();
            return View(c);
        }

        // GET: Playlist/Details/5
        public ActionResult Details(int id)
        {
            var o = m.PlaylistGetByIdWithDetail(id);

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
        // GET: Playlist/Edit/5
        public ActionResult Edit(int id)
        {
            // Attempt to fetch the matching object
            var o = m.PlaylistGetByIdWithDetail(id);

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                // Create a form, based on the fetched matching object
                var form = Mapper.Map<Playlistbase, PlaylistEditTracksForm>(o);

                // For the multi select list, configure the "selected" items
                // Notice the use of the Select() method, 
                // which allows us to select/return/use only some properties from the source
                var selectedValues = o.Tracks.Select(jd => jd.TrackId);

                // For clarity, use the named parameter feature of C#
                form.TrackList = new MultiSelectList
                    (items: m.TrackGetAll(),
                    dataValueField: "Id",
                    dataTextField: "FullName",
                    selectedValues: selectedValues);

                return View(form);
            }
        }
        
        // POST: Playlist/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, PlaylistEditTracks newItem)
        {
            // Validate the input
            if (!ModelState.IsValid)
            {
                // Our "version 1" approach is to display the "edit form" again
                return RedirectToAction("edit", new { id = newItem.TrackIds });
            }

            if (id != newItem.Id)
            {
                // This appears to be data tampering, so redirect the user away
                return RedirectToAction("index");
            }

            // Attempt to do the update
            var editedItem = m.PlaylistEditTracks(newItem);

            if (editedItem == null)
            {
                // There was a problem updating the object
                // Our "version 1" approach is to display the "edit form" again
                return RedirectToAction("ByTrack", new { id = newItem.TrackIds });
            }
            else
            {
                // Show the details view, which will have the updated data
                return RedirectToAction("ByPlaylistWithTracks", new { id = newItem.TrackIds });
            }
        }
    }
}
