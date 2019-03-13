using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_3.Models;

namespace Assignment_3.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            // If necessary, add constructor code here
        }

        public IEnumerable<Employee_base> EmployeeGetAll()
        {
            return Mapper.Map<IEnumerable<Employee>, IEnumerable<Employee_base>>(ds.Employees);
        }

        public Employee_base EmployeeGetById(int Employeeid)
        {
            var o = ds.Employees.Find(Employeeid);
            return (o == null) ? null : Mapper.Map<Employee, Employee_base>(o);
        }

        public Employee_base EmployeeEdit(EmployeeEdit newItem)
        {
            var o = ds.Employees.Find(newItem.EmployeeId);

            if(o == null)
            {
                return null;
            } else
            {
                ds.Entry(o).CurrentValues.SetValues(newItem);
                ds.SaveChanges();

                return Mapper.Map<Employee, Employee_base>(o);
            }
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

        public IEnumerable<Track_Base> TrackGetAll()
        {
            return Mapper.Map<IEnumerable<Track>, IEnumerable<Track_Base>>(ds.Tracks);
        }

        public IEnumerable<Track_Base> TrackGetAllPop()
        {
            var c = ds.Tracks
                .Where(p => p.GenreId == 9)
                .OrderBy(p => p.Name);
            return Mapper.Map<IEnumerable<Track>, IEnumerable<Track_Base>>(c);
        }

        public IEnumerable<Track_Base> TrackGetAllDeepPurple()
        {
            var c = ds.Tracks
                .Where(p => p.Composer.Contains("Jon Lord"))
                .OrderBy(p => p.TrackId);
            return Mapper.Map<IEnumerable<Track>, IEnumerable<Track_Base>>(c);
        }

        public IEnumerable<Track_Base> TrackGetAllTop100Longest()
        {
            var c = ds.Tracks
                .Take(100)
                .OrderByDescending(p => p.Milliseconds);
            return Mapper.Map<IEnumerable<Track>, IEnumerable<Track_Base>>(c);
        }



    }
}