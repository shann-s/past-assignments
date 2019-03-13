﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_2.Models;

namespace Assignment_2.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        // AutoMapper components
        MapperConfiguration config;
        public IMapper mapper;

        public Manager()
        {
            // If necessary, add your own code here

            // Configure AutoMapper...
            config = new MapperConfiguration(cfg =>
            {
                // Define the mappings below, for example...
                // cfg.CreateMap<SourceType, DestinationType>();
                // cfg.CreateMap<Employee, EmployeeBase>();
                cfg.CreateMap<Artist, ArtistBase>();
                cfg.CreateMap<Album, AlbumBase>();
                cfg.CreateMap<ArtistAdd, Artist>();
                cfg.CreateMap<AlbumAdd, Album>();
                cfg.CreateMap<AlbumBase, AlbumEdit>();

            });

            mapper = config.CreateMapper();

            // Data-handling configuration

            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;
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


        // Method templates, used by the ExampleController class

        public IEnumerable<ArtistBase> ArtistGetAll()
        {
            return mapper.Map<IEnumerable<ArtistBase>>(ds.Artists.OrderBy(c => c.ArtistId));
        }
        public IEnumerable<AlbumBase> AlbumGetAll()
        {
            return mapper.Map<IEnumerable<AlbumBase>>(ds.Albums.OrderBy(c => c.AlbumId));
        }

        public ArtistBase ArtistGetOne(int? id)
        {
            var o = ds.Artists.Find(id);
            return (o == null) ? null : mapper.Map<Artist, ArtistBase>(o);
        }

        public AlbumBase AlbumGetOne(int? id)
        {
            var p = ds.Albums.Find(id);
            return (p == null) ? null : mapper.Map<Album, AlbumBase>(p);
        }

        public ArtistBase ArtistAdd(ArtistAdd newItem)
        {
            var added = ds.Artists.Add(mapper.Map<Artist>(newItem));

            ds.SaveChanges();

            return (added == null) ? null : mapper.Map<Artist, ArtistBase>(added);
        }

        public AlbumBase AlbumAdd(AlbumAdd newItem)
        {
            var added = ds.Albums.Add(mapper.Map<AlbumAdd, Album>(newItem));

            ds.SaveChanges();

            return (added == null) ? null : mapper.Map<Album, AlbumBase>(added);
        }
        public AlbumBase AlbumEdit(AlbumEdit newItem)
        {
            var o = ds.Albums.Find(newItem.AlbumId);

            if (o == null)
            {
                return null;
            }
            else
            {
                ds.Entry(o).CurrentValues.SetValues(newItem);
                ds.SaveChanges();
                return mapper.Map<Album, AlbumBase>(o);
            }
        }

        public void AlbumDelete(int id)
        {
            var storedItem = ds.Albums.Find(id);

            if (storedItem == null)
            {
            }
            else
            {
                try
                {
                    ds.Albums.Remove(storedItem);
                    ds.SaveChanges();
                }
                catch (Exception) { }
            }
        }

        public string ExampleEditSomething(string editedItem)
        {
            return $"item was edited with {editedItem}";
        }

        public bool ExampleDelete(int id)
        {
            return true;
        }





        // Programmatically-generated objects

        // Can do this in one method, or in several
        // Call the method(s) from a controller method

        public bool LoadData()
        {
            /*
            // Return immediately if there's existing data
            if (ds.[entity collection].Courses.Count() > 0) { return false; }

            // Otherwise, add objects...

            ds.[entity collection].Add(new [whatever] { Property1 = "value", Property2 = "value" });
            */

            return ds.SaveChanges() > 0 ? true : false;
        }

    }
}