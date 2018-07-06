using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateStudent
{
    /// <summary>
    /// интерфейс объект
    /// </summary>
    public interface ISubject
    {
        /// <summary>
        /// делегат, информирующий о среднем бале у студента по предметам
        /// </summary>
        MarkDlg MarkSubjects { get; set; }

        /// <summary>
        /// делегат, информирующий о переходе студента на следующий курс по данному предмету
        /// </summary>
        StudentGoNextDlg StudentGoNext { get; set; }

        /// <summary>
        /// название предмета
        /// </summary>
        string Name { get; set; }

        /// <summary>
        /// массив оценок
        /// </summary>
        int[] Marks { get; }

        /// <summary>
        /// количество добавленных оценок
        /// </summary>
        int Count { get; }

        /// <summary>
        /// средняя оценка по предмету
        /// </summary>
        int MiddleMark { get; }

        /// <summary>
        /// свойство предмет сдан
        /// </summary>
        bool SubjectPassed { get; }

        /// <summary>
        /// перегруженный индексатор
        /// </summary>
        /// <param name="index">индекс оценки</param>
        /// <returns>оценка</returns>
        int this[int index] { get; set; }

        /// <summary>
        /// метод добавления оценки
        /// </summary>
        /// <param name="mark"></param>
        void AddMark(int mark);

        /// <summary>
        /// удалить оценку по индексу
        /// </summary>
        void DelMark(int index);
    }
}