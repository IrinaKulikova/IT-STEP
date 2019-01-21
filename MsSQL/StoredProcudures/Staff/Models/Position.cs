using System;
using System.Collections.Generic;
using System.Text;

namespace Staff
{
    public class Position
    {
        public int Id { get; set; }
        public string Name { get; set; }
        
        public override string ToString()
        {
            var builder = new StringBuilder();
            builder.Append($"Id - {Id}\n");
            builder.Append($"Name - {Name}\n");
            return builder.ToString();
        }
    }
}