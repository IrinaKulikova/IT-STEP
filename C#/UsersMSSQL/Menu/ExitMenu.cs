using System;
using static System.Console;

namespace UsersMSSQL
{
    static class ExitMenu
    {
        internal static int Start()
        {
            string exit = "";
            int exitItem = 0;
            var items = Enum.GetValues(typeof(ExitEnum));
            do
            {
                do
                {
                    WriteLine("Are you sure?");
                    foreach (ExitEnum exitEnum in items)
                    {
                        WriteLine(exitEnum + " - " + (int)exitEnum);
                    }
                    exit = ReadLine();
                } while (!int.TryParse(exit, out exitItem));
                exitItem = int.Parse(exit);
            } while (exitItem != (int)ExitEnum.YES && exitItem != (int)ExitEnum.NO);

            return exitItem;
        }
    }
}