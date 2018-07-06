using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using static System.Console;

namespace Tasks
{
    /// <summary>
    /// класс меню
    /// </summary>
    public static class MainMenu
    {
        /// <summary>
        /// главное меню
        /// </summary>
        /// <param name="xmlDocument">xml doc</param>
        public static void Start(IParser parser)
        {
            int answer;
            do
            {
                WriteLine("Main Menu:");
                WriteLine($"{(int)EnumMainMenu.Categories} - Categories,");
                WriteLine($"{(int)EnumMainMenu.Tasks} - Tasks,");
                WriteLine($"{(int)EnumMainMenu.Exit} - Exit");

                string data;
                do
                {
                    Write("your choice: ");
                    data = ReadLine();
                } while (!int.TryParse(data, out answer));

                switch ((EnumMainMenu)answer)
                {
                    case EnumMainMenu.Categories:
                    case EnumMainMenu.Tasks:
                        LevelMenu(parser, (EnumToDo)answer);
                        break;
                    case EnumMainMenu.Exit:
                        Environment.Exit(0);
                        break;
                    default:
                        WriteLine("error iteam menu...");
                        break;
                }
                ReadKey();
                Clear();

            } while (true);
        }

        /// <summary>
        /// меню задачи
        /// </summary>
        /// <param name="xmlDocument">документ с xml данными</param>
        private static void LevelMenu(IParser parser, EnumToDo elements)
        {
            Clear();
            int answer;
            do
            {
                WriteLine($"{elements} menu:");
                WriteLine($"{(int)EnumMenu.Edit} - Edit,");
                WriteLine($"{(int)EnumMenu.Add} - Add,");
                WriteLine($"{(int)EnumMenu.Delete} - Delete,");
                WriteLine($"{(int)EnumMenu.Show} - Show all");
                WriteLine($"{(int)EnumMenu.Back} - Back");

                string data;
                do
                {
                    Write("your choice: ");
                    data = ReadLine();
                } while (!int.TryParse(data, out answer));

                switch ((EnumMenu)answer)
                {
                    case EnumMenu.Add:
                        switch (elements)
                        {
                            case EnumToDo.Categories:
                                AddCategory(parser);
                                break;
                            case EnumToDo.Tasks:
                                AddTask(parser);
                                break;
                        }
                        break;
                    case EnumMenu.Edit:
                        switch (elements)
                        {
                            case EnumToDo.Categories:
                                EditCategory(parser);
                                break;
                            case EnumToDo.Tasks:
                                EditTask(parser);
                                break;
                        }
                        break;
                    case EnumMenu.Delete:
                        switch (elements)
                        {
                            case EnumToDo.Categories:
                                DeleteCategory(parser);
                                break;
                            case EnumToDo.Tasks:
                                DeleteTask(parser);
                                break;
                        }
                        break;
                    case EnumMenu.Show:
                        switch (elements)
                        {
                            case EnumToDo.Categories:
                                Console.WriteLine(parser.GetCategories());
                                break;
                            case EnumToDo.Tasks:
                                Console.WriteLine(parser.GetTasks());
                                break;
                        }
                        break;
                    case EnumMenu.Back:
                        Clear();
                        Start(parser);//возвращаемся в главное меню
                        break;

                    default:
                        WriteLine("error iteam menu....");
                        break;
                }
                WriteLine("Done!");
                ReadKey();
                Clear();

            } while (true);
        }

        /// <summary>
        /// добавить задачу
        /// </summary>
        /// <param name="xmlDocument"></param>
        private static void AddTask(IParser parser)
        {
            if(parser.EmptyCategory())
            {
                WriteLine("Anyone category!");
                return;
            }

            string id;
            do
            {
                Write("Enter id: ");
                id = ReadLine();
            } while (parser.ContainsTask(id));

            Write("Enter name: ");
            string name = ReadLine();

            Write("Enter title: ");
            string title = ReadLine();

            Write("Enter priority: ");
            string priority = ReadLine();

            WriteLine(parser.GetCategories());
            string category;
            do
            {
                Write("Enter category: ");
                category = ReadLine();
            } while (!parser.ContainsCategory(category));

            Write("Enter process: ");
            string process = ReadLine();

            Write("Enter start data: ");
            string startData = ReadLine();

            Write("Enter deadline: ");
            string deadline = ReadLine();

            //добавляем задачу
            parser.AddNewTask(id, name, title, priority, category, process, startData, deadline);
        }


        /// <summary>
        /// добавить категорию
        /// </summary>
        /// <param name="xmlDocument"></param>
        private static void AddCategory(IParser parser)
        {
            string id;
            do
            {
                Write("Enter id:");
                id = ReadLine();

            } while (parser.ContainsCategory(id));

            Write("Enter name: ");
            string name = ReadLine();

            //добавляем категорию
            parser.AddNewCategory(id, name);
        }


        /// <summary>
        /// редактировать задачу
        /// </summary>
        /// <param name="parser"></param>
        private static void EditTask(IParser parser)
        {
            if (parser.EmptyTasks())
            {
                WriteLine("Anyone task!");
                return;
            }

            WriteLine(parser.GetTasks());
            WriteLine("---------------------------------");
            string dataId;

            do
            {
                Write("Enter id to edit: ");
                dataId = ReadLine();
            } while (!parser.ContainsTask(dataId));

            WriteLine("Edit:");
            WriteLine($"{(int)EnumEditTask.Name} - name,");
            WriteLine($"{(int)EnumEditTask.Title} - title,");
            WriteLine($"{(int)EnumEditTask.Priority} - priority,");
            WriteLine($"{(int)EnumEditTask.Category} - category,");
            WriteLine($"{(int)EnumEditTask.Process} - process,");
            WriteLine($"{(int)EnumEditTask.StartTime} - start time,");
            WriteLine($"{(int)EnumEditTask.Deadline} - deadline,");
            WriteLine($"{(int)EnumEditTask.Cancel} - cancel");
            string data;
            int number;
            do
            {
                Write("your choice: ");
                data = ReadLine();
            } while (!int.TryParse(data, out number) || number < (int)EnumEditTask.Name || number > (int)EnumEditTask.Cancel);

            if (number == (int)EnumEditTask.Cancel)
            {
                return;
            }

            string newDatas = null;

            //если меняем категорию
            if (number == (int)EnumEditTask.Category)
            {
                WriteLine(parser.GetCategories());
                WriteLine("---------------------------------\n");

                do
                {
                    Write("Enter new id category: ");
                    newDatas = ReadLine();
                } while (!parser.ContainsCategory(newDatas));

            }
            else
            {
                Write("Enter new datas: ");
                newDatas = ReadLine();
            }

            parser.EditTaskData(dataId, newDatas, (EnumEditTask)number);
        }


        /// <summary>
        /// редактировать категорию
        /// </summary>
        /// <param name="xmlDocument"></param>
        private static void EditCategory(IParser parser)
        {
            if (parser.EmptyCategory())
            {
                WriteLine("Anyone category");
                return;
            }

            WriteLine(parser.GetCategories());
            WriteLine("---------------------------------\n");
            string dataId;
            do
            {
                Write("Enter id to edit: ");
                dataId = ReadLine();
            } while (!parser.ContainsCategory(dataId));

            WriteLine("Edit:");
            WriteLine($"{(int)EnumEditCategory.Id} - id,");
            WriteLine($"{(int)EnumEditCategory.Name} - name,");
            WriteLine($"{(int)EnumEditCategory.Cancel} - cancel");

            string data;
            int number;

            do
            {
                Write("your choice: ");
                data = ReadLine();
            } while (!int.TryParse(data, out number) || number < (int)EnumEditCategory.Id || number > (int)EnumEditCategory.Cancel);

            if (number == (int)EnumEditCategory.Cancel)
            {
                return;
            }

            string newData;
            Write("Enter new data: ");
            newData = ReadLine();

            parser.EditCategory(dataId, newData, (EnumEditCategory)number);
        }


        /// <summary>
        /// удалить задачу
        /// </summary>
        /// <param name="xmlDocument"></param>
        private static void DeleteTask(IParser parser)
        {
            if (parser.EmptyTasks())
            {
                WriteLine("Anyone task!");
                return;
            }
            WriteLine(parser.GetTasks());
            WriteLine("---------------------------------\n");
            string dataId;

            Write("Enter id to delete: ");
            dataId = ReadLine();

            parser.DeleteTaskById(dataId);
        }


        /// <summary>
        /// удалить категорию
        /// </summary>
        /// <param name="xmlDocument"></param>
        private static void DeleteCategory(IParser parser)
        {
            if(parser.EmptyCategory())
            {
                WriteLine("Anyone category!");
                return;
            }

            WriteLine(parser.GetCategories());
            WriteLine("---------------------------------\n");
            string dataId;

            Write("Enter id to delete: ");
            dataId = ReadLine();

            //удаляем категорию
            parser.DeleteCategory(dataId);
        }
    }
}