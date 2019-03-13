using Assignment_6.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Assignment_6.Controllers
{
    public class Trackbase
    {
        public int TrackId { get; set; }

        public int Id { get; set; }

        [Required]
        [StringLength(200)]
        public string Name { get; set; }

        [StringLength(220)]
        public string Composer { get; set; }

        public int Milliseconds { get; set; }

        [Column(TypeName = "numeric")]
        public decimal UnitPrice { get; set; }

        public virtual Album Album { get; set; }

        public string FullName

        {

            get

            {

                var ms = Math.Round((((double)Milliseconds / 1000) / 60), 1);



                var composer = string.IsNullOrEmpty(Composer) ? "" : ", composer " + Composer;

                var trackLength = (ms > 0) ? ", " + ms.ToString() + " minutes" : "";

                var unitPrice = (UnitPrice > 0) ? ", $ " + UnitPrice.ToString() : "";



                return string.Format("{0}{1}{2}{3}", Name, composer, trackLength, unitPrice);

            }

        }
    }
}