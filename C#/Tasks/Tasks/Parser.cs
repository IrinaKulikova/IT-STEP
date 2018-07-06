using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Tasks
{
    /// <summary>
    /// класс парсит и редактирукт xmlDocument
    /// </summary>
    public class Parser : IParser
    {
        /// <summary>
        /// документ с которым работает класс
        /// </summary>
        public XmlDocument Document { get; }

        /// <summary>
        /// путь к документу
        /// </summary>
        private string pathFileXml;

        /// <summary>
        /// конструктор
        /// </summary>
        /// <param name="path">путь к фокумену xml</param>
        public Parser(string path)
        {
            Document = new XmlDocument();
            pathFileXml = path;
            Document.Load(path);
        }

        public Parser()
        {
        }

        /// <summary>
        /// статические строки
        /// </summary>
        private string idTag = "id";
        private string valueTag = "value";
        private string nameTag = "name";
        private string taskTag = "task";
        private string tasksTag = "tasks";
        private string titleTag = "title";
        private string priorityTag = "priority";
        private string categoryTag = "category";
        private string processTag = "process";
        private string startTimeTag = "timeStart";
        private string deadlineTag = "deadline";
        private string categoriesTag = "categories";

        /// <summary>
        /// добавление новой задачи
        /// </summary>
        /// <param name="name">имя задачи</param>
        /// <param name="title">описание</param>
        /// <param name="priority">приоритет</param>
        /// <param name="category">категория</param>
        /// <param name="process">готовность</param>
        /// <param name="startData">дата старта</param>
        /// <param name="deadline">срок выполнения</param>
        public void AddNewTask(string id, string name, string title, string priority, string category, string process, string startData, string deadline)
        {
            //создаём элемент
            XmlElement element = Document.CreateElement(taskTag);

            //создаём атрибут
            XmlAttribute idAttribute = Document.CreateAttribute(idTag);

            //добавляем значение атрибуду
            idAttribute.Value = id;

            //добавляем атрибут элементу
            element.Attributes.Append(idAttribute);

            //создаём элемент
            XmlElement nameTask = Document.CreateElement(nameTag);

            //создаём атрибут
            XmlAttribute nameAttribute = Document.CreateAttribute(valueTag);

            //добавляем значение атрибуду
            nameAttribute.Value = name;

            //добавляем атрибут элементу
            nameTask.Attributes.Append(nameAttribute);

            //добавляем в элемент элемент
            element.AppendChild(nameTask);

            XmlElement titleTask = Document.CreateElement(titleTag);
            XmlAttribute titleAttribute = Document.CreateAttribute(valueTag);
            titleAttribute.Value = title;
            titleTask.Attributes.Append(titleAttribute);
            element.AppendChild(titleTask);

            XmlElement priorityTask = Document.CreateElement(priorityTag);
            XmlAttribute priorityAttribute = Document.CreateAttribute(valueTag);
            priorityAttribute.Value = priority;
            priorityTask.Attributes.Append(priorityAttribute);
            element.AppendChild(priorityTask);

            XmlElement categoryTask = Document.CreateElement(categoryTag);
            XmlAttribute categoryAttribute = Document.CreateAttribute(idTag);
            categoryAttribute.Value = category;
            categoryTask.Attributes.Append(categoryAttribute);
            element.AppendChild(categoryTask);

            XmlElement processTask = Document.CreateElement(processTag);
            XmlAttribute processAttribute = Document.CreateAttribute(valueTag);
            processAttribute.Value = process;
            processTask.Attributes.Append(processAttribute);
            element.AppendChild(processTask);

            XmlElement startTimeTask = Document.CreateElement(startTimeTag);
            XmlAttribute startTimeAttribute = Document.CreateAttribute(valueTag);
            startTimeAttribute.Value = startData;
            startTimeTask.Attributes.Append(startTimeAttribute);
            element.AppendChild(startTimeTask);

            XmlElement deadlineTask = Document.CreateElement(deadlineTag);
            XmlAttribute deadlineAttribute = Document.CreateAttribute(valueTag);
            deadlineAttribute.Value = deadline;
            deadlineTask.Attributes.Append(deadlineAttribute);
            element.AppendChild(deadlineTask);

            XmlNodeList list = Document.GetElementsByTagName(tasksTag);

            //добавляем элемент задача
            if (list != null)
            {
                list[0].AppendChild(element);

                //сохраняем документ
                Document.Save(pathFileXml);
            }
        }


        /// <summary>
        /// метод добавляет новую категорию
        /// </summary>
        /// <param name="id">id категории</param>
        /// <param name="name">имя категории</param>
        public void AddNewCategory(string id, string name)
        {
            XmlElement element = Document.CreateElement(categoryTag);
            XmlAttribute idAttribute = Document.CreateAttribute(idTag);
            idAttribute.Value = id;
            element.Attributes.Append(idAttribute);

            XmlAttribute nameAttribute = Document.CreateAttribute(nameTag);
            nameAttribute.Value = name;
            element.Attributes.Append(nameAttribute);

            XmlNodeList list = Document.GetElementsByTagName(categoriesTag);

            if (list != null)
            {
                list[0].AppendChild(element);
                Document.Save(pathFileXml);
            }
        }

        /// <summary>
        /// метод редактирует данные в задаче
        /// </summary>
        /// <param name="dataId">id задачи</param>
        /// <param name="newDatas">новые данные</param>
        /// <param name="number">номер атрибута для замены</param>
        public void EditTaskCategory(string dataId, string newDatas, EnumEditTask number)
        {
            //ищем узел по тегу <tasks> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(tasksTag);

            if (xmlNodeList != null)
            {

                //перебираем элементы
                foreach (XmlNode node in xmlNodeList)
                {
                    //приводим найденный узел к элементу
                    XmlElement child = node as XmlElement;

                    //ищим в узлы по тэгу <task>
                    XmlNodeList list = child.GetElementsByTagName(taskTag);

                    if (list != null)
                    {
                        //перебираем узлы
                        foreach (XmlNode childnode in list)
                        {
                            //приводим узел у элементу
                            XmlElement task = childnode as XmlElement;

                            //если у задачи соответствующий id
                            if (task.ChildNodes[(int)number - 1].Attributes[0].Value.CompareTo(dataId) == 0)
                            {
                                task.ChildNodes[(int)number - 1].Attributes[0].Value = newDatas;
                            }

                        }
                    }
                    Document.Save(pathFileXml);
                }
            }
        }


        /// <summary>
        /// метод редактирует данные в задаче
        /// </summary>
        /// <param name="dataId">id задачи</param>
        /// <param name="newDatas">новые данные</param>
        /// <param name="number">номер атрибута для замены</param>
        public void EditTaskData(string dataId, string newDatas, EnumEditTask number)
        {
            //ищем узел по тегу <tasks> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(tasksTag);

            //перебираем элементы
            foreach (XmlNode node in xmlNodeList)
            {
                //приводим найденный узел к элементу
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <task>
                XmlNodeList list = child.GetElementsByTagName(taskTag);

                //перебираем узлы
                foreach (XmlNode childnode in list)
                {
                    //приводим узел у элементу
                    XmlElement task = childnode as XmlElement;

                    //если у задачи соответствующий id
                    if (task.Attributes[0].Value.CompareTo(dataId) == 0)
                    {
                        task.ChildNodes[(int)number - 1].Attributes[0].Value = newDatas;
                        break;
                    }
                }
            }
            Document.Save(pathFileXml);
        }

        /// <summary>
        /// метод проверяет существует ли задача искомым id
        /// </summary>
        /// <param name="id">искомый id</param>
        /// <returns>true - задача с искомым id e;t tcnm</returns>
        public bool ContainsTask(string id)
        {
            //ищем узел по тегу <tasks> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(tasksTag);

            //перебираем элементы
            foreach (XmlNode node in xmlNodeList)
            {
                //приводим найденный узел к элементу
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <task>
                XmlNodeList list = child.GetElementsByTagName(taskTag);

                List<XmlElement> listDelete = new List<XmlElement>();

                //перебираем узлы
                foreach (XmlNode childnode in list)
                {
                    //приводим узел у элементу
                    XmlElement task = childnode as XmlElement;

                    if (task.Attributes[0].Value.CompareTo(id) == 0)//если у задачи искомый id удаляем её
                    {
                        return true;
                    }
                }
            }
            return false;
        }


        /// <summary>
        /// метод определяем, существует ли катигория с соответствующим id
        /// </summary>
        /// <param name="id">id категории, котрою ищим</param>
        /// <returns>true - такая категория есть</returns>
        public bool ContainsCategory(string id)
        {
            //ищем узел по тегу <categories> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(categoriesTag);

            //перебираем найденные узлы
            foreach (XmlNode node in xmlNodeList)
            {
                //приводим найденный узел к элементу
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <category>
                XmlNodeList list = child.GetElementsByTagName(categoryTag);

                if (list != null)
                {

                    //перебираем полученные узлы
                    foreach (XmlNode childnode in list)
                    {
                        //приводим узел к элементу
                        XmlElement category = childnode as XmlElement;

                        //если id катигории совпало с искомым
                        if (category.Attributes[0].Value.CompareTo(id) == 0)
                        {
                            return true;
                        }
                    }
                }
            }

            return false;
        }


        /// <summary>
        /// редактировать id категории
        /// </summary>
        /// <param name="idCategory">id категории, котрой меняем id</param>
        /// <param name="newId">новое id</param>
        public void EditCategory(string idCategory, string newId, EnumEditCategory categoryEdit)
        {
            //ищем узел по тегу <categories> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(categoriesTag);

            //перебираем найденные узлы
            foreach (XmlNode node in xmlNodeList)
            {
                //приводим найденный узел к элементу
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <category>
                XmlNodeList list = child.GetElementsByTagName(categoryTag);

                if (list != null)
                {
                    //перебираем полученные узлы
                    foreach (XmlNode childnode in list)
                    {
                        //приводим узел к элементу
                        XmlElement category = childnode as XmlElement;

                        if (category.Attributes[0].Value.CompareTo(idCategory) == 0)
                        {
                            //удаляем атребут со старым id
                            category.RemoveAttributeNode(category.Attributes[(int)categoryEdit - 1]);

                            //создаём новый атрибут id
                            XmlAttribute xmlAttribute = null;
                            if (categoryEdit == EnumEditCategory.Id)
                            {
                                xmlAttribute = Document.CreateAttribute(idTag);
                                //задаём ему значение

                                xmlAttribute.Value = newId;

                                //добавляем атрибут
                                category.Attributes.InsertBefore(xmlAttribute, category.Attributes[(int)categoryEdit - 1]);
                            }
                            else
                            {
                                xmlAttribute = Document.CreateAttribute(nameTag);
                                //задаём ему значение

                                xmlAttribute.Value = newId;

                                //добавляем атрибут
                                category.Attributes.Append(xmlAttribute);
                            }
                        }
                    }
                }
                if (categoryEdit == EnumEditCategory.Id)
                {
                    //переименовываем id в задачах для категории
                    EditTaskCategory(idCategory, newId, EnumEditTask.Category);
                }

                //сохраняем документ
                Document.Save(pathFileXml);
            }
        }

        /// <summary>
        /// проверка на наличие категорий
        /// </summary>
        /// <returns>категории отсутствуют true</returns>
        public bool EmptyCategory()
        {
            //ищем узел по тегу <categories> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(categoriesTag);

            //перебираем найденные узлы
            foreach (XmlNode node in xmlNodeList)
            {
                //приводим найденный узел к элементу
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <category>
                XmlNodeList list = child.GetElementsByTagName(categoryTag);

                if (list.Count != 0)
                {
                    return false;
                }
            }

            return true;
        }


        /// <summary>
        /// проверка на наличие задач
        /// </summary>
        /// <returns>пустой список- true</returns>
        public bool EmptyTasks()
        {
            //ищем узел по тегу <tasks> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(tasksTag);

            //перебираем элементы
            foreach (XmlNode node in xmlNodeList)
            {
                //приводим найденный узел к элементу
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <task>
                XmlNodeList list = child.GetElementsByTagName(taskTag);

                //если задачи найдены
                if (list.Count != 0)
                {
                    return false;
                }
            }
            return true;
        }

        /// <summary>
        /// удаление задачи по id
        /// </summary>
        /// <param name="id"></param>
        public void DeleteTaskById(string id)
        {
            //ищем узел по тегу <tasks> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(tasksTag);

            //перебираем элементы
            foreach (XmlNode node in xmlNodeList)
            {
                //приводим найденный узел к элементу
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <task>
                XmlNodeList list = child.GetElementsByTagName(taskTag);

                if (list != null)
                {
                    List<XmlElement> listDelete = new List<XmlElement>();

                    //перебираем узлы
                    foreach (XmlNode childnode in list)
                    {
                        //приводим узел у элементу
                        XmlElement task = childnode as XmlElement;

                        if (task.Attributes[0].Value.CompareTo(id) == 0)//если у задачи искомый id удаляем её
                        {
                            child.RemoveChild(task);
                            break;
                        }
                    }
                    Document.Save(pathFileXml);
                }
            }
        }


        /// <summary>
        /// удаление задач по id категории
        /// </summary>
        /// <param name="id">id категории</param>
        private void DeleteTaskByCategoryId(string id, EnumEditTask editTask)
        {
            //ищем узел по тегу <tasks> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(tasksTag);

            //перебираем элементы
            foreach (XmlNode node in xmlNodeList)
            {
                //приводим найденный узел к элементу
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <task>
                XmlNodeList list = child.GetElementsByTagName(taskTag);

                if (list != null)
                {
                    List<XmlElement> listDelete = new List<XmlElement>();

                    //перебираем узлы
                    foreach (XmlNode childnode in list)
                    {
                        //приводим узел у элементу
                        XmlElement task = childnode as XmlElement;

                        if ((task.ChildNodes[(int)editTask - 1] as XmlElement).Attributes[0].Value.CompareTo(id) == 0)//если у категории задачи искомый id
                        {
                            //node.RemoveChild(task);
                            listDelete.Add(task);
                        }
                    }

                    if (listDelete.Count > 0)
                    {
                        foreach (XmlElement element in listDelete)
                        {
                            node.RemoveChild(element);
                        }
                    }
                }
            }
        }


        /// <summary>
        /// посмотреть все задачи
        /// </summary>
        public string GetTasks()
        {
            if (EmptyTasks())
            {
                return $"Anyone task!";
            }

            //ищем узел по тегу <tasks> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(tasksTag);

            //строка с данными
            int i = 1;
            StringBuilder data = new StringBuilder($"\n\ntask {i++} is:\n");

            //перебираем элементы
            foreach (XmlNode node in xmlNodeList)
            {
                //приводим найденный узел к элементу
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <task>
                XmlNodeList list = child.GetElementsByTagName(taskTag);

                if (list != null)
                {
                    //перебираем узлы
                    foreach (XmlNode childnode in list)
                    {
                        //приводим узел у элементу
                        XmlElement task = childnode as XmlElement;

                        data.Append($"  id - {task.Attributes[0].Value}\n");
                        data.Append($"  name - {(task.ChildNodes[0] as XmlElement).Attributes[0].Value}\n");
                        data.Append($"  title - {(task.ChildNodes[1] as XmlElement).Attributes[0].Value}\n");
                        data.Append($"  priority - {(task.ChildNodes[2] as XmlElement).Attributes[0].Value}\n");
                        data.Append($"  category - {(task.ChildNodes[3] as XmlElement).Attributes[0].Value}\n");
                        data.Append($"  process - {(task.ChildNodes[4] as XmlElement).Attributes[0].Value}\n");
                        data.Append($"  start time - {(task.ChildNodes[5] as XmlElement).Attributes[0].Value}\n");
                        data.Append($"  deadline - {(task.ChildNodes[6] as XmlElement).Attributes[0].Value}\n");
                        data.Append("------------------------\n");
                    }
                }
                else
                {
                    data.Append("empty....\n");
                }
            }
            return data.ToString();
        }


        /// <summary>
        /// выводим в консоль категории
        /// </summary>
        public string GetCategories()
        {
            if (EmptyCategory())
            {
                return $"Anyone category!";
            }

            //ищем узел по тегу <categories> такой у нас должен быть 1 в документе
            XmlNodeList xmlNodeList = Document.GetElementsByTagName(categoriesTag);

            StringBuilder data = new StringBuilder($"\n\ncatigories is:\n");

            //перебираем найденные узлы
            foreach (XmlNode node in xmlNodeList)
            {
                //приводим найденный узел к элементу
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <category>
                XmlNodeList list = child.GetElementsByTagName(categoryTag);

                if (list != null)
                {
                    //перебираем полученные узлы
                    foreach (XmlNode childnode in list)
                    {
                        //приводим узел к элементу
                        XmlElement category = childnode as XmlElement;
                        data.Append($"-------------------------\n ");

                        //перебираем атрибуты элемента и выводим их в консоль
                        foreach (XmlAttribute xmlAttribute in category.Attributes)
                        {
                            data.Append($"{xmlAttribute.Name} - {xmlAttribute.Value}, ");
                        }
                        data.Append("\n");
                    }
                }
                else
                {
                    data.Append("empty....\n");
                }
            }
            return data.ToString();
        }


        /// <summary>
        /// метод удаляет категорию по id
        /// </summary>
        /// <param name="id">id катигории</param>
        public void DeleteCategory(string id)
        {
            //ищим узлы с тэгом категория
            XmlNodeList nodeList = Document.GetElementsByTagName(categoriesTag);

            foreach (XmlNode node in nodeList)
            {
                XmlElement child = node as XmlElement;

                //ищим в узлы по тэгу <category>
                XmlNodeList list = child.GetElementsByTagName(categoryTag);

                if (list != null)
                {

                    //перебираем полученные узлы
                    foreach (XmlNode childnode in list)
                    {
                        //приводим узел к элементу
                        XmlElement category = childnode as XmlElement;

                        //если у текущей категории совпал id,удаляем её
                        if (category.Attributes[0].Value.CompareTo(id) == 0)
                        {
                            node.RemoveChild(category);
                            break;
                        }
                    }
                }
                //удаляем задачи с искомой категорией
                DeleteTaskByCategoryId(id, EnumEditTask.Category);

                //сохраняем документ
                Document.Save(pathFileXml);
            }
        }
    }
}
