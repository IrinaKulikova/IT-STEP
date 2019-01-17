using System;
using System.Collections.Generic;
using System.Data.SqlClient;

namespace UsersMSSQL
{
    public class RepositoryUser : IRepository<User>
    {
        public int Add(User item)
        {
            int rows = 0;
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                var sql = "INSERT INTO [User]([Name] , [SecondName] , [LastName] ,[Phone] , [Email] , [AccountId]) VALUES ('"
                            + item.Name + "', '" + item.SecondName + "', '" + item.LastName + "', '" + item.Phone + "', '" +
                            item.Email + "', " + item.Account.Id + ")";
                System.Console.WriteLine(sql);
                System.Console.ReadKey();
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
                var sql = "DELETE FROM [User] WHERE [Id] = " + id;
                var command = conn.CreateCommand();
                command.CommandText = sql;
                rows = command.ExecuteNonQuery();
            }
            return rows;
        }

        public IList<User> GetAll()
        {
            var users = new List<User>();
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                string sql = "SELECT u.Id,  u.Name , u.SecondName, u.LastName, u.Phone, u.Email ,"
                    + " a.Id , a.Login, a.Password , r.Id, r.Name FROM [User] u INNER JOIN [Account] a "
                    + " ON u.AccountId = a.Id INNER JOIN [Role] as r ON a.RoleId = r.Id";
                var command = conn.CreateCommand();
                command.CommandText = sql;
                var reader = command.ExecuteReader();
                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        var role = new Role
                        {
                            Id = reader.GetInt32(9),
                            Name = reader.GetString(10)
                        };
                        var account = new Account
                        {
                            Id = reader.GetInt32(6),
                            Login = reader.GetString(7),
                            Password = reader.GetString(8),
                            Role = role
                        };
                        users.Add(new User
                        {
                            Id = reader.GetInt32(0),
                            Name = reader.GetString(1),
                            SecondName = reader.GetString(2),
                            LastName = reader.GetString(3),
                            Phone = reader.GetString(4),
                            Email = reader.GetString(5),
                            Account = account,
                        });
                    }
                }
            }
            return users;
        }

        public int Update(User item)
        {
            int rows = 0;
            using (var conn = Program.GetConnection())
            {
                conn.Open();
                var sql = "UPDATE [User] SET [Name] = '" + item.Name + "', [SecondName] = '" + item.SecondName +
                             "', [LastName] = '" + item.LastName + "', [Phone] = '" + item.Phone +
                              "', [Email] = '" + item.Email + "' WHERE [Id] = " + item.Id;
                var command = conn.CreateCommand();
                command.CommandText = sql;
                rows = command.ExecuteNonQuery();
            }
            return rows;
        }
    }
}