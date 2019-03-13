﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_8.Controllers
{
    [Authorize(Roles = "Admin")]
    public class LoadDataController : Controller
    {
        // Reference to the manager object
        Manager m = new Manager();

        // GET: LoadData
        public ActionResult Index()
        {
            if (m.LoadData())
            {
                ViewBag.Result = "Data was loaded";
            }
            else
            {
                ViewBag.Result = "(done)";
            }
            return View("Result");
        }

        public ActionResult Load()
        {
            if (m.LoadData())
            {
                ViewBag.Result = "Data was loaded";
            }
            else
            {
                ViewBag.Result = "(done)";
            }
            return View("result");
        }

        public ActionResult Remove()
        {
            if (m.RemoveData())
            {
                return Content("data has been removed");
            }
            else
            {
                return Content("could not remove data");
            }
        }

        public ActionResult RemoveDatabase()
        {
            if (m.RemoveDatabase())
            {
                return Content("database has been removed");
            }
            else
            {
                return Content("could not remove database");
            }
        }

    }
}