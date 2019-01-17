using System;
using static System.Console;


namespace UsersMSSQL
{
    public delegate void Foo();
    internal static class MenuCRUD
    {
        internal static void Start(IController controller)
        {
            int menuCRUD = 0;
            var items = Enum.GetValues(typeof(MenuCRUDEnum));
            do
            {
                Clear();
                WriteLine(controller.Name + " CRUD Menu: ");
                foreach (MenuCRUDEnum itemCRUD in items)
                {
                    WriteLine(itemCRUD + " " + (int)itemCRUD);
                }
                string answer = "";
                do
                {
                    Write("You should choose menu item: ");
                    answer = ReadLine();
                } while (!int.TryParse(answer, out menuCRUD));
                menuCRUD = int.Parse(answer);
            } while (menuCRUD < 0 || menuCRUD > items.Length - 1);

            switch (menuCRUD)
            {
                case (int)MenuCRUDEnum.CREATE:
                    controller.Create();
                    break;
                case (int)MenuCRUDEnum.READ:
                    controller.Read();
                    break;
                case (int)MenuCRUDEnum.UPDATE:
                    controller.Update();
                    break;
                case (int)MenuCRUDEnum.DELETE:
                    controller.Delete();
                    break;
                case (int)MenuCRUDEnum.BACK:
                    return;
                case (int)MenuCRUDEnum.EXIT:
                    if (ExitMenu.Start() == (int)ExitEnum.YES)
                    {
                        Environment.Exit(0);
                    }
                    break;
            }
            Start(controller);
        }
    }
}