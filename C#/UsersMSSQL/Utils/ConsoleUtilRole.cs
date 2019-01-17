using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace UsersMSSQL
{
    internal static class ConsoleUtilRole
    {
        internal static Role GetData()
        {
            Role role = new Role();
            Write("Role's name: ");
            role.Name = ReadLine();
            return role;
        }
        internal static void Show(IList<Role> list)
        {
            WriteLine(string.Join("\n\n", list));
            ReadKey();
        }
    }
}