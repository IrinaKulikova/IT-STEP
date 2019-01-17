using System;
using System.Collections.Generic;

namespace UsersMSSQL
{
    interface IController
    {
        string Name { get; }
        void Create();
        void Read();
        void Update();
        void Delete();
    }
}
