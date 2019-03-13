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
            return Mapper.Map<IEnumerable<Album>, IEnumerable<Albumbase>>(ds.Albums);
        }

        public Albumbase AlbumGetById(int Albumid)
        {
            var o = ds.Albums.Find(Albumid);
            return (o == null) ? null : Mapper.Map<Album, Albumbase>(o);
        }

        public IEnumerable<Mediatypebase> MediatypeGetAll()
        {
            return Mapper.Map<IEnumerable<MediaType>, IEnumerable<Mediatypebase>>(ds.MediaTypes);
        }

        public Mediatypebase MediatypeGetById(int Mediatypeid)
        {
            var o = ds.MediaTypes.Find(Mediatypeid);
            return (o == null) ? null : Mapper.Map<MediaType, Mediatypebase>(o);
        }

        public IEnumerable<Trackbase> TrackGetAll()
        {
            return Mapper.Map<IEnumerable<Track>, IEnumerable<Trackbase>>(ds.Tracks);
        }

        public Trackbase TrackGetById(int TrackId)
        {
            var o = ds.Tracks.Find(TrackId);
            return (o == null) ? null : Mapper.Map<Track, Trackbase>(o);
        }

        public IEnumerable<TrackWithDetail> TrackGetAllWithDetail()
        {
            var c = ds.Tracks.Include("MediaType");

            return Mapper.Map<IEnumerable<Track>, IEnumerable<TrackWithDetail>>(c.OrderBy(m => m.Name));
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