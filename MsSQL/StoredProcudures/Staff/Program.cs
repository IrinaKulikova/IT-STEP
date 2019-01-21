using System;
using static System.Console;

namespace Staff
{
    class Program
    {
        static void Main(string[] args)
        {
            ReaderConfiguration.DoConfigure();

            var employeesRepository = new EmployeesRepository();
            var positionsRepository = new PositionsRepository();

            InitDB(employeesRepository,positionsRepository);
            
            TestEmployeeProcedure(employeesRepository);
            TestPositionProcedure(positionsRepository);

            ReadKey();
        }

        private static void InitDB(EmployeesRepository employeesRepository, 
                                   PositionsRepository positionsRepository)
        {
             positionsRepository.Create(new Position
            {
                Name = "CEO"
            });
             positionsRepository.Create(new Position
            {
                Name = "CMO"
            });
             positionsRepository.Create(new Position
            {
                Name = "CTO"
            });
             positionsRepository.Create(new Position
            {
                Name = "CSO"
            });
            positionsRepository.Create(new Position
            {
                Name = "Programmer"
            });

            employeesRepository.Create(new Employee
            {
                Name = "Peter",
                Surname = "Semenov",
                Birth = new DateTime(1985, 2, 6),
                PositionId = 2,
                OrderStart = 66,
                OrderEnd = null,
                Image = "../../images/semenov.jpg"
            });

            employeesRepository.Create(new Employee
            {
                Name = "Vova",
                Surname = "Erisov",
                Birth = new DateTime(1985, 2, 6),
                PositionId = 1,
                OrderStart = 66,
                OrderEnd = null,
                Image = "../../images/erisov.jpg"
            });

            employeesRepository.Create(new Employee
            {
                Name = "Inna",
                Surname = "Semenova",
                Birth = new DateTime(1985, 2, 6),
                PositionId = 3,
                OrderStart = 66,
                OrderEnd = null,
                Image = "../../images/semenova.jpg"
            });

            employeesRepository.Create(new Employee
            {
                Name = "Kirill",
                Surname = "Titov",
                Birth = new DateTime(1990, 12, 26),
                PositionId = 4,
                OrderStart = 66,
                OrderEnd = null,
                Image = "../../images/titov.jpg"
            });
        }

        private static void TestPositionProcedure(PositionsRepository positionsRepository)
        {
            var list = positionsRepository.GetAll();
            WriteLine(String.Join('\n', list));

            Write(positionsRepository.GetById(2));
            Write(positionsRepository.GetById(3));
            var id = 8;
            var position = positionsRepository.GetById(id);
            Write(position == null ? $"There are not a position by id {id}\n" : position.ToString());

            positionsRepository.Create(new Position
            {
                Name = "Worker"
            });

            list = positionsRepository.GetAll();
            WriteLine(String.Join('\n', list));
            id = 5;
            position = positionsRepository.GetById(id);
            if (position != null)
            {
                position.Name = "CCO";
            }

            WriteLine(positionsRepository.GetById(id));
            positionsRepository.Delete(id);

            position = positionsRepository.GetById(id);
            Write(position == null ? $"There are not a position by id {id}\n" : position.ToString());
        }

        private static void TestEmployeeProcedure(EmployeesRepository employeesRepository)
        {
            var list = employeesRepository.GetAll();
            WriteLine(String.Join('\n', list));

            Write(employeesRepository.GetById(1));
            Write(employeesRepository.GetById(3));
            var id = 10;
            var employee = employeesRepository.GetById(id);
            Write(employee == null ? $"There are not an employee by id {id}\n" : employee.ToString());

            employeesRepository.Create(new Employee
            {
                Name = "Peter",
                Surname = "Semenov",
                Birth = new DateTime(1985, 2, 6),
                PositionId = 2,
                OrderStart = 66,
                OrderEnd = null,
                Image = "../../images/semenov.jpg"
            });

            list = employeesRepository.GetAll();
            WriteLine(String.Join('\n', list));
            id = 5;
            employee = employeesRepository.GetById(id);
            if (employee != null)
            {
                employee.Name = "Artem";
                employee.PositionId = 3;
                employeesRepository.Update(employee);
            }

            WriteLine(employeesRepository.GetById(id));
            employeesRepository.Delete(id);

            employee = employeesRepository.GetById(id);
            Write(employee == null ? $"There are not an employee by id {id}\n" : employee.ToString());
        }
    }
}
