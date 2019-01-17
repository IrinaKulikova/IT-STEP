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
            Write("Введите имя: ");
            user.Name = ReadLine();
            Write("Введите отчество: ");
            user.SecondName = ReadLine();
            Write("Введите фамилию: ");
            user.LastName = ReadLine();
            Write("Введите телефон: ");
            user.Phone = ReadLine();
            Write("Введите почту: ");
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