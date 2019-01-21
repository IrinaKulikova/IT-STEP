
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

CREATE LOGIN [user_staff] WITH PASSWORD = 'UserStaff123';
GO

CREATE USER [user_staff] FOR LOGIN [user_staff] WITH DEFAULT_SCHEMA = [StaffHW]
GO

Grant INSERT, UPDATE, DELETE, SELECT ON Employees TO user_staff
Grant INSERT, UPDATE, DELETE, SELECT ON Positions TO user_staff
GO


---PROCEDURES INSERT---
GO
CREATE PROCEDURE AddEmployee @name NVARCHAR(100), 
							 @surname NVARCHAR(100), 
							 @birth NVARCHAR(100),
							 @position NVARCHAR(100),
							 @orderStart INT,
							 @orderEnd INT = NULL,
							 @image NVARCHAR(255) = NULL
							  
AS
BEGIN
	DECLARE @id int = -1;
	SELECT @id = [Id] FROM [Positions] WHERE [Name] = @position

	IF @id < 0
		BEGIN
			INSERT INTO [Positions] ([Name]) VALUES(@position)
			SELECT @id=IDENT_CURRENT('Positions')
		END

	INSERT INTO [Employees]([Name],[Surname],[Birth],[Position_ID],[OrderStart],[OrderEnd],[Image]) 
	VALUES (@name, @surname,@birth, @id, @orderStart, @orderEnd, @image )
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


EXEC AddPosition N'CFO'
EXEC AddPosition N'CMO'
EXEC AddEmployee @name = N'Vova',@surname =N'Eresov', @birth ='19960312 00:00:00.000', @position = N'CEO', @orderStart = 21, @orderEnd = 3621
EXEC AddEmployee @name=N'Inna',@surname=N'Khmelenko',@birth ='19901224 00:00:00.000', @position = N'CTO', @orderStart = 785
EXEC AddEmployee @name=N'Kolya', @surname=N'Titov',@birth = '19860324 00:00:00.000', @position=N'director',@orderStart = 786, @image =  N'../../Images/titov.jpg'

--- PROCEDURE UPDATE-----

GO
CREATE PROCEDURE UpdateEmployee @id int,
							 @name NVARCHAR(100), 
							 @surname NVARCHAR(100), 
							 @birth NVARCHAR(100),
							 @position NVARCHAR(100),
							 @orderStart INT,
							 @orderEnd INT = NULL,
							 @image NVARCHAR(255) = NULL
							  
AS
BEGIN
	DECLARE @Position_id int = -1;
	SELECT @Position_id = [Id] FROM [Positions] WHERE [Name] = @position

	IF @Position_id < 0
		BEGIN
			INSERT INTO [Positions] ([Name]) VALUES(@position)
			SELECT @Position_id = IDENT_CURRENT('Positions')
		END

	UPDATE [Employees] SET [Name] = @name ,[Surname] = @surname , [Birth] = @birth, [Position_ID] = @Position_id ,
	 [OrderStart] = @orderStart, [OrderEnd] = @orderEnd, [Image] = @image WHERE [Id] = @id
END
GO

EXEC UpdateEmployee @id = 2, @name = N'Kolya', @surname = N'Titov', @birth = '1986-03-24 00:00:00.000',
					@position = N'CMO', @orderStart = 786, @image = N'../../Images/titov1.jpg'

EXEC UpdateEmployee @id = 2, @name = N'Fedor', @surname = N'Titov', @birth = '1986-03-24 00:00:00.000',
					@position = N'CMO', @orderStart = 786, @image = N'../../Images/titov1.jpg'


EXEC UpdateEmployee @id = 2, @name = N'Fedor', @surname = N'Titorenko', @birth = '1986-03-24 00:00:00.000',
					@position = N'CMO', @orderStart = 786, @image = N'../../Images/titov1.jpg'

					
EXEC UpdateEmployee @id = 2, @name = N'Fedor', @surname = N'Titorenko', @birth = '1986-06-25 00:00:00.000',
					@position = N'CTO', @orderStart = 786, @image = N'../../Images/titorenko.jpg'


GO

CREATE PROCEDURE UpdatePosition @id int,
							 @name NVARCHAR(100)							  
AS
BEGIN
	UPDATE [Positions] SET [Name] = @name  WHERE [Id] = @id
END
GO

EXEC UpdatePosition @id = 5621, @name = N'name'
EXEC UpdatePosition @id = 1, @name = N'CISO'
EXEC UpdatePosition @id = 5, @name = N'CFO'

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

EXEC DeleteEmployee @id = 1
EXEC DeletePosition @id = 1
EXEC DeletePosition @id = 5

---PROCEDURES SELECT ALL---

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

EXEC GetEmployees
EXEC GetPositions


---PROCEDURES SELECT BY ID---

GO
CREATE PROCEDURE GetEmployeeById @id int						  
AS
BEGIN
	SELECT * FROM [Employees] WHERE [Id] = id
END
GO

GO
CREATE PROCEDURE GetPositionsById	 @id int						  
AS
BEGIN
	SELECT * FROM [Positions] WHERE [Id] = id
END
GO