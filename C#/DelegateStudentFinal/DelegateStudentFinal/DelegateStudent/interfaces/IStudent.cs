using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateStudent
{
    /// <summary>
    /// интерфейс студент
    /// </summary>
    public interface IStudent
    {
        /// <summary>
        /// имя
        /// </summary>
        string Name { get; set; }

        /// <summary>
        /// возраст
        /// </summary>
        int Age { get; set; }

        /// <summary>
        /// номер телефона
        /// </summary>
        string PhoneNumber { get; set; }

        /// <summary>
        /// ссылка на предметы
        /// </summary>
        Subject[] Subjects { get; set; }
    }
}