using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateStudent
{
    /// <summary>
    /// интерфейс журнала
    /// </summary>
    public interface IJournalMarks
    {
        /// <summary>
        /// количество студентов
        /// </summary>
        int Count { get; set; }

        /// <summary>
        /// массив студентов
        /// </summary>
        IStudent[] Students { get; }

        /// <summary>
        /// добавить студента в журнал
        /// </summary>
        /// <param name="student">новый студент</param>
        void AddStudent(Student student);
    }
}
