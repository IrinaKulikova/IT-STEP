using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateStudent
{
    /// <summary>
    /// класс студент
    /// </summary>
    public class Student : IStudent
    {
        /// <summary>
        /// минимальный возраст студента
        /// </summary>
        public static int minAge = 12;

        /// <summary>
        /// имя
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// возраст
        /// </summary>
        public int Age { get; set; }

        /// <summary>
        /// номер телефона
        /// </summary>
        public string PhoneNumber { get; set; }

        /// <summary>
        /// массив предметов
        /// </summary>
        public Subject[] Subjects { get; set; }

        /// <summary>
        /// количество предметов
        /// </summary>
        private int _countSubjects = 3;

        /// <summary>
        /// конструктор с задаными параметрами
        /// </summary>
        /// <param name="Name">имя</param>
        /// <param name="Age">возраст</param>
        /// <param name="PhoneNumber">номер телефона</param>
        public Student(string Name, int Age, string PhoneNumber)
        {
            this.Name = Name;
            this.Age = Age;
            this.PhoneNumber = PhoneNumber;
            Subjects = new Subject[_countSubjects];
            Subjects[(int)SubjectsName.Administration - 1] = new Subject("Administration");
            Subjects[(int)SubjectsName.Design - 1] = new Subject("Design");
            Subjects[(int)SubjectsName.Programming - 1] = new Subject("Programming");
        }
        
        /// <summary>
        /// перегрузка выода информации о студенте
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            return $"{Name} , age: {Age}, phone: {PhoneNumber}\n{Subjects[0]}\n{Subjects[1]}\n{Subjects[2]}\n";
        }
    }
}
