using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace FileSystem
{
    /// <summary>
    /// класс создаёт бэкапы
    /// </summary>    
    public class BackUper
    {
        /// <summary>
        /// путь к папке, которую проверяем
        /// </summary>
        public string Path { get; set; }

        /// <summary>
        /// папка в которой создаём архив
        /// </summary>
        public string PathForCreateDirectoryArchive { get; set; }

        /// <summary>
        /// путь к архиву
        /// </summary>
        public string PathArhive
        {
            get
            {
                return PathForCreateDirectoryArchive + nameArhive + "\\";
            }
        }

        /// <summary>
        /// дата для поиска
        /// </summary>
        public DateTime SearchDate { get; set; }

        /// <summary>
        /// имя архива
        /// </summary>
        public string nameArhive = "BackUpApplication";

        //имя логфайла
        public static string nameLog = "log.txt";


        /// <summary>
        /// путь к лог-файлу
        /// </summary>
        public string PathLogFile
        {
            get
            {
                return PathArhive + nameLog;
            }
        }

        /// <summary>
        /// метод переименовывает фаил
        /// </summary>
        /// <param name="newName">новое имя</param>
        /// <param name="directoryArhive"></param>
        private StringBuilder RenameFile(StringBuilder newName)
        {
            //находим индекс последней точки с конца
            int index = newName.ToString().LastIndexOf(".");

            //отметка копированной строки 
            string copy = "--copy";

            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append(newName.ToString(), 0, index);

            //если имя содержит "++copy"
            if (stringBuilder.ToString().Contains(copy))
            {
                //находим индекс последней открывающейся скобки
                int first = newName.ToString().LastIndexOf("(");

                //находим индекс вхождения ++copy
                int indexCopy = newName.ToString().IndexOf(copy);

                //если имя не содержит скобок
                if (first < 0 || (first > 0 && first < indexCopy))
                {
                    int indexFirstCopy = 1;
                    newName.Insert(indexCopy + copy.Length, $"({indexFirstCopy})");
                }
                else
                {
                    //формируем строку
                    StringBuilder builder = new StringBuilder();

                    //индекс, соответствующий позиции начала числа номера копии
                    int i = first + 1;

                    //записываем в строку номер копии
                    while (newName.ToString()[i] != ')')
                    {
                        builder.Append(newName.ToString()[i++]);
                    }

                    //парсим полученную строку
                    int.TryParse(builder.ToString(), out int newNumberOfCopy);

                    //увеличиваем счётчик копии
                    newNumberOfCopy++;

                    //переписываем имя для копии
                    newName.Replace(builder.ToString(), newNumberOfCopy.ToString(), first + 1, newNumberOfCopy.ToString().Length);
                }
            }
            else
            {
                //формируем новое имя файла
                newName.Insert(index, copy);
            }
            return newName;
        }

        /// 
        /// <summary>
        /// метод проверяет, есть ли в папке фаил с таким иминем, если есть, переименовывает его
        /// </summary>
        /// <param name="nameFile">фаил который нужно скопировать</param>
        /// <param name="directoryArhive">архив куда копируем</param>
        /// <returns>новое имя файла</returns>
        private string CheckName(string nameFile)
        {
            //формируем строку
            StringBuilder newName = new StringBuilder();

            //вписываем в строку путь архива
            newName.Append(PathArhive);
            //newName.Append("\\");

            //дописываем имя файла
            newName.Append(nameFile);

            //переиминовываем пока в папке не найдемтся нового имени
            while (File.Exists(newName.ToString()))
            {
                newName = RenameFile(newName);
            }
            //возвращаем имя файла
            return newName.ToString();
        }


        //добавить в архив
        public static void AddToArchive()
        {
            //создаём объект архиватор
            BackUper backUper = DialogConsole.InstanceBackUper();

            try
            {
                //получаем папку с файлами для архивипрвания
                DirectoryInfo directoryRun = new DirectoryInfo(backUper.Path);

                //папка где создаём архив
                DirectoryInfo CurrentDirectory = new DirectoryInfo(backUper.PathForCreateDirectoryArchive);

                //создаём архив
                CurrentDirectory.CreateSubdirectory(backUper.nameArhive);

                //создаём в папке фаил логирования
                FileStream stream = new FileStream(backUper.PathLogFile, FileMode.OpenOrCreate, FileAccess.Read);
                stream.Close();

                //запускаем процес создания бэкапов
                backUper.BackUpData(directoryRun);
            }
            catch (System.IO.DirectoryNotFoundException exception)
            {
                Console.WriteLine(exception.Message);
            }
        }

        private static string SearchBackUpInfo(string data, string pattern, string fileOrig)
        {

            //\[(\d\d).(\d\d).(\d{2,4})\s(\d\d):(\d\d):(\d\d)\]\s(?<origFile>.+)\s->\s(?<archiveFile>.+)\b
            //[26.10.2017 11:53:19] D:\\kulikova\\pic\Безымянный.png -> D:\\BackUpApplication\Безымянный.png

            //получаем соответствие
            Match match = Regex.Match(data, pattern);

            //последняя копия записана в воследнюю очередь, перебираем все строки и запоминием те, где есть путь потеряного файла

            Match matchSearch = match;

            //перебираем все строки, запоминаем последнюю добавленную запись с копированием искомого файла
            while (match.Success)
            {
                if (match.Value.Contains(fileOrig))
                {
                    matchSearch = match;
                }

                //переходим к следующему
                match = match.NextMatch();
            }

            //возвращаем путь к архимному файлу
            return matchSearch.Groups["archiveFile"].Value;
        }

        //восстановить с архива
        public static void RestoreFromArchive()
        {
            //получаем информацию для архивирования
            BackUper backUper = DialogConsole.InstanceBackUper();

            try
            {
                using (Stream stream = new FileStream(backUper.PathLogFile, FileMode.Open, FileAccess.Read))
                {
                    using (StreamReader reader = new StreamReader(stream))
                    {
                        //считываем лог фаил
                        string data = reader.ReadToEnd();

                        //регулярное выражения записи резервного копирования файла
                        string pattern = @".*\s*(\d\d).(\d\d).(\d{2,4}).*]\s*(?<origFile>.+?)\s*->\s*(?<archiveFile>.+)\b";

                        bool s = Regex.IsMatch(data, pattern);
                        //если по регулярному выражению найдено хоть 1 соответствие
                        if (Regex.IsMatch(data, pattern))
                        {
                            //получаем соответствие
                            Match match = Regex.Match(data, pattern);

                            //повторяем пока попытки получения следующего удачные
                            while (match.Success)
                            {
                                //получаем путь к файлу оригиналу
                                string fileOriginalPath = match.Groups["origFile"].Value;

                                //если фаил отсутствует, будем его копировать из архивабэкапов
                                if (!File.Exists(fileOriginalPath))
                                {
                                    //ищим самый свежий бэкап в архиве
                                    string fileBackUpPath = SearchBackUpInfo(data, pattern, fileOriginalPath);
                                    File.Copy(fileBackUpPath, fileOriginalPath);
                                }
                                //переходим к следующему совпадению
                                match = match.NextMatch();
                            }
                        }
                    }
                }
            }
            catch (System.IO.DirectoryNotFoundException exception)
            {
                Console.WriteLine(exception.Message);
            }
        }


        /// <summary>
        /// рекурсивный обход папки
        /// </summary>
        /// <param name="directory">папка в которой перечисляем содержимое</param>
        /// <param name="directoryArhive">папка куда копируем найденные файлы</param>
        /// <param name="dateSearch">дата с которой нам нужно переписывать файлы</param>
        public void BackUpData(DirectoryInfo directory)
        {
            //цикл перебирает содержимое папки
            foreach (FileSystemInfo info in directory.GetFileSystemInfos())
            {
                if ((info.Attributes & FileAttributes.Directory) == FileAttributes.Directory)//если текущий элемент папки- папка
                {
                    Console.WriteLine($"dir: {info.Name}");//выводим имя

                    //получаем путь в внутренней папке
                    string NextDir = directory.FullName + info.Name;

                    //получаем данные о папке
                    DirectoryInfo newDir = new DirectoryInfo(NextDir);

                    //заходим в папку
                    BackUpData(newDir);//заходим в папку
                }
                else//если текущий элемент фаил
                {
                    DateTime dateTime = new DateTime();//создаём объект время создания файла
                    dateTime = info.CreationTime;//записываем в объект время создания файла и сравниваем время создания с рубежным.

                    //если фаил создан после указанной даты, копируем его
                    if (dateTime > SearchDate)
                    {
                        //проверяем, есть ли фаил с таким иминем в архиве, если есть, переименовываем его
                        string newChekedName = CheckName(info.Name);

                        //копируем фаил в архив
                        File.Copy(info.FullName, newChekedName);

                        //создаём поток
                        using (Stream stream = new FileStream(PathLogFile, FileMode.Append, FileAccess.Write))
                        {
                            using (StreamWriter writer = new StreamWriter(stream))
                            {
                                //получаем текущюю дату
                                DateTime timeNow = new DateTime();
                                timeNow = DateTime.Now;
                                writer.Write($"[{timeNow}] ");

                                //расположение исходного файла
                                writer.Write($"{directory}");
                                if (directory.FullName != Path)
                                {
                                    writer.Write($"\\");
                                }
                                writer.Write($"{info.Name}");

                                writer.Write($" -> ");
                                //расположение копии
                                writer.WriteLine($"{newChekedName}");
                            }
                        }
                    }
                    //выводим в консоль имя файла
                    Console.WriteLine($"file: {info.Name}");
                }
            }
        }
    }
}
