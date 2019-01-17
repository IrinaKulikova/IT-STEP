using System;
using System.Data.Common;
using System.Data.SqlClient;

namespace UsersMSSQL
{
    public class Role
    {
        public int Id { get; set; }
        public string Name { get; set; }

        public override string ToString() => $"Role: Id - {Id}, Name - {Name}";
    }
}