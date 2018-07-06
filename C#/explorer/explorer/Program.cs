using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

/*видео: https://youtu.be/mLhHmcVOEwc

Реализовать программу - аналог проводника. 
Использовать TreeView для отображения структуры директорий и файлов 
на всех дисках в системе.
Отображать разные иконки для папок и файлов.
Двойной клик по файлу приводит к отркытию этого файла.
Реализовать "ленивую загрузку" файлов и папок для текущего узла.

 видео: https://youtu.be/j_Gy0Ios4U8

В продолжении домашнего задания.
В дополнении к TreeView в проводник добавить ListView с возможностью
изменить вид отображения ListView, перехода по папкам, открытия файлов,
копирования файлов через DragNDrop с рабочего стола.*/

namespace explorer
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
