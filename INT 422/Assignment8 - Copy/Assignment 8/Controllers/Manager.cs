using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_8.Models;
using System.Security.Claims;

namespace Assignment_8.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private ApplicationDbContext ds = new ApplicationDbContext();

        // Declare a property to hold the user account for the current request
        // Can use this property here in the Manager class to control logic and flow
        // Can also use this property in a controller 
        // Can also use this property in a view; for best results, 
        // near the top of the view, add this statement:
        // var userAccount = new ConditionalMenu.Controllers.UserAccount(User as System.Security.Claims.ClaimsPrincipal);
        // Then, you can use "userAccount" anywhere in the view to render content
        public UserAccount UserAccount { get; private set; }

        public Manager()
        {
            // If necessary, add constructor code here

            // Initialize the UserAccount property
            UserAccount = new UserAccount(HttpContext.Current.User as ClaimsPrincipal);

            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;
        }

        // ############################################################
        // RoleClaim

        public List<string> RoleClaimGetAllStrings()
        {
            return ds.RoleClaims.OrderBy(r => r.Name).Select(r => r.Name).ToList();
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

        public IEnumerable<Albumbase> AlbumGetAll()
        {
            return Mapper.Map<IEnumerable<Album>, IEnumerable<Albumbase>>(ds.Albums);
        }

        public Albumbase AlbumGetById(int Albumid)
        {
            var o = ds.Albums.Find(Albumid);
            return (o == null) ? null : Mapper.Map<Album, Albumbase>(o);
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

        public IEnumerable<Artistbase> ArtistGetAll()
        {
            return Mapper.Map<IEnumerable<Artist>, IEnumerable<Artistbase>>(ds.Artists);
        }

        public Artistbase ArtistGetById(int ArtistId)
        {
            var o = ds.Artists.Find(ArtistId);
            return (o == null) ? null : Mapper.Map<Artist, Artistbase>(o);
        }

        public IEnumerable<GenreBase> GenreGetAll()
        {
            return Mapper.Map<IEnumerable<Genre>, IEnumerable<GenreBase>>(ds.Genres);
        }

        public GenreBase GenreGetById(int GenreId)
        {
            var o = ds.Genres.Find(GenreId);
            return (o == null) ? null : Mapper.Map<Genre, GenreBase>(o);
        }

        public Artistbase ArtistAdd(ArtistAddForm newItem)
        {
                var added = ds.Artists.Add(Mapper.Map<ArtistAddForm, Artist>(newItem));
                ds.SaveChanges();

                return (added == null) ? null : Mapper.Map<Artist, Artistbase>(added);
        }

        public Albumbase AlbumAdd(AlbumAddForm newItem)
        {
            var added = ds.Albums.Add(Mapper.Map<AlbumAddForm, Album>(newItem));
            ds.SaveChanges();

            return (added == null) ? null : Mapper.Map<Album, Albumbase>(added);
        }

        public Trackbase Trackadd(TrackAddForm newItem)
        {
            var added = ds.Tracks.Add(Mapper.Map<TrackAddForm, Track>(newItem));
            ds.SaveChanges();

            return (added == null) ? null : Mapper.Map<Track, Trackbase>(added);
        }

        public Trackbase TrackEdit(TrackEdit newItem)
        {
            var o = ds.Tracks.Find(newItem.Id);

            if (o == null)
            {
                return null;
            }
            else
            {
                ds.Entry(o).CurrentValues.SetValues(newItem);
                ds.SaveChanges();
                return Mapper.Map<Track, Trackbase>(o);
            }
        }

        public bool TrackDelete(int id)
        {
            // Attempt to fetch the object to be deleted
            var itemToDelete = ds.Tracks.Find(id);

            if (itemToDelete == null)
            {
                return false;
            }
            else
            {
                // Remove the object
                ds.Tracks.Remove(itemToDelete);
                ds.SaveChanges();

                return true;
            }
        }


        // Add some programmatically-generated objects to the data store
        // Can write one method, or many methods - your decision
        // The important idea is that you check for existing data first
        // Call this method from a controller action/method


        public bool LoadData()
        {
            // User name
            var user = HttpContext.Current.User.Identity.Name;

            // Monitor the progress
            bool done = false;

            // ############################################################
            // Genre
            if (ds.Genres.Count() > 0 || ds.Artists.Count() > 0 || ds.Albums.Count() > 0 || ds.Tracks.Count() > 0) { return false; }

            ds.Genres.Add(new Genre { Name = "Rock", Id = 1});
            ds.Genres.Add(new Genre { Name = "Pop", Id = 2 });
            ds.Genres.Add(new Genre { Name = "Alt Rock", Id = 3 });
            ds.Genres.Add(new Genre { Name = "Jazz", Id = 4 });
            ds.Genres.Add(new Genre { Name = "Metal", Id = 5 });
            ds.Genres.Add(new Genre { Name = "Electro", Id = 6 });
            ds.Genres.Add(new Genre { Name = "Hip Hop", Id = 7 });
            ds.Genres.Add(new Genre { Name = "Classical", Id = 8 });
            ds.Genres.Add(new Genre { Name = "Punk", Id = 9 });
            ds.Genres.Add(new Genre { Name = "RnB", Id = 10 });
            //April 29, 1899
            DateTime? dt = new DateTime(1899, 04, 29);
            //String.Format("{0:MM/dd/yyyy}", dt);
       
            ds.Artists.Add(new Artist { Name = "Duke Ellington", BirthName = "Edward Kennedy Ellington", BirthOrStartDate =  new DateTime(1899, 04, 29), Id = 1, UrlArtist = "https://upload.wikimedia.org/wikipedia/commons/a/af/Duke_Ellington_-_publicity.JPG" });

            dt = new DateTime(1984, 10, 25);

            ds.Artists.Add(new Artist { Name = "Katy Perry", BirthName = "Katheryn Elizabeth Hudson", BirthOrStartDate = new DateTime(1984, 10, 25), Id = 2, UrlArtist = "https://upload.wikimedia.org/wikipedia/commons/c/c2/Katy_Perry_UNICEF_2012.jpg" });

            dt = new DateTime(1986, 10, 24);

            ds.Artists.Add(new Artist { Name = "Drake", BirthName = "Aubrey Drake Graham", BirthOrStartDate = new DateTime(1986, 10, 24), Id = 3, UrlArtist = "https://iscale.iheart.com/v3/url/aHR0cDovL2ltYWdlLmloZWFydC5jb20vaW1hZ2VzL3JvdmkvMTA4MC8wMDAzLzcyMy9NSTAwMDM3MjM4NDguanBn" });
            
            var drake = ds.Artists.SingleOrDefault(a=>a.Name == "Drake");

            ds.Albums.Add(new Album
            {
                Artists = new List<Artist> { drake },
                Name = "Views",
                Id = 1,
                UrlAlbum = "https://upload.wikimedia.org/wikipedia/en/6/64/Drakeviewsfromthe6.jpg"
            });

            ds.Albums.Add(new Album
            {
                Artists = new List<Artist> { drake },
                Name = "Nothing Was The Same",
                Id = 2,
                UrlAlbum = "https://upload.wikimedia.org/wikipedia/en/b/b9/Nothing_Was_the_Same_cover_2.png"
            });

            var album = ds.Albums.SingleOrDefault(a=>a.Name == "Views");

            ds.Tracks.Add(new Track { Name = "Hotline Bling", Composers = "Drake", Albums = new List<Album> { album }, Id = 1 });
            ds.Tracks.Add(new Track { Name = "One Dance", Composers = "Drake", Albums = new List<Album> { album }, Id = 2 });
            ds.Tracks.Add(new Track { Name = "Pop Style", Composers = "Drake", Albums = new List<Album> { album }, Id = 3 });
            ds.Tracks.Add(new Track { Name = "Controlla", Composers = "Drake", Albums = new List<Album> { album }, Id = 4 });
            ds.Tracks.Add(new Track { Name = "Too Good", Composers = "Drake", Albums = new List<Album> { album }, Id = 5 });

            album = ds.Albums.SingleOrDefault(a => a.Name == "Nothing Was The Same");

            ds.Tracks.Add(new Track { Name = "Started From The Bottom", Composers = "Drake", Albums = new List<Album> { album }, Id = 6 });
            ds.Tracks.Add(new Track { Name = "Hold On, We're Going Home", Composers = "Drake", Albums = new List<Album> { album }, Id = 7 });
            ds.Tracks.Add(new Track { Name = "All Me", Composers = "Drake", Albums = new List<Album> { album }, Id = 8 });
            ds.Tracks.Add(new Track { Name = "Too Much", Composers = "Drake", Albums = new List<Album> { album }, Id = 9 });
            ds.Tracks.Add(new Track { Name = "Worst Behavior", Composers = "Drake", Albums = new List<Album> { album }, Id = 10 });

            ds.SaveChanges();

            //{
                // Add role claims
                //ds.SaveChanges();
                //done = true;
            //}

            return true;
        }

        public bool RemoveData()
        {
            try
            {
                foreach (var e in ds.RoleClaims)
                {
                    ds.Entry(e).State = System.Data.Entity.EntityState.Deleted;
                }

                foreach(var s in ds.Albums)
                {
                    ds.Entry(s).State = System.Data.Entity.EntityState.Deleted;
                }
                foreach (var s in ds.Artists)
                {
                    ds.Entry(s).State = System.Data.Entity.EntityState.Deleted;
                }
                foreach (var s in ds.Genres)
                {
                    ds.Entry(s).State = System.Data.Entity.EntityState.Deleted;
                }
                foreach (var s in ds.Tracks)
                {
                    ds.Entry(s).State = System.Data.Entity.EntityState.Deleted;
                }
                ds.SaveChanges();

                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        public bool RemoveDatabase()
        {
            try
            {
                return ds.Database.Delete();
            }
            catch (Exception)
            {
                return false;
            }
        }

    }

    // New "UserAccount" class for the authenticated user
    // Includes many convenient members to make it easier to render user account info
    // Study the properties and methods, and think about how you could use it
    public class UserAccount
    {
        // Constructor, pass in the security principal
        public UserAccount(ClaimsPrincipal user)
        {
            if (HttpContext.Current.Request.IsAuthenticated)
            {
                Principal = user;

                // Extract the role claims
                RoleClaims = user.Claims.Where(c => c.Type == ClaimTypes.Role).Select(c => c.Value);

                // User name
                Name = user.Identity.Name;

                // Extract the given name(s); if null or empty, then set an initial value
                string gn = user.Claims.SingleOrDefault(c => c.Type == ClaimTypes.GivenName).Value;
                if (string.IsNullOrEmpty(gn)) { gn = "(empty given name)"; }
                GivenName = gn;

                // Extract the surname; if null or empty, then set an initial value
                string sn = user.Claims.SingleOrDefault(c => c.Type == ClaimTypes.Surname).Value;
                if (string.IsNullOrEmpty(sn)) { sn = "(empty surname)"; }
                Surname = sn;

                IsAuthenticated = true;
                IsAdmin = user.HasClaim(ClaimTypes.Role, "Admin") ? true : false;
            }
            else
            {
                RoleClaims = new List<string>();
                Name = "anonymous";
                GivenName = "Unauthenticated";
                Surname = "Anonymous";
                IsAuthenticated = false;
                IsAdmin = false;
            }

            NamesFirstLast = $"{GivenName} {Surname}";
            NamesLastFirst = $"{Surname}, {GivenName}";
        }

        // Public properties
        public ClaimsPrincipal Principal { get; private set; }
        public IEnumerable<string> RoleClaims { get; private set; }

        public string Name { get; set; }

        public string GivenName { get; private set; }
        public string Surname { get; private set; }

        public string NamesFirstLast { get; private set; }
        public string NamesLastFirst { get; private set; }

        public bool IsAuthenticated { get; private set; }

        // Add other role-checking properties here as needed
        public bool IsAdmin { get; private set; }

        public bool HasRoleClaim(string value)
        {
            if (!IsAuthenticated) { return false; }
            return Principal.HasClaim(ClaimTypes.Role, value) ? true : false;
        }

        public bool HasClaim(string type, string value)
        {
            if (!IsAuthenticated) { return false; }
            return Principal.HasClaim(type, value) ? true : false;
        }
    }

}