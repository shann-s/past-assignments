using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment1.Controllers
{
    public class SmartphonesController : ApiController
    {
        private Manager m = new Manager();

        public IHttpActionResult GetAllSmartphone()
        {
            var c = m.SmartphoneGetAll();
            return Ok(c);
        }
        public IHttpActionResult GetOne(int? id)
        {
            var o = m.SmartphoneGetOne(id.GetValueOrDefault());
            //Will always be null because there are no values set (yet). Otherwise function works.
            if (o == null)
            {
                return NotFound();
            }
            else
            {
                return Ok(o);
            }
        }


        public IHttpActionResult Post([FromBody]SmartphoneAdd newItem)
        {
            if (newItem == null)
            {
                return BadRequest("newItem is null");
            }
            if (!ModelState.IsValid)
            {
                return BadRequest("Model State is invalid");
            }
            // Process the input
            var addedItem = m.SmartphoneAdd(newItem);

            if (addedItem == null) {

                return BadRequest("addedItem is null");

            }
            var uri = Url.Link("DefaultApi", new { id = addedItem.Id });
            return Created(uri, addedItem);
        }

        // PUT: api/Smartphones/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE: api/Smartphones/5
        public void Delete(int id)
        {
        }
    }
}
