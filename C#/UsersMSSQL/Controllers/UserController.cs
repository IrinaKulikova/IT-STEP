using System;
using System.Collections.Generic;

namespace UsersMSSQL
{
    internal class UserController : IController
    {
        private static readonly IRepository<User> repositoryUser = new RepositoryUser();
        private static readonly RepositoryAccount repositoryAccount = new RepositoryAccount();
        static string name = "User";
        public string Name => name;
        public void Create()
        {
            var account = ConsoleUtilAccount.GetData();
            repositoryAccount.Add(account);
            Account lastInsertAccount = repositoryAccount.GetByLogin(account.Login);
            var user = ConsoleUtilUser.GetData();
            user.Account = lastInsertAccount;
            repositoryUser.Add(user);
        }

        public void Read()
        {
            ConsoleUtilUser.Show(repositoryUser.GetAll());
        }

        public void Update()
        {
            Read();
            int id = ConsoleUtilEntities.GetId();
            var user = ConsoleUtilUser.GetData();
            user.Id = id;
            repositoryUser.Update(user);
        }

        public void Delete()
        {
            Read();
            repositoryUser.Delete(ConsoleUtilEntities.GetId());
        }
    }
}
