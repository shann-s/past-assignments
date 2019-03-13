using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using System.Web.Mvc;

namespace Assignment1.Controllers
{
    public class ValuesController : ApiController
    {
        private Manager m = new Manager();
        // GET api/values
        public ActionResult Get()
        {
            var c = m.SmartphoneGetAll();
            HttpResponseMessage response = Request.CreateResponse(HttpStatusCode.OK, c);
            return new HttpStatusCodeResult(HttpStatusCode.OK);
        }

        // GET api/values/5
        public ActionResult GetOne(int id)
        {
            var o = m.SmartphoneGetOne(id);
            if (o == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.NotFound);
            }
            else
            {
                return new HttpStatusCodeResult(HttpStatusCode.OK);
            }
        }

        // POST api/values
        public ActionResult Post(SmartphoneAdd newItem)
        {
            if(newItem.Equals(null))
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            if (!ModelState.IsValid)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }

            return new HttpStatusCodeResult(HttpStatusCode.OK);

            /*// Process the input
            var addedItem = m.SmartphoneAdd(newItem);

            if (addedItem == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            else
            {
                return RedirectToAction("details", new { id = addedItem.Id });
            }*/
        }

        // PUT api/values/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE api/values/5
        public void Delete(int id)
        {
        }
    }
}
