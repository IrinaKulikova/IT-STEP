using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace UsersMSSQL
{
    internal static class ConsoleUtilUser
    {
        internal static User GetData()
        {
            User user = new User();
            Write("Name: ");
            user.Name = ReadLine();
            Write("Second name: ");
            user.SecondName = ReadLine();
            Write("Last name: ");
            user.LastName = ReadLine();
            Write("Phone: ");
            user.Phone = ReadLine();
            Write("Email: ");
            user.Email = ReadLine();
            return user;
        }

        internal static void Show(IList<User> list)
        {
            WriteLine(string.Join("\n\n", list));
            ReadKey();
        }
    }
}