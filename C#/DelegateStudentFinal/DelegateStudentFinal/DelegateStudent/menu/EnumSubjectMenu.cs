using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DelegateStudent
{
    /// <summary>
    /// перечисление пунктов меню предмета
    /// </summary>
    public enum SubjectMenu
    {
        /// <summary>
        /// посмотреть оценки
        /// </summary>
        ShowMarks = 1,

        /// <summary>
        /// добавить оценку
        /// </summary>
        AddMark,

        /// <summary>
        /// исправить оценку
        /// </summary>
        CorrectMark,

        /// <summary>
        /// удалить оценку
        /// </summary>
        DelMark,

        /// <summary>
        /// вернуться в предидущее меню
        /// </summary>
        BackMenu
    }
}