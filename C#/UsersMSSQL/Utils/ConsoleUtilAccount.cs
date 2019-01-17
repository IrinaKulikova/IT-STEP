using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace UsersMSSQL
{
    internal static class ConsoleUtilAccount
    {
        internal static Account GetData()
        {
            Account account = new Account();
            Write("Введите логин: ");
            account.Login = ReadLine();
            Write("Введите пароль: ");
            account.Password = ReadLine();
            return account;
        }

        internal static void Show(IList<Account> list)
        {
            WriteLine(string.Join("\n\n", list));
            ReadKey();
        }
    }
}