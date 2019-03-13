using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_2.Models;

namespace Assignment_2.Controllers
{
    public class Manager : Employeebase
    {
        // Reference to the data context
        private DataContext ds = new DataContext();
        public Manager()
        {
            // If necessary, add constructor code here
        }

        // Add methods below
        // Controllers will call these methods
        // Ensure that the methods accept and deliver ONLY view model objects and collections
        // The collection return type is almost always IEnumerable<T>

        // Suggested naming convention: Entity + task/action
        // For example:
        // ProductGetAll()
        // ProductGetById()
        // ProductAdd()
        // ProductEdit()
        // ProductDelete()

        public IEnumerable<Employeebase> EmployeeGetAll()
        {
            /*var results = new List<Employeebase>();

            var allemp = ds.Employees;

            foreach (var Employee in allemp)
            {
                var c = new Employeebase();
                c.LastName = Employee.LastName;
                c.FirstName = Employee.FirstName;
                c.Title = Employee.Title;
                c.BirthDate = Employee.BirthDate;
                c.HireDate = Employee.HireDate;
                c.Address = Employee.Address;
                c.City = Employee.City;
                c.State = Employee.State;
                c.Country = Employee.Country;
                c.PostalCode = Employee.PostalCode;
                c.Phone = Employee.Phone;
                c.Fax = Employee.Fax;
                c.Email = Employee.Email;

                results.Add(c);
            }

            return results;*/
            return Mapper.Map<IEnumerable<Employee>, IEnumerable<Employeebase>>(ds.Employees);
        }
        
        public Employeebase EmployeeGetById(int Employeeid)
        {
            var o = ds.Employees.Find(Employeeid);
            return (o == null) ? null : Mapper.Map<Employee, Employeebase>(o);
        }

        public Employeebase EmployeeAdd(EmployeeAdd NewEmployee)
        {
            var added = ds.Employees.Add(Mapper.Map<EmployeeAdd, Models.Employee>(NewEmployee));
            ds.SaveChanges();

            return (added == null) ? null : Mapper.Map<Models.Employee, Employeebase>(added);
        }
    }
}