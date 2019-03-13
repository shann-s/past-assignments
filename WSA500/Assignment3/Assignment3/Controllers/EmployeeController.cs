using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment3.Controllers
{
    public class EmployeeController : ApiController
    {
        private Manager m = new Manager();
        // GET: api/Employee
        public IHttpActionResult GetAllEmployee()
        {
            var c = m.EmployeeGetAll();
            return Ok(c);
        }

        // GET: api/Employee/5
        public IHttpActionResult Get(int? id)
        {
            var o = m.EmployeeGetOne(id.GetValueOrDefault());
            if (o == null)
            {
                return NotFound();
            }
            else
            {
                return Ok(o);
            }
        }

        // POST: api/Employee
        public void Post([FromBody]string value)
        {
        }

        // PUT: api/Employee/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE: api/Employee/5
        public void Delete(int id)
        {
        }
    }
}
