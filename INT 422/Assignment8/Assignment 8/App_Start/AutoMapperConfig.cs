using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace Assignment_8
{
    public static class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // AutoMapper create map statements - using AutoMapper static API
            // Mapper.Initialize(cfg => cfg.CreateMap< FROM , TO >());
            // Add map creation statements here
            Mapper.Initialize(cfg =>
            {
                cfg.CreateMap<Models.RegisterViewModel, Models.RegisterViewModelForm>();

                //add new
                cfg.CreateMap<Controllers.TrackAddForm, Models.Track>();
                cfg.CreateMap<Controllers.AlbumAddForm, Models.Album>();
                cfg.CreateMap<Controllers.ArtistAddForm, Models.Artist>();

                //get all & get one
                cfg.CreateMap<Models.Album, Controllers.Albumbase>();
                cfg.CreateMap<Models.Artist, Controllers.Artistbase>();
                cfg.CreateMap<Models.Genre, Controllers.GenreBase>();
                cfg.CreateMap<Models.Track, Controllers.Trackbase>();

            });

        }
    }
}