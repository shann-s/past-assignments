using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment_2.Controllers
{
    public class AlbumController : ApiController
    {
        private Manager m = new Manager();
        // GET: api/Album
        public IHttpActionResult Get()
        {
            var c = m.AlbumGetAll();
            return Ok(c);
        }

        // GET: api/Album/5
        public IHttpActionResult Get(int? id)
        {
            var o = m.AlbumGetOne(id.GetValueOrDefault());
            if (o == null)
            {
                return NotFound();
            }
            else
            {
                return Ok(o);
            }
        }

        // POST: api/Album
        public IHttpActionResult Post([FromBody]AlbumAdd newItem)
        {
            if (Request.GetRouteData().Values["id"] != null) { return BadRequest("Invalid request URI"); }

            if (newItem == null)
            {
                return BadRequest("newItem is null");
            }
            if (!ModelState.IsValid)
            {
                return BadRequest("Model State is invalid");
            }
            // Process the input
            var addedItem = m.AlbumAdd(newItem);

            if (addedItem == null)
            {

                return BadRequest("addedItem is null");

            }
            var uri = Url.Link("DefaultApi", new { id = addedItem.AlbumId });
            return Created(uri, addedItem);
        }

        // PUT: api/Album/5
        public IHttpActionResult Put(int? id, [FromBody]AlbumEdit newItem)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest("Model State is invalid");
            }

            if(id.GetValueOrDefault() != newItem.AlbumId)
            {
                return BadRequest();
            }

            // Process the input
            var editItem = m.AlbumEdit(newItem);

            if (editItem == null)
            {

                return BadRequest("editedItem is null");

            }
            var uri = Url.Link("DefaultApi", new { id = editItem.AlbumId });
            return Created(uri, editItem);
        }

        // DELETE: api/Album/5
        public void Delete(int id)
        {
            m.AlbumDelete(id);
        }
    }
}
