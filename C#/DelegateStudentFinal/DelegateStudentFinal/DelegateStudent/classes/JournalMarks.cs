using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateStudent
{
    /// <summary>
    /// журнал оценок студентов
    /// </summary>
    public class JournalMarks : IJournalMarks
    {
        /// <summary>
        /// массив студентов
        /// </summary>
        public IStudent[] Students { get; set; }

        /// <summary>
        /// количество студентов
        /// </summary>
        public int Count { get; set; }

        /// <summary>
        /// количество студентов по умолчанию
        /// </summary>
        private static int _size = 10;

        /// <summary>
        /// конструктор по умолчанию
        /// </summary>
        public JournalMarks() : this(_size) { }

        /// <summary>
        /// конструктор с заданными параметрами
        /// </summary>
        /// <param name="size">количество студентов</param>
        public JournalMarks(int size)
        {
            Students = new Student[size];
            Count = 0;
        }

        /// <summary>
        /// добавить студента в журнал
        /// </summary>
        /// <param name="student">новый студент</param>
        public void AddStudent(Student student)
        {
            if (Count >= Students.Length)
            {
                Student[] newStudents = new Student[Students.Length + _size];
                Array.Copy(Students, newStudents, Students.Length);
                Students = newStudents;
            }
            Students[Count++] = student;
        }

        /// <summary>
        /// вывод информации о журнале
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            string list = null;
            for (int i = 0; i < Count; i++)
            {
                list += $"{i + 1 }" + ". ";
                list += Students[i];
                list += "\n";
            }
            return list;
        }
    }
}