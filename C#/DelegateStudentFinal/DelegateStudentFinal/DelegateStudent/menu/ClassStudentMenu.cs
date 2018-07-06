using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace DelegateStudent
{
    /// <summary>
    /// меню студента
    /// </summary>
    public static class StudentMenu
    {
        /// <summary>
        /// ввод оценки
        /// </summary>
        /// <returns></returns>
        private static int EnterData(string text)
        {
            int mark = 0;
            string data = null;
            do
            {
                Write(text);
                data = ReadLine();
            } while (!int.TryParse(data, out mark));
            return mark;
        }


        public static void ChoiceSubject(IJournalMarks journalMarks, IStudent student)
        {
            WriteLine();
            int number = 0;
            string data = null;

            do
            {
                WriteLine("Choice subject, enter number(1-3): ");
                WriteLine((int)SubjectsName.Administration + " - Administration,");
                WriteLine((int)SubjectsName.Design + " - Design,");
                WriteLine((int)SubjectsName.Programming + " - Programming,");
                WriteLine((int)SubjectsName.Back + " - Back");
                Write("Your choice: ");
                data = ReadLine();

            } while (!int.TryParse(data, out number));

            if (number == (int)SubjectsName.Back)
            {
                return;
            }

            switch ((SubjectsName)number)
            {
                case SubjectsName.Administration:
                case SubjectsName.Design:
                case SubjectsName.Programming:
                    ClassSubjectMenu.StartSubjectMenu(journalMarks, student, student.Subjects[number - 1], number - 1);
                    break;
                case SubjectsName.Back:
                    return;
                default:
                    WriteLine("Error iteam menu...");
                    break;
            }
            ReadKey();//пауза
        }

        /// <summary>
        /// метод запускает меню студента
        /// </summary>
        /// <param name="student"></param>
        public static void StartStudentMenu(IJournalMarks journalMarks, IStudent student)
        {
            do
            {
                Clear();

                int number = 0;
                string data = null;

                WriteLine("       Student menu: ");
                WriteLine((int)MenuStudent.ChoiceSubject + " - Choice subject,");
                WriteLine((int)MenuStudent.BackMenu + " - Back,");
                do
                {
                    Write("Your choice: ");
                    data = ReadLine();
                } while (!int.TryParse(data, out number));
                WriteLine("--------------------------------");

                Student newStudent = student as Student;

                switch ((MenuStudent)number)
                {
                    case MenuStudent.ChoiceSubject:
                        StudentMenu.ChoiceSubject(journalMarks, student);
                        break;
                    case MenuStudent.BackMenu:
                        JournalMenu.StartMenuJournal(journalMarks);
                        break;
                    default:
                        WriteLine("Error iteam menu...");
                        break;
                }
                WriteLine("Done!");
                ReadKey();//пауза
                Clear();
            } while (true);
        }
    }
}