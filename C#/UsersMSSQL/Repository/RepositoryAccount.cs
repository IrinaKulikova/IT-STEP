using System;
using System.Collections.Generic;
using System.Data.SqlClient;

namespace UsersMSSQL
{
    class RepositoryAccount : IRepository<Account>
    {
        public int Add(Account item)
        {
            int rows = 0;
            if (item.Role == null || item.Role.Id == 0)
            {
                item.Role = new Role { Id = 2 };
            }
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                var sql = "INSERT INTO [Account]([Login],[Password],[RoleId]) VALUES ('" + item.Login + "', '" + item.Password + "', '" + item.Role.Id + "')";
                var command = conn.CreateCommand();
                command.CommandText = sql;
                rows = command.ExecuteNonQuery();
            }
            return rows;
        }

        public Account GetByLogin(string login)
        {
            Account account = null;
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                string sql = "SELECT a.Id, a.Login, a.Password, r.Id, r.Name FROM Account AS a INNER JOIN [Role] as r ON a.RoleId = r.Id WHERE [Login] = '" + login + "'";
                var command = conn.CreateCommand();
                command.CommandText = sql;
                var reader = command.ExecuteReader();
                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        var role = new Role()
                        {
                            Id = reader.GetInt32(3),
                            Name = reader.GetString(4)
                        };

                        account = new Account
                        {
                            Id = reader.GetInt32(0),
                            Login = reader.GetString(1),
                            Password = reader.GetString(2),
                            Role = role
                        };
                    }
                }
            }
            return account;
        }

        public int Delete(int id)
        {
            int rows = 0;
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                var sql = "DELETE FROM [Account] WHERE [Id] = " + id;
                var command = conn.CreateCommand();
                command.CommandText = sql;
                rows = command.ExecuteNonQuery();
            }
            return rows;
        }

        public IList<Account> GetAll()
        {
            var accounts = new List<Account>();
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                string sql = "SELECT a.Id, a.Login, a.Password, r.Id, r.Name FROM Account as a join Role as r on a.RoleId = r.Id";
                var command = conn.CreateCommand();
                command.CommandText = sql;
                var reader = command.ExecuteReader();
                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        var role = new Role()
                        {
                            Id = reader.GetInt32(3),
                            Name = reader.GetString(4)
                        };
                        accounts.Add(new Account
                        {
                            Id = reader.GetInt32(0),
                            Login = reader.GetString(1),
                            Password = reader.GetString(2),
                            Role = role
                        });
                    }
                }
            }
            return accounts;
        }

        public int Update(Account item)
        {
            int rows = 0;
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                var sql = "UPDATE [Account] SET [Login] = '" + item.Login + "', [Password] = '" + item.Password + "' WHERE [Id] = " + item.Id;
                var command = conn.CreateCommand();
                command.CommandText = sql;
                rows = command.ExecuteNonQuery();
            }
            return rows;
        }
    }
}
