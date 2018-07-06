using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*Задание 1.
Написать приложение, которое позволит рекурсивно находить все файлы
новее заданной даты и копировать их в папку заданную пользователем.

Пользователь вводит:
	- директорию с которой начинается поиск
	- выходную директорию
	- дату

При наличии в папке archive файла с таким-же именем необходимо переименовать файл.
Во время копирования вести журнал следующего формата:

[23.10.2017 10:12] c:\Users\student\Desctop\test.txt -> d:\archive\test.txt
[23.10.2017 10:12] c:\Users\student\Desctop\tmp\test.txt -> d:\archive\test1.txt

 Задание 3 (дополнительное).
Написать программу восстановления файлов из папки архива (см задание 1), 
но только в том случае если файлы были удалены или обнаружены файлы позднее сохраненных в архиве*/


namespace FileSystem
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "BackUper 1.0 Kulikova edition";

            //ведем диалог с пользователем
            DialogConsole.Menu();
        }
    }
}
