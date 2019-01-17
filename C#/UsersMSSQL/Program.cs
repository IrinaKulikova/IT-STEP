using System;
using System.Data.SqlClient;
using System.IO;
using Microsoft.Extensions.Configuration;

namespace UsersMSSQL
{
    /**
     * Создать базу данных "Пользователи"
            Создать набор таблиц для хранения основной информации 
            о пользователе(Имя, Фамилия, Отчество, Адрес, Телефон, Эл.Почта) 
            о его уч.записи(Логин, Пароль) 
            и роли для уч.записей(Название), 
            
            установить связи:
            У аккаунта есть роль
            У пользователя есть аккаунт
            
            В проекте на C# реализовать простейшее консольное приложение по работе с данными этой базы данных, в виде меню
            1.Роли
            	1.1.Просмотр
            	1.2.Создание
            	1.3.Изменение
            	1.4.Удаление
            
            1.Уч.записи(аккаунт)
            	1.1.Просмотр
            	1.2.Создание
            	1.3.Изменение
            	1.4.Удаление
            
            1.Пользователи
            	1.1.Просмотр
            	1.2.Создание
            	1.3.Изменение
            	1.4.Удаление*/
    public class Program
    {
        public static string ConnectionString { get; private set; }
        public static SqlConnection GetConnection() => new SqlConnection(ConnectionString);
        public static void ReadConfiguration() => ConnectionString = File.ReadAllText("appsettings.txt");
        static void Main(string[] args)
        {
            ReadConfiguration();
            MenuEntities.Start();
            Console.ReadKey();
        }
    }
}
