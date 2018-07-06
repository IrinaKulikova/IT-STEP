using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace FileSystem
{
    /// <summary>
    /// класс взаимодействия с пользователем
    /// </summary>
    static public class DialogConsole
    {
        /// <summary>
        /// метод проверяет корректность введенной даты
        /// </summary>
        /// <param name="year">год</param>
        /// <param name="mounth">месяц</param>
        /// <param name="day">день</param>
        /// <returns></returns>
        static private bool CheckDataDay(int year, int mounth, int day)
        {
            int longFebruary = 29;
            int shotFebruary = 28;
            int longMounth = 31;
            int shotMounth = 30;

            const int HUNDRED = 100;
            const int FOURHUNDRED = 400;
            const int FOUR = 4;

            if ((int)Mounths.February == mounth)//если введен февраль
            {
                if ((year % FOUR == 0 && year % HUNDRED != 0) || year % FOURHUNDRED == 0)
                {
                    if (day > longFebruary)//проверка на длину месяца и ссответствия числа
                    {
                        return false;
                    }
                }
                else
                {
                    if (day > shotFebruary)//проверка на длину месяца и сoответствия числа
                    {
                        return false;
                    }
                }
            }
            else if ((int)Mounths.April == mounth || (int)Mounths.June == mounth || (int)Mounths.August == mounth || (int)Mounths.November == mounth)//если месяц короткий
            {
                if (day > shotMounth)//проверка на длину месяца и ссответствия числа
                {
                    return false;
                }
            }
            else//если месяц длинный
            {
                if (day > longMounth)//проверка на длину месяца и ссответствия числа
                {
                    return false;
                }
            }

            return true;
        }

        /// <summary>
        /// метод получает дату для поиска
        /// </summary>
        /// <returns></returns>
        private static DateTime GetData()
        {
            Console.WriteLine("Enter data to search files.");

            string data = null;
            int year = 0;
            int minYear = 1980;
            int MaxYear = DateTime.Now.Year;

            do
            {
                Console.Write("Year: ");
                data = Console.ReadLine();
            } while (!int.TryParse(data, out year) || year < minYear || year > MaxYear);

            int mounth = 0;
            int minMount = 1;
            int maxMounth = 12;
            if (year == MaxYear)
            {
                maxMounth = DateTime.Now.Month;
            }

            do
            {
                Console.Write("Mounth: ");
                data = Console.ReadLine();
            } while (!int.TryParse(data, out mounth) || mounth < minMount || mounth > maxMounth);

            int day = 0;
            do
            {
                Console.Write("day: ");
                data = Console.ReadLine();
            } while (!int.TryParse(data, out day) || !CheckDataDay(year, mounth, day));

            //получаем время для рубежа копирования
            DateTime date = new DateTime(year, mounth, day, 0, 0, 0);
            return date;
        }

        public static BackUper InstanceBackUper()
        {
            //создаём объект архиватор
            BackUper backUper = new BackUper();

            //запрашиваем путь к папке для перебора содержимого
            Console.Write(@"Enter directory path(for example  D:\books\): ");
            backUper.Path = Console.ReadLine();
            //backUper.Path = @"D:\ШАГ\books\";

            Console.Write(@"Enter arhive directory path (for example  D:\): ");
            backUper.PathForCreateDirectoryArchive = Console.ReadLine();
            //backUper.PathForCreateDirectoryArchive = @"D:\";

            //получаем дату поиска
            backUper.SearchDate = GetData();
            //backUper.SearchDate = new DateTime(2016, 2, 24, 0, 0, 0);

            return backUper;
        }

        public static void Menu()
        {
            do
            {
                int answer = -1;//выбраный пользователем пункт меню
                string data = null;//считываемая строка

                Console.WriteLine("Menu: ");
                Console.WriteLine($"{(int)MenuEnum.AddToArchiveFiles} - Add to arhive,");
                Console.WriteLine($"{(int)MenuEnum.RestoreFromArchiveFiles} - Restore from arhive,");
                Console.WriteLine($"{(int)MenuEnum.Exit} - Exit");

                do
                {
                    Console.Write("your choice: ");
                    data = Console.ReadLine();
                } while (!int.TryParse(data, out answer));

                switch ((MenuEnum)answer)
                {
                    case MenuEnum.AddToArchiveFiles:
                        BackUper.AddToArchive();
                        Console.WriteLine("Done!");
                        break;
                    case MenuEnum.RestoreFromArchiveFiles:
                        BackUper.RestoreFromArchive();
                        Console.WriteLine("Done!");
                        break;
                    case MenuEnum.Exit:
                        Environment.Exit(0);
                        break;
                    default:
                        Console.WriteLine("error menu iteam...");
                        break;
                }

                Console.ReadKey();
                Console.Clear();

            } while (true);
        }
    }
}
