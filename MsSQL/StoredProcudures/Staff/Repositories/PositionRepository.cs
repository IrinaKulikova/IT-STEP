using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;

namespace Staff
{
    public class PositionsRepository : IRepository<Position>
    {
        public IList<Position> GetAll()
        {
            var list = new List<Position>();
            using (var conn = ConnectionDB.GetConnection())
            {
                conn.Open();
                var command = conn.CreateCommand();
                command.CommandText = "[StaffHW].[dbo].[GetPositions]";
                command.CommandType = CommandType.StoredProcedure;
                var reader = command.ExecuteReader();
                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        list.Add(new Position
                        {
                            Id = reader.GetInt32(0),
                            Name = reader.GetString(1)
                        });
                    }
                }
            }
            return list;
        }

        public Position GetById(int id)
        {
            Position position = null;
            using (var conn = ConnectionDB.GetConnection())
            {
                conn.Open();
                var command = conn.CreateCommand();
                command.CommandText = "[StaffHW].[dbo].[GetPositionById]";
                command.CommandType = CommandType.StoredProcedure;
                var paramId = new SqlParameter
                {
                    ParameterName = "PositionId",
                    Value = id
                };

                command.Parameters.Add(paramId);
                var reader = command.ExecuteReader();
                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        position = new Position
                        {
                            Id = reader.GetInt32(0),
                            Name = reader.GetString(1)
                        };
                    }
                }
            }
            return position;
        }

        public int Create(Position position)
        {
            int result = 0;
            using (var conn = ConnectionDB.GetConnection())
            {
                conn.Open();
                var command = conn.CreateCommand();
                command.CommandText = "[StaffHW].[dbo].[AddPosition]";
                command.CommandType = CommandType.StoredProcedure;

                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Name",
                    Value = position.Name
                });
                result = command.ExecuteNonQuery();
            }
            return result;
        }

        public int Update(Position position)
        {
            int result = 0;
            using (var conn = ConnectionDB.GetConnection())
            {
                conn.Open();
                var command = conn.CreateCommand();
                command.CommandText = "[StaffHW].[dbo].[UpdatePosition]";
                command.CommandType = CommandType.StoredProcedure;
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Id",
                    Value = position.Id
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Name",
                    Value = position.Name
                });
                result = command.ExecuteNonQuery();
            }
            return result;
        }

        public int Delete(int id)
        {
            int result = 0;
            using (var conn = ConnectionDB.GetConnection())
            {
                conn.Open();
                var command = conn.CreateCommand();
                command.CommandText = "[StaffHW].[dbo].[DeletePosition]";
                command.CommandType = CommandType.StoredProcedure;
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Id",
                    Value = id
                });
                result = command.ExecuteNonQuery();
            }
            return result;
        }
    }
}