using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateStudent
{
    /// <summary>
    /// класс предмет
    /// </summary>
    public class Subject : ISubject
    {

        /// <summary>
        /// делегаты, информирующие о среднем бале у студента по всем предметам
        /// </summary>
        public MarkDlg MarkSubjects { get; set; }

        /// <summary>
        /// делегаты информеры, переходит студент на следующий курс или нет 
        /// </summary>
        public StudentGoNextDlg StudentGoNext { get; set; }
        
        /// <summary>
        /// максимальная оценка по предмету
        /// </summary>
        public const int MAXMARK = 12;

        /// <summary>
        /// минимальная оценка по предмету
        /// </summary>
        public const int MINMARK = 1;

        /// <summary>
        /// проходной бал по предмету
        /// </summary>
        public const int PASSMARK = 4;
        
        /// <summary>
        /// минимальное количество сделалых домашних заданий
        /// </summary>
        const int MINMARKCOUNT = 8;

        /// <summary>
        /// название предмета
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// количество добавленных оценок
        /// </summary>
        public int Count { get; private set; }

        /// <summary>
        /// массив оценок
        /// </summary>
        public int[] Marks { get; private set; }

        /// <summary>
        /// переведен ли студен на следующий курс
        /// </summary>
        public bool goToNextCourse;

        /// <summary>
        /// средняя оценка
        /// </summary>
        public int MiddleMark
        {
            get
            {
                int mark = 0;
                for (int i = 0; i < Count; i++)
                {
                    mark += Marks[i];
                }
                if (mark > 0)
                {
                    mark /= Count;
                }
                return mark;
            }
        }

        /// <summary>
        /// размер массива по умолчанию
        /// </summary>
        private int _size = 10;

        /// <summary>
        /// перегруженный индексатор
        /// </summary>
        /// <param name="index">индекс оценки</param>
        /// <returns>оценка</returns>
        public int this[int index]
        {
            get => Marks[index];
            set
            {
                if (index >= 0 && index < Count)
                {
                    Marks[index] = value;
                }
                else
                {
                    throw new MarkException("The mark is absent!");
                }
            }
        }

        /// <summary>
        /// констрктор с заданными параметрами
        /// </summary>
        /// <param name="name">название предмета</param>
        public Subject(string name)
        {
            goToNextCourse = false;
            Name = name;
            Marks = new int[_size];
            Count = 0;
        }

        /// <summary>
        /// свойство экзамен сдан
        /// </summary>
        public bool SubjectPassed
        {
            get
            {
                if (Count >= MINMARKCOUNT && MiddleMark >= PASSMARK)
                {
                    return true;
                }
                return false;
            }
        }

        /// <summary>
        /// метод добавления оценки
        /// </summary>
        /// <param name="mark"></param>
        public void AddMark(int mark)
        {
            if (mark < MINMARK || mark > MAXMARK)
            {
                throw new MarkException("Error: invalid mark!");
            }

            if (Count < Marks.Length)
            {
                Marks[Count++] = mark;
            }
            else
            {
                throw new MarkException("Error: the marks journal is overcrowded!");
            }
        }

        /// <summary>
        /// удалить оценку
        /// </summary>
        /// <param name="index"></param>
        public void DelMark(int index)
        {
            if (index < 0 || index >= Count)
            {
                throw new MarkException("Error: the marks is absent!");
            }

            for (int i = index; i < Count - 1; i++)
            {
                Marks.SetValue(Marks[i + 1], i);
            }
            //уменьшакм счётчик
            Count--;
        }

        /// <summary>
        /// получить информацию о предмете
        /// </summary>
        /// <returns>строка- массив оценок</returns>
        public override string ToString()
        {
            string data = Name;
            data += ": \n";
            if (Count == 0)
            {
                data += " anyone mark...";
            }
            for (int i = 0; i < Count; i++)
            {
                data += $"{i + 1}.)";
                data += Marks[i];
                data += ",  ";
            }
            return data;
        }
    }
}
