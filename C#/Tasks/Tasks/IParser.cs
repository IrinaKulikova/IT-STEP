using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Tasks
{
    /// <summary>
    /// интерфейс класса Parser
    /// </summary>
    public interface IParser
    {
        /// <summary>
        /// документ с которым работает класс
        /// </summary>
        XmlDocument Document { get; }

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
        void AddNewTask(string id, string name, string title, string priority, string category, string process, string startData, string deadline);


        /// <summary>
        /// метод добавляет новую категорию
        /// </summary>
        /// <param name="id">id категории</param>
        /// <param name="name">имя категории</param>
        void AddNewCategory(string id, string name);


        /// <summary>
        /// метод редактирует данные в задаче
        /// </summary>
        /// <param name="dataId">id задачи</param>
        /// <param name="newDatas">новые данные</param>
        /// <param name="number">номер атрибута для замены</param>
        void EditTaskData(string dataId, string newDatas, EnumEditTask number);


        /// <summary>
        /// метод проверяет существует ли задача искомым id
        /// </summary>
        /// <param name="id">искомый id</param>
        /// <returns>true - задача с искомым id существует</returns>
        bool ContainsTask(string id);


        /// <summary>
        /// метод определяем, существует ли катигория с соответствующим id
        /// </summary>
        /// <param name="id">id категории, котрою ищим</param>
        /// <returns>true - такая категория есть</returns>
        bool ContainsCategory(string id);


        /// <summary>
        /// редактировать id категории
        /// </summary>
        /// <param name="idCategory">id категории, котрой меняем id</param>
        /// <param name="newId">новое id</param>
        void EditCategory(string idCategory, string newId, EnumEditCategory categoryEdit);


        /// <summary>
        /// проверка на наличие задач
        /// </summary>
        /// <returns>пустой список- true</returns>
        bool EmptyTasks();


        /// <summary>
        /// проверка наличия категорий
        /// </summary>
        /// <returns></returns>
        bool EmptyCategory();

        /// <summary>
        /// удаление задачи по id
        /// </summary>
        /// <param name="id"></param>
        void DeleteTaskById(string id);


        /// <summary>
        /// посмотреть все задачи
        /// </summary>
        string GetTasks();


        /// <summary>
        /// выводим в консоль категории
        /// </summary>
        string GetCategories();


        /// <summary>
        /// метод удаляет категорию по id
        /// </summary>
        /// <param name="id">id катигории</param>
        void DeleteCategory(string id);
    }
}