using System;
using System.Collections.Generic;

namespace UsersMSSQL
{
    internal class RoleController : IController
    {
        private static readonly IRepository<Role> repository = new RepositoryRole();
        static string name = "Role";

        public string Name => name;
        public void Create()
        {
            repository.Add(ConsoleUtilRole.GetData());
        }

        public void Read()
        {
            ConsoleUtilRole.Show(repository.GetAll());
        }

        public void Update()
        {
            Read();
            int id = ConsoleUtilEntities.GetId();
            var role = ConsoleUtilRole.GetData();
            role.Id = id;
            repository.Update(role);
        }

        public void Delete()
        {
            Read();
            repository.Delete(ConsoleUtilEntities.GetId());
        }
    }
}
