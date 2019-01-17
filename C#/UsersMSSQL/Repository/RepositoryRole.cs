using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Text;

namespace UsersMSSQL
{
    class RepositoryRole : IRepository<Role>
    {
        public int Add(Role item)
        {
            int rows = 0;
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                var sql = "INSERT INTO [Role]([Name]) VALUES ('" + item.Name + "')";
                var command = conn.CreateCommand();
                command.CommandText = sql;
                rows = command.ExecuteNonQuery();
            }
            return rows;
        }

        public int Delete(int id)
        {
            int rows = 0;
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                var sql = "DELETE FROM [Role] WHERE [Id] = " + id;
                var command = conn.CreateCommand();
                command.CommandText = sql;
                rows = command.ExecuteNonQuery();
            }
            return rows;
        }

        public IList<Role> GetAll()
        {
            var roles = new List<Role>();
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                var sql = "SELECT r.Id, r.Name FROM Role as r";
                var command = conn.CreateCommand();
                command.CommandText = sql;
                var reader = command.ExecuteReader();
                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        roles.Add(new Role
                        {
                            Id = reader.GetInt32(0),
                            Name = reader.GetString(1)
                        });
                    }
                }
            }
            return roles;
        }

        public int Update(Role item)
        {
            int rows = 0;
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                var sql = "UPDATE Role SET [Name] = '" + item.Name + "' WHERE [Id] = " + item.Id;
                var command = conn.CreateCommand();
                command.CommandText = sql;
                rows = command.ExecuteNonQuery();
            }
            return rows;
        }
    }
}
