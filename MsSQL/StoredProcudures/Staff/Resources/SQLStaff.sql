
/* Разработать базу данных для автоматизации учёта сотрудников в отделе кадров предприятия.
        1. База должна содержать информацию о сотруднике: 
            имя,
            фамилия,
            дата рождения, 
            должность, 
            номер приказа о приёме на работу,
            номер приказа об увольнении, 
            фотография сотрудника.
        2. Доступ к данным должен быть сделан через хранимые процедуры.
        3. Необходимо ограничить доступ к данным путем раздачи прав пользователям системы.*/

IF NOT EXISTS (SELECT * FROM [master].[dbo].[sysdatabases] WHERE name = 'StaffHW') 
BEGIN 
CREATE DATABASE [StaffHW] 
END

GO
USE StaffHW


IF NOT EXISTS ( SELECT * FROM INFORMATION_SCHEMA.TABLES T
WHERE T.TABLE_SCHEMA = 'dbo'
AND T.TABLE_NAME = 'StaffHW')
BEGIN
CREATE TABLE [Positions](
	[Id] INT IDENTITY PRIMARY KEY,
	[Name] NVARCHAR(255) UNIQUE NOT NULL
)

CREATE TABLE [Employees](
	[Id] INT IDENTITY PRIMARY KEY,
	[Name] NVARCHAR(100) NOT NULL,
	[Surname] NVARCHAR(100) NOT NULL,
	[Birth] DATETIME NOT NULL, 
	[Position_ID] INT,
	[OrderStart] INT NOT NULL,
	[OrderEnd] INT,
	[Image] NVARCHAR(255)
	CONSTRAINT FK_Position_ID_Employees
		FOREIGN KEY  (Position_ID)
		REFERENCES Positions(Id) 
		ON DELETE SET NULL
		ON UPDATE CASCADE
)
END
GO

---PROCEDURES INSERT---
GO
CREATE PROCEDURE AddEmployee @name NVARCHAR(100), 
							 @surname NVARCHAR(100), 
							 @birth NVARCHAR(100),
							 @position INT,
							 @orderStart INT,
							 @orderEnd INT = NULL,
							 @image NVARCHAR(255) = NULL
							  
AS
BEGIN
	INSERT INTO [Employees]([Name],[Surname],[Birth],[Position_ID],[OrderStart],[OrderEnd],[Image]) 
	VALUES (@name, @surname,@birth, @position, @orderStart, @orderEnd, @image )
END
GO

CREATE PROCEDURE AddPosition @name NVARCHAR(100)							  
AS
BEGIN
	DECLARE @id int = -1;
	SELECT @id = [Id] FROM [Positions] WHERE [Name] = @name

	IF @id < 0
		BEGIN
			INSERT INTO [Positions] ([Name]) VALUES(@name)
		END
END
GO


--- PROCEDURE UPDATE-----

GO
CREATE PROCEDURE UpdateEmployee @id int,
							 @name NVARCHAR(100), 
							 @surname NVARCHAR(100), 
							 @birth NVARCHAR(100),
							 @position INT,
							 @orderStart INT,
							 @orderEnd INT = NULL,
							 @image NVARCHAR(255) = NULL
							  
AS
BEGIN

	UPDATE [Employees] SET [Name] = @name ,[Surname] = @surname , [Birth] = @birth, [Position_ID] = @position ,
	 [OrderStart] = @orderStart, [OrderEnd] = @orderEnd, [Image] = @image WHERE [Id] = @id
END
GO


CREATE PROCEDURE UpdatePosition @id int,
							 @name NVARCHAR(100)							  
AS
BEGIN
	UPDATE [Positions] SET [Name] = @name  WHERE [Id] = @id
END

-----------PROCEDURE DELETE---------

GO
CREATE PROCEDURE DeleteEmployee @id int							  
AS
BEGIN
	DELETE [Employees] WHERE [Id] = @id
END
GO

CREATE PROCEDURE DeletePosition @id int							  
AS
BEGIN
	DELETE [Positions] WHERE [Id] = @id
END
GO

GO
CREATE PROCEDURE GetEmployees							  
AS
BEGIN
	SELECT * FROM [Employees]
END
GO

GO
CREATE PROCEDURE GetPositions 							  
AS
BEGIN
	SELECT * FROM [Positions]
END
GO

---PROCEDURES SELECT BY ID---

GO
CREATE PROCEDURE GetEmployeeById @EmployeeId int					  
AS
BEGIN
	SELECT * FROM [Employees] WHERE [Id] = @EmployeeId
END
GO


GO
CREATE PROCEDURE GetPositionById @PositionId int						  
AS
BEGIN
	SELECT * FROM [Positions] WHERE [Id] = @PositionId
END
GO


CREATE LOGIN [user_staff] WITH PASSWORD = 'UserStaff123';
GO

CREATE USER [user_staff] FOR LOGIN [user_staff] WITH DEFAULT_SCHEMA = [StaffHW]
GO

Grant INSERT, UPDATE, DELETE, SELECT ON Employees TO user_staff
Grant INSERT, UPDATE, DELETE, SELECT ON Positions TO user_staff
GO


GRANT EXECUTE ON [StaffHW].[dbo].[AddEmployee] TO user_staff
GRANT EXECUTE ON [StaffHW].[dbo].[AddPosition] TO user_staff
GRANT EXECUTE ON [StaffHW].[dbo].[DeleteEmployee] TO user_staff
GRANT EXECUTE ON [StaffHW].[dbo].[DeletePosition] TO user_staff
GRANT EXECUTE ON [StaffHW].[dbo].[GetEmployees] TO user_staff
GRANT EXECUTE ON [StaffHW].[dbo].[GetEmployeeById] TO user_staff
GRANT EXECUTE ON [StaffHW].[dbo].[GetPositionById] TO user_staff
GRANT EXECUTE ON [StaffHW].[dbo].[GetPositions] TO user_staff
GRANT EXECUTE ON [StaffHW].[dbo].[UpdateEmployee] TO user_staff
GRANT EXECUTE ON [StaffHW].[dbo].[UpdatePosition] TO user_staff

