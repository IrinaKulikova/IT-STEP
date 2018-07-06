using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateStudent
{
    /// <summary>
    /// исключения, связанные с оценками
    /// </summary>
    class MarkException:Exception
    {
        //конструктор
        public MarkException(string msg) : base(msg) { }
    }
}
