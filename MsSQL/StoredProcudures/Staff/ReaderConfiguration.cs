using System;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.IO;

namespace Staff
{
    public static class ReaderConfiguration
    {
        public static void DoConfigure()
        {
            AppSettings.ConnectionString = File.ReadAllText("appsettings.txt");
        }
    }
}