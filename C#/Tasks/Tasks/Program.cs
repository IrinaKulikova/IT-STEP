using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

/*видео: https://youtu.be/R1Dk0WgMkpg

Написать приложение для ведения списка задач.
Каждая задача включает:
	- название
	- описание
	- приоритет
	- категория
	- степень выполнения
	- дата старта
	- срок выполнения (дата окончания)

Категория включает
	- название
	- список задач

Приложение должно предоставлять пользователю возможность:
	1. Добавить/редактировать/удалить задачу
	2. Добавить/редактировать/удалить категорию
	3. Все таски и категории должны сохраняться 
           и считываться из xml фала.*/

namespace Tasks
{
    class Program
    {
        static void Main(string[] args)
        {
            //путь к документу
            string path = "Tasks.xml";

            //создаём парсер
            IParser parser = new Parser(path);

            //запускаем меню
            MainMenu.Start(parser);
        }
    }
}
