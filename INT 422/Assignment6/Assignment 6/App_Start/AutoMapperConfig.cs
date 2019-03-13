using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace Assignment_6
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
                cfg.CreateMap<Models.Track, Controllers.Trackbase>();
                cfg.CreateMap<Models.Playlist, Controllers.Playlistbase>();
                cfg.CreateMap<Controllers.Playlistbase, Controllers.PlaylistEditTracksForm>();
                cfg.CreateMap<Models.Playlist, Controllers.PlaylistWithDetail>();
            });
        }
    }
}