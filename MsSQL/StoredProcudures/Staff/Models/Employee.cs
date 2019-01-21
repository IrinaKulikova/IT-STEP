using System;
using System.Collections.Generic;
using System.Text;

namespace Staff
{
    public class Employee 
    {
        public int Id { get; set; }
         public string Name { get; set; }
        public string Surname { get; set; }
        public DateTime Birth { get; set; }
        public int? PositionId { get; set; }
        public int OrderStart { get; set; }
        public int? OrderEnd { get; set; }
        public string Image { get; set; }

        public override string  ToString(){
            var builder = new StringBuilder();
            builder.Append($"Id - {Id}\n");
            builder.Append($"Name - {Name}\n");
            builder.Append($"Surname - {Surname}\n");
            builder.Append($"Birth - {Birth}\n");
            builder.Append($"Position id - {PositionId}\n");
            builder.Append($"OrderStart - {OrderStart}\n");
            builder.Append($"OrderEnd - {OrderEnd}\n");
            builder.Append($"Image - {Image}\n");
            return builder.ToString();
        }
    }
}