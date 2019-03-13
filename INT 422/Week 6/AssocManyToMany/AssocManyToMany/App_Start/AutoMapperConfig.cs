using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace AssocManyToMany
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
                cfg.CreateMap<Models.Employee, Controllers.EmployeeWithJobDuties>();
                cfg.CreateMap<Controllers.EmployeeBase, Controllers.EmployeeEditJobDutiesForm>();

                cfg.CreateMap<Models.JobDuty, Controllers.JobDutyBase>();
                cfg.CreateMap<Models.JobDuty, Controllers.JobDutyWithEmployees>();
                cfg.CreateMap<Controllers.JobDutyBase, Controllers.JobDutyEditEmployeesForm>();

            });
        }
    }
}