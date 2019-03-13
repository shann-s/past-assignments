using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace AssocSelf
{
    public static class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here - using AutoMapper static API
            // Mapper.Initialize(cfg => cfg.CreateMap< FROM , TO >());
            Mapper.Initialize(cfg => { 

                // Add map creation statements here
                cfg.CreateMap<Models.Employee, Controllers.EmployeeBase>();
                cfg.CreateMap<Models.Employee, Controllers.EmployeeWithOrgInfo>();
                cfg.CreateMap<Controllers.EmployeeBase, Controllers.EmployeeEditSupervisorForm>();
                cfg.CreateMap<Controllers.EmployeeBase, Controllers.EmployeeEditDirectReportsForm>();

            });
        }
    }
}