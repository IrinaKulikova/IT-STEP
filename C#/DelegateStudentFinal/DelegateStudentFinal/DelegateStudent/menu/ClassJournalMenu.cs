using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;


namespace DelegateStudent
{
    /// <summary>
    /// класс взаимодействия с пользователем
    /// </summary>
    public static class JournalMenu
    {
        /// <summary>
        /// выбрать студента
        /// </summary>
        /// <param name="journalMarks"></param>
        public static void ChoiceStudent(IJournalMarks journalMarks)
        {
            WriteLine(journalMarks);

            string data = null;
            int number = 0;
            do
            {
                Write("Choice student: ");
                data = ReadLine();
            } while (!int.TryParse(data, out number) || number <= 0 || number > journalMarks.Count);

            StudentMenu.StartStudentMenu(journalMarks, journalMarks.Students[number - 1]);
        }

        /// <summary>
        /// показать всех студентов 
        /// </summary>
        /// <param name="journalMarks">журнал студентов</param>
        public static void ShowJournal(IJournalMarks journalMarks)
        {
            WriteLine(journalMarks);
        }

        /// <summary>
        /// метод запускает меню журнала
        /// </summary>
        /// <param name="journalMarks"></param>
        public static void StartMenuJournal(IJournalMarks journalMarks)
        {
            Clear();
            do
            {
                WriteLine("       Main menu:");
                WriteLine((int)MenuJournal.ShowJornal + " - Show all students,");
                WriteLine((int)MenuJournal.ChoiceStudent + " - Choice the student,");
                WriteLine((int)MenuJournal.Exit + " - Exit");

                string choice = null;
                int answer = 0;
                do
                {
                    Write("Your choice: ");
                    choice = ReadLine();
                } while (!int.TryParse(choice, out answer));
                WriteLine("--------------------------------");

                switch ((MenuJournal)answer)
                {
                    case MenuJournal.ShowJornal:
                        JournalMenu.ShowJournal(journalMarks);
                        break;
                    case MenuJournal.ChoiceStudent:
                        JournalMenu.ChoiceStudent(journalMarks);
                        break;
                    case MenuJournal.Exit:
                        Environment.Exit(0);
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