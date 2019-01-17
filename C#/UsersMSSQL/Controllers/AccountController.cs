using System;
using System.Collections.Generic;

namespace UsersMSSQL
{
    internal class AccountController : IController
    {
        private static readonly IRepository<Account> repository = new RepositoryAccount();
        static string name = "Account";

        public string Name => name;

        public void Create()
        {
            repository.Add(ConsoleUtilAccount.GetData());
        }

        public void Read()
        {
            ConsoleUtilAccount.Show(repository.GetAll());
        }

        public void Update()
        {
            Read();
            int id = ConsoleUtilEntities.GetId();
            var account = ConsoleUtilAccount.GetData();
            account.Id = id;
            repository.Update(account);
        }

        public void Delete()
        {
            Read();
            repository.Delete(ConsoleUtilEntities.GetId());
        }
    }
}
