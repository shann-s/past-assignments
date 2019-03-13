using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace AssocAddEdit
{
    public static class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here - using AutoMapper static API
            // Mapper.Initialize(cfg => cfg.CreateMap< FROM , TO >());
            Mapper.Initialize(cfg => {
                // Add map creation statements here
                cfg.CreateMap<Models.Country, Controllers.CountryBase>();

                cfg.CreateMap<Models.Manufacturer, Controllers.ManufacturerBase>();
                cfg.CreateMap<Models.Manufacturer, Controllers.ManufacturerWithDetail>();

                cfg.CreateMap<Models.Vehicle, Controllers.VehicleBase>();
                cfg.CreateMap<Models.Vehicle, Controllers.VehicleWithDetail>();
                cfg.CreateMap<Controllers.VehicleAdd, Models.Vehicle>();
                cfg.CreateMap<Controllers.VehicleBase, Controllers.VehicleEditForm>();
                cfg.CreateMap<Controllers.VehicleWithDetail, Controllers.VehicleEditForm>();
            });
        }
    }
}