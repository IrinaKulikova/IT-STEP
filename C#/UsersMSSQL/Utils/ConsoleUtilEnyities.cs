using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace UsersMSSQL
{
    internal static class ConsoleUtilEntities
    {
        internal static void ErrorMessageId()
        {
            WriteLine("There is no id!");
        }

        internal static int GetId()
        {
            Write("Id: ");
            int id = 0;
            string data = String.Empty;
            do
            {
                data = ReadLine();
            } while (!int.TryParse(data, out id));
            return int.Parse(data);
        }
    }
}