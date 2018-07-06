using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*Видео занятий:
	https://youtu.be/_wF8EmbjBZ8
	https://youtu.be/ToaRI9jSbuQ
	https://youtu.be/YdmAwGNBhFs

Домашнее задание.

1) Написать программу в которой будет класс Студент, у которого будет: имя, возраст, телефон и оценки. 
Дать пользователю возможность проставить оценки студенту по одной из трех дисциплин: 
Администрирование, Программирование, Дизайн. 

Предусмотреть вызов делегата на момент выставления последней оценки по каждой дисциплине об 
информации среднего бала и делегата проходит или не проходит студент по данной дисциплине на следующий курс.

2) Добавить функционал:
	Поставить оценку
	Изменить оценку
	Удалить оценку
    
Пересчёт среднего бала осуществляется после каждого изменения.*/

namespace DelegateStudent
{
    /// <summary>
    /// делегат, информирующий о среднем бале предмета у студента
    /// </summary>
    /// <param name="student"></param>
    /// <param name="subject"></param>
    public delegate void MarkDlg(ISubject subject);

    /// <summary>
    /// определение делегата
    /// </summary>
    /// <param name="student"></param>
    /// <param name="subject"></param>
    public delegate void StudentGoNextDlg(ISubject subject);


    class Program
    {
        //создаём объекты, генерирующие случайные числа
        static Random randomCount = new Random();
        static Random randomMark = new Random();

        /// <summary>
        /// наполняем жулнал оценками
        /// </summary>
        /// <param name="subject">предмет</param>
        public static void InitSubject(ISubject subject)
        {
            //минимальное и максимальное количество оценок по предмету
            const int MINCOUNTMARKS = 7;
            const int MAXCOUNTMARKS = 10;

            //генерируем количество оценок
            int marksCount = randomCount.Next(MINCOUNTMARKS, MAXCOUNTMARKS);

            //минимальная и максимальная оценка
            const int MINMARK = 3;
            const int MAXMARK = 12;

            //добавляем оценку
            for (int i = 0; i < marksCount; i++)
            {
                subject.AddMark(randomMark.Next(MINMARK, MAXMARK));
            }
        }

        /// <summary>
        /// информер переходит студент на следующий курс или нет
        /// </summary>
        /// <param name="student">студент</param>
        /// <param name="subject">предмет</param>
        public static void SubjectPassedInformer(ISubject subject)
        {
            if (subject.SubjectPassed)
            {
                Console.WriteLine($" -Subject passed! //delegate");
            }
            else
            {
                Console.WriteLine($" -Subject not passed! //delegate");
            }
        }

        /// <summary>
        /// информер среднего бала по предмету у студента
        /// </summary>
        /// <param name="student">студент</param>
        /// <param name="subject">предмет</param>
        public static void MarkInformer(ISubject subject)
        {
            Console.WriteLine(subject);
            Console.WriteLine($" -Avarege mark: {subject.MiddleMark} //delegate");
        }

        static void Main(string[] args)
        {
            //создаём журнал
            IJournalMarks journalMarks = new JournalMarks();

            //создаём массив студентов
            int countStudent = 3;

            IStudent[] students = new Student[countStudent];

            //создаём студентов
            students[0] = new Student("Ilya Popovich", 24, "+380699874563");
            students[1] = new Student("Vasiliy Fedorez", 22, "+380638524697");
            students[2] = new Student("Inna Levchenko", 21, "+380504789632");

            int countSubjects = 3;

            //наполняем оценками предметы
            foreach (Student iteam in students)
            {
                for (int i = 0; i < countSubjects; i++)
                {
                    InitSubject(iteam.Subjects[i]);
                    iteam.Subjects[i].MarkSubjects = MarkInformer;
                    iteam.Subjects[i].StudentGoNext = SubjectPassedInformer;
                }

                //добавляем студентов в журнал
                journalMarks.AddStudent(iteam);
            }

            //запускаем меню
            JournalMenu.StartMenuJournal(journalMarks);
        }
    }
}