using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_5.Models;

namespace Assignment_5.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            // If necessary, add constructor code here
        }

        public IEnumerable<Albumbase> AlbumGetAll()
        {
            return Mapper.Map<IEnumerable<Album>, IEnumerable<Albumbase>>(ds.Albums.OrderBy(c => c.Title));
        }

        public Albumbase AlbumGetById(int id)
        {
            var o = ds.Albums.Find(id);

            return (o == null) ? null : Mapper.Map<Album, Albumbase>(o);
        }

        public IEnumerable<MediaTypebase> MediaTypeGetAll()
        {
            return Mapper.Map<IEnumerable<MediaType>, IEnumerable<MediaTypebase>>(ds.MediaTypes.OrderBy(c => c.Name));
        }

        public MediaTypebase MediaTypeGetById(int id)
        {
            var o = ds.MediaTypes.Find(id);

            return (o == null) ? null : Mapper.Map<MediaType, MediaTypebase>(o);
        }

        public IEnumerable<Trackbase> TrackGetAll()
        { 
            return Mapper.Map<IEnumerable<Track>, IEnumerable<Trackbase>>(ds.Tracks.OrderBy(d => d.Name));
        }

        public IEnumerable<TrackWithDetail> TrackGetAllWithDetail()
        {
            var c = ds.Tracks.Include("Album");

            return Mapper.Map<IEnumerable<Track>, IEnumerable<TrackWithDetail>>(c.OrderBy(d => d.Name));
        }

        public Trackbase TrackGetById(int id)
        {
            var o = ds.Tracks.Find(id);

            return (o == null) ? null : Mapper.Map<Track, Trackbase>(o);
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
    }
}