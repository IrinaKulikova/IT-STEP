using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;


namespace DelegateStudent
{
    /// <summary>
    /// меню предмет
    /// </summary>
    public static class ClassSubjectMenu
    {
        /// <summary>
        /// посмотреть оцентки
        /// </summary>
        /// <param name="subject"></param>
        public static void ShowMarks(ISubject subject)
        {
            WriteLine(subject);
        }

        /// <summary>
        /// ввод данных
        /// </summary>
        /// <param name="text">текст в консоле</param>
        /// <returns>полученные данные</returns>
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

        /// <summary>
        /// добавить оценку
        /// </summary>
        /// <param name="subject"></param>
        public static void AddMark(IStudent student, ISubject subject, int i)
        {
            //минимальное количество оценок для вызова делегата-80%
            int minCountMarks = subject.Marks.Length * 80 / 100;

            int mark = EnterData("Enter mark: ");
            try
            {
                subject.AddMark(mark);
            }
            catch (MarkException exception)
            {
                WriteLine(exception.Message);
            }

            //вызов делегатов
            if (subject.Count >= minCountMarks)
            {
                student.Subjects[i].MarkSubjects?.Invoke(subject);
                student.Subjects[i].StudentGoNext?.Invoke(subject);
            }
        }

        /// <summary>
        /// изменить оценку
        /// </summary>
        /// <param name="subject"></param>
        public static void CorrectMark(ISubject subject)
        {
            ShowMarks(subject);
            if (subject.Count == 0)
            {
                return;
            }
            int index = EnterData("Choice mark to correct(index): ");
            int mark = EnterData("Enter new mark: ");
            try
            {
                subject[index - 1] = mark;
            }
            catch (MarkException exception)
            {
                WriteLine(exception.Message);
            }
        }

        /// <summary>
        /// удалить оценку
        /// </summary>
        /// <param name="subject"></param>
        public static void DelMark(ISubject subject)
        {
            ShowMarks(subject);
            if (subject.Count == 0)
            {
                return;
            }
            int index = EnterData("Choice mark to delete(index): ");
            try
            {
                subject.DelMark(index - 1);
            }
            catch (MarkException exception)
            {
                WriteLine(exception.Message);
            }
        }

        /// <summary>
        /// метод запускает меню предмета
        /// </summary>
        /// <param name="student"></param>
        public static void StartSubjectMenu(IJournalMarks journalMarks, IStudent student, ISubject subject, int index)
        {
            Clear();//очищаем консоль
            do
            {
                WriteLine("       Subject menu:");
                WriteLine((int)SubjectMenu.ShowMarks + " - Show all  marks,");
                WriteLine((int)SubjectMenu.AddMark + " - Add mark,");
                WriteLine((int)SubjectMenu.CorrectMark + " - Correct mark,");
                WriteLine((int)SubjectMenu.DelMark + " - Delete mark,");
                WriteLine((int)SubjectMenu.BackMenu + " - Back");

                string choice = null;
                int answer = 0;
                do
                {
                    Write("Your choice: ");
                    choice = ReadLine();
                } while (!int.TryParse(choice, out answer));
                WriteLine("--------------------------------");

                switch ((SubjectMenu)answer)
                {
                    case SubjectMenu.ShowMarks:
                        ClassSubjectMenu.ShowMarks(subject);
                        break;
                    case SubjectMenu.AddMark:
                        ClassSubjectMenu.AddMark(student, subject, index);
                        break;
                    case SubjectMenu.CorrectMark:
                        ClassSubjectMenu.CorrectMark(subject);
                        break;
                    case SubjectMenu.DelMark:
                        ClassSubjectMenu.DelMark(subject);
                        break;
                    case SubjectMenu.BackMenu:
                        StudentMenu.StartStudentMenu(journalMarks, student);
                        break;
                    default:
                        WriteLine("Error iteam menu...");
                        break;
                }
                WriteLine("Done!");
                ReadKey();//пауза
                Clear();//очистка консоли
            } while (true);
        }
    }
}

