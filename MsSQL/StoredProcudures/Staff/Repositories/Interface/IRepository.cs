using System;
using System.Collections.Generic;

namespace Staff
{
    public interface IRepository<T> where T : class
    {
        IList<T> GetAll();
        T GetById(int id);
        int Create(T entity);
        int Update(T entity);
        int Delete(int id);
    }
}