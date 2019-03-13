using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment3.Controllers
{
    public class EmployeeBase
    {
        public EmployeeBase()
        {
            BirthDate = DateTime.Now;
            HireDate = DateTime.Now;
        }

        public int EmployeeId { get; set; }
        public string LastName { get; set; }
        public string FirstName { get; set; }
        public string Title { get; set; }


        public DateTime? BirthDate { get; set; }

        public DateTime? HireDate { get; set; }
        public string Address { get; set; }
        public string City { get; set; }
        public string State { get; set; }
        public string Country { get; set; }
        public string PostalCode { get; set; }
        public string Phone { get; set; }
        public string Fax { get; set; }
        public string Email { get; set; }
    }

    public class EmployeeWithRelatedObjects : EmployeeBase
    {
        public EmployeeWithRelatedObjects()
        {
            DirectReports = new List<EmployeeBase>();
        }
        public int? SupervisorId { get; set; }
        public virtual IEnumerable<EmployeeBase> DirectReports { get; set; }

        public EmployeeBase Supervisor { get; set; }
    }

    public class EmployeeAdd : EmployeeBase
    {
        public string Supervisor { get; set; }
    }

    public class EmployeeWithMediaInfo : EmployeeBase
    {
        public string MediaContentType { get; set; }
    }

    public class EmployeeWithMedia : EmployeeWithMediaInfo
    {
        public byte[] MediaContent { get; set; }
    }
}