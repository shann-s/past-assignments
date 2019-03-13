using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment_2.Controllers
{
    public class ArtistController : ApiController
    {
        private Manager m = new Manager();
        // GET: api/Artist
        public IHttpActionResult GetAllArtist()
        {
            var c = m.ArtistGetAll();
            return Ok(c);
        }

        // GET: api/Artist/5
        public IHttpActionResult Get(int? id)
        {
            var o = m.ArtistGetOne(id.GetValueOrDefault());
            if (o == null)
            {
                return NotFound();
            }
            else
            {
                return Ok(o);
            }
        }

        // POST: api/Artist
        public IHttpActionResult Post([FromBody]ArtistAdd newItem)
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
            var addedItem = m.ArtistAdd(newItem);

            if (addedItem == null)
            {

                return BadRequest("addedItem is null");

            }
            var uri = Url.Link("DefaultApi", new { id = addedItem.ArtistId });
            return Created(uri, addedItem);
        }

        // PUT: api/Artist/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE: api/Artist/5
        public void Delete(int id)
        {
        }
    }
}
