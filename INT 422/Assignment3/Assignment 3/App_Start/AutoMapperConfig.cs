using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace Assignment_3
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
                cfg.CreateMap<Models.Employee, Controllers.Employee_base>();
                cfg.CreateMap<Controllers.Employee_base, Controllers.EmployeeEditForm>();
                cfg.CreateMap<Models.Track, Controllers.Track_Base>();
            });

        }
    }
}