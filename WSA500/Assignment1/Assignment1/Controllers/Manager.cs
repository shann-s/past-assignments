using Assignment1.Models;
using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment1.Controllers
{
    public class Manager
    {
        private ApplicationDbContext ds = new ApplicationDbContext();

        MapperConfiguration config;
        public IMapper mapper;

        public Manager()
        {

            // Configure the AutoMapper components
            config = new MapperConfiguration(cfg =>
            {
                // Define the mappings below, for example...
                // cfg.CreateMap();
                cfg.CreateMap<Models.Smartphone, SmartphoneBase>();
                // cfg.CreateMap();
                cfg.CreateMap<Models.Smartphone, SmartphoneAdd>();

                // Object mapper definitions (add them on the next few lines...)
            });

            mapper = config.CreateMapper();
        }

        public IEnumerable<SmartphoneBase> SmartphoneGetAll()
        {
            //return Mapper.Map<IEnumerable<Smartphone>, IEnumerable<SmartphoneBase>>(ds.SmartPhone);
            return mapper.Map<IEnumerable<SmartphoneBase>>(ds.SmartPhone.OrderBy(c => c.Id));
        }

        public IEnumerable<SmartphoneBase> SmartphoneGetOne(int ID)
        {
            var o = ds.SmartPhone.Find(ID);
            return (o == null) ? null : mapper.Map<IEnumerable<SmartphoneBase>>(ds.SmartPhone.OrderBy(c => c.Id));
        }

        public SmartphoneBase SmartphoneAdd(SmartphoneAdd newItem)
        {
            var added = ds.SmartPhone.Add(mapper.Map<SmartphoneAdd, Smartphone>(newItem));

            ds.SaveChanges();

            return (added == null) ? null : mapper.Map<Smartphone, SmartphoneBase>(added);
        }

    }
}