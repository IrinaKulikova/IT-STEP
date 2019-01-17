using System;
using System.Data.Common;
using System.Data.SqlClient;
using System.Text;

namespace UsersMSSQL
{
    public class Account
    {
        public int Id { get; set; }
        public string Login { get; set; }
        public string Password { get; set; }
        public Role Role { get; set; }

        public override string ToString()
        {
            StringBuilder builder = new StringBuilder();
            builder.Append($"Id {Id}\n");
            builder.Append($"Login {Login}\n");
            builder.Append($"Password {Password}\n");
            builder.Append($"Role {Role}");
            return builder.ToString();
        }
    }
}