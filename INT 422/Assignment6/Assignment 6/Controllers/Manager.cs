using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_6.Models;

namespace Assignment_6.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            // Turn off the Entity Framework (EF) proxy creation features

            // We do NOT want the EF to track changes - we'll do that ourselves

            ds.Configuration.ProxyCreationEnabled = false;



            // Also, turn off lazy loading...

            // We want to retain control over fetching related objects

            ds.Configuration.LazyLoadingEnabled = false;
            // If necessary, add constructor code here
        }

        public IEnumerable<PlaylistWithDetail> PlaylistGetAll()
        {
            return Mapper.Map<IEnumerable<Playlist>, IEnumerable<PlaylistWithDetail>>(ds.Playlists.Include("Tracks").OrderBy(e => e.Name));
        }

        public IEnumerable<PlaylistWithDetail> PlaylistGetAllWithTracks()
        {
            return Mapper.Map<IEnumerable<Playlist>, IEnumerable<PlaylistWithDetail>>(ds.Playlists.Include("Tracks").OrderBy(e => e.Name));
        }

        public Playlistbase PlaylistGetById(int id)
        {
            var o = ds.Playlists.Find(id);

            return (o == null) ? null : Mapper.Map<Playlist, Playlistbase>(o);
        }

        public PlaylistWithDetail PlaylistGetByIdWithDetail(int id)
        {
            var o = ds.Playlists.Include("Tracks").SingleOrDefault(e => e.PlaylistId == id);

            return (o == null) ? null : Mapper.Map<Playlist, PlaylistWithDetail>(o);
        }

        public PlaylistWithDetail PlaylistEditTracks(PlaylistEditTracks newItem)
        {
            var o = ds.Playlists.Include("Track").SingleOrDefault(e => e.PlaylistId == newItem.Id);

            if (o == null)
            {
                return null;
            }

            else
            {
                o.Tracks.Clear();

                foreach (var item in newItem.TrackIds)
                {
                    var a = ds.Tracks.Find(item);
                    o.Tracks.Add(a);
                }
                ds.SaveChanges();

                return Mapper.Map<Playlist, PlaylistWithDetail>(o);
            }
        }

        public IEnumerable<Trackbase> TrackGetAll()
        {
            return Mapper.Map<IEnumerable<Track>, IEnumerable<Trackbase>>(ds.Tracks);
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