using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Data.SqlClient;

namespace UsersMSSQL
{

    interface IRepository<T> where T : class
    {
        IList<T> GetAll();
        int Add(T item);
        int Update(T item);
        int Delete(int id);
    }
}