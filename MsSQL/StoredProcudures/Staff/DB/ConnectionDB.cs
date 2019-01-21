using System;
using System.Data.SqlClient;
using System.Collections.Generic;

namespace Staff
{
    public static class ConnectionDB
    {
        public static SqlConnection GetConnection()
        {
            return new SqlConnection(AppSettings.ConnectionString);
        }
    }
}