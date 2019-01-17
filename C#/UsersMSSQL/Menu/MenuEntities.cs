using System;
using static System.Console;

namespace UsersMSSQL
{

    public static class MenuEntities
    {
        public static void Start()
        {
            int entityMenu = 0;
            var items = Enum.GetValues(typeof(MenuEntitiesEnum));
            do
            {
                Clear();
                WriteLine("Main menu:");
                foreach (MenuEntitiesEnum entity in items)
                {
                    WriteLine(entity + " " + (int)entity);
                }
                string answer = "";
                do
                {
                    Write("You should choose menu item: ");
                    answer = ReadLine();
                } while (!int.TryParse(answer, out entityMenu));
                entityMenu = int.Parse(answer);
            } while (entityMenu < 0 || entityMenu > items.Length - 1);
            switch (entityMenu)
            {
                case (int)MenuEntitiesEnum.ROLES:
                    MenuCRUD.Start(new RoleController());
                    break;
                case (int)MenuEntitiesEnum.USERS:
                    MenuCRUD.Start(new UserController());
                    break;
                case (int)MenuEntitiesEnum.ACCOUNTS:
                    MenuCRUD.Start(new AccountController());
                    break;
                case (int)MenuEntitiesEnum.EXIT:
                    if (ExitMenu.Start() == (int)ExitEnum.YES)
                    {
                        Environment.Exit(0);
                    }
                    break;
            }
            Start();
        }
    }
}