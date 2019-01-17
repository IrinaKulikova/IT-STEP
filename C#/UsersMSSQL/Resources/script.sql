--CREATE DATABASE UsersMSSQL
--GO

USE UsersMSSQL
GO

CREATE TABLE [Role]
(
	[Id] INT IDENTITY PRIMARY KEY,
	[Name] NVARCHAR(255) UNIQUE NOT NULL
)


CREATE TABLE [Account]
(
	[Id] INT IDENTITY PRIMARY KEY,
	[Login] NVARCHAR(255) UNIQUE NOT NULL,
	[Password] NVARCHAR(255) NOT NULL,
	[RoleId] INT NOT NULL,
		CONSTRAINT FK_RoleId_Account 
		FOREIGN KEY (RoleId)
		REFERENCES [Role](Id) 
			ON DELETE CASCADE
			ON UPDATE CASCADE
)

CREATE TABLE [User]
(
	[Id] INT IDENTITY PRIMARY KEY,
	[Name] NVARCHAR(255) NOT NULL,
	[SecondName] NVARCHAR(255) NOT NULL,
	[LastName] NVARCHAR(255) NOT NULL,
	[Phone] NVARCHAR(255),
    [Address] NVARCHAR(255),
	[EMail] NVARCHAR(255) UNIQUE NOT NULL,
	[AccountId] INT UNIQUE NOT NULL,
		CONSTRAINT FK_AccountId_User 
		FOREIGN KEY (AccountId)
		REFERENCES Account(Id) 
			ON DELETE CASCADE
			ON UPDATE CASCADE
)

GO

INSERT INTO [Role]([Name]) VALUES('Admin'),('User')
INSERT INTO Account([Login], [Password], [RoleId]) VALUES('ADMIN','ADMIN',1),('USER','USER',2),('STUDENT','STUDENT',2)
INSERT INTO [User]([Name],[SecondName],[LastName], [Phone], [Address], [EMail], [AccountId])
	VALUES('KOLYA','SERGEEVICH','KKUSCH','+380630987412','DNIPRO','KOLYA@GMAIL.COM',1),
		('MASHA','PETROVNA','IVANOVA','+380996662211','KIYV','MASHAA@GMAIL.COM',2),
		('INNA','VLADIMIROVNA','KHMELENKO','+380973336699','ODESSA','INNA@GMAIL.COM',3)
GO

/*
DROP TABLE [User]
DROP TABLE Account
DROP TABLE [Role]
*/


SELECT * FROM Account
SELECT * FROM Account as a join Role as r on a.RoleId = r.Id
SELECT a.Id, a.Login, a.Password, r.Id, r.Name FROM Account as a join Role as r on a.RoleId = r.Id

INSERT INTO Role([Name]) VALUES('SYSTEM')
SELECT u.Id,  u.Name , u.SecondName, u.LastName, u.Phone, u.Email , a.Id , a.Login, a.Password , r.Id, r.Name FROM [User] u INNER JOIN [Account] a ON u.AccountId=a.Id INNER JOIN [Role] as r ON a.RoleId = r.Id 

--INSERT INTO [User]([Name] , [SecondName] , [LastName] ,[Phone] , [Email] , [AccountId]) VALUES ('Name', 'item.SecondName', 'LastName', 'Phone', 'Email', 1)

--DELETE FROM [Role] WHERE [Id] = 2
