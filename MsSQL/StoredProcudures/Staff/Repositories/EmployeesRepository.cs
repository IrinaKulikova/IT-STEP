using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;

namespace Staff
{
    public class EmployeesRepository : IRepository<Employee>
    {
        public IList<Employee> GetAll()
        {
            var list = new List<Employee>();
            using (var conn = ConnectionDB.GetConnection())
            {
                conn.Open();
                var command = conn.CreateCommand();
                command.CommandText = "[StaffHW].[dbo].[GetEmployees]";
                command.CommandType = CommandType.StoredProcedure;
                var reader = command.ExecuteReader();
                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        int? order = null;
                        order = (!reader.IsDBNull(6)) ? reader.GetInt32(6) : order;

                        int? position = null;
                        position = (!reader.IsDBNull(4)) ? reader.GetInt32(4) : position;

                        list.Add(new Employee
                        {
                            Id = reader.GetInt32(0),
                            Name = reader.GetString(1),
                            Surname = reader.GetString(2),
                            Birth = reader.GetDateTime(3),
                            PositionId = position,
                            OrderStart = reader.GetInt32(5),
                            OrderEnd = order,
                            Image = reader.IsDBNull(7) ? String.Empty : reader.GetString(7)
                        });
                    }
                }
            }
            return list;
        }

        public Employee GetById(int id)
        {
            Employee employee = null;
            using (var conn = ConnectionDB.GetConnection())
            {
                conn.Open();
                var command = conn.CreateCommand();
                command.CommandText = "[StaffHW].[dbo].[GetEmployeeById]";
                command.CommandType = CommandType.StoredProcedure;
                var paramId = new SqlParameter
                {
                    ParameterName = "EmployeeId",
                    Value = id
                };

                command.Parameters.Add(paramId);
                var reader = command.ExecuteReader();
                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        int? order = null;
                        order = (!reader.IsDBNull(6)) ? reader.GetInt32(6) : order;

                        int? position = null;
                        position = (!reader.IsDBNull(4)) ? reader.GetInt32(4) : position;

                        employee = new Employee
                        {
                            Id = reader.GetInt32(0),
                            Name = reader.GetString(1),
                            Surname = reader.GetString(2),
                            Birth = reader.GetDateTime(3),
                            PositionId = position,
                            OrderStart = reader.GetInt32(5),
                            OrderEnd = order,
                            Image = reader.IsDBNull(7) ? String.Empty : reader.GetString(7)
                        };

                    }
                }
            }
            return employee;
        }

        public int Create(Employee employee)
        {
            int result = 0;
            using (var conn = ConnectionDB.GetConnection())
            {
                conn.Open();
                var command = conn.CreateCommand();
                command.CommandText = "[StaffHW].[dbo].[AddEmployee]";
                command.CommandType = CommandType.StoredProcedure;

                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Name",
                    Value = employee.Name
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Surname",
                    Value = employee.Surname
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Birth",
                    Value = employee.Birth
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Position",
                    Value = employee.PositionId
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "OrderStart",
                    Value = employee.OrderStart
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "OrderEnd",
                    Value = employee.OrderEnd
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Image",
                    Value = employee.Image
                });
                result = command.ExecuteNonQuery();
            }
            return result;
        }

        public int Update(Employee employee)
        {
            int result = 0;
            using (var conn = ConnectionDB.GetConnection())
            {
                conn.Open();
                var command = conn.CreateCommand();
                command.CommandText = "[StaffHW].[dbo].[UpdateEmployee]";
                command.CommandType = CommandType.StoredProcedure;
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Id",
                    Value = employee.Id
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Name",
                    Value = employee.Name
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Surname",
                    Value = employee.Surname
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Birth",
                    Value = employee.Birth
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Position",
                    Value = employee.PositionId
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "OrderStart",
                    Value = employee.OrderStart
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "OrderEnd",
                    Value = employee.OrderEnd
                });
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Image",
                    Value = employee.Image
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
                command.CommandText = "[StaffHW].[dbo].[DeleteEmployee]";
                command.CommandType = CommandType.StoredProcedure;
                command.Parameters.Add(new SqlParameter
                {
                    ParameterName = "Id",
                    Value =id
                });
                result = command.ExecuteNonQuery();
            }
            return result;
        }
    }
}