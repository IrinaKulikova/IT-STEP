drop database if exists users;

create database if not exists users 
			default character set utf8
				collate utf8_general_ci;

use users;

create table user
(
	id int primary key auto_increment,
    name varchar(255) not null,
    surname varchar(255) not null,
    email varchar(255),
    phone varchar(30),
    mobile_phone varchar(30),
    status ENUM('active','inactive') default 'active'
);

create table course
(
	id int primary key auto_increment,
    name varchar(255) not null
);

create table  user_course
(	
    id_user int,
		foreign key (id_user)
		references `user`(id)
			on delete set null
			on update set null,
	id_course int,
		foreign key (id_course)
		references course(id)
			on delete set null
			on update set null
);

insert into user(name,surname,email,phone,mobile_phone,status)
					values
                    ('Артур', 'Пирожков', 'pirajkov@gmail.com','+38(056)3719632','+38(096)3210000','active' ),
                    ('Илья', 'Тодоров', 'todorov@mail.com','+38(044)4785555','+38(097)3698745','inactive' ),
                    ('Валерия', 'Иванова', 'ivanova@mail.com','+38(044)3258741','+38(093)0550102','active' ),
					('Александр', 'Рыжов', 'alex@ua.com','+38(044)9831010','+38(092)1114477','inactive' ),
                    ('Мария', 'Петрова', 'petrova@mail.com','+38(044)7799661','+38(050)9852103','active' ),
                    ('Сеня', 'Федорец', 'fedorec@org.ua','+38(044)1239874','+38(022)3332211','active' ),
                    ('Пётр', 'Иванченко', 'ivanchenko@gmail.com','+38(056)8887744','+38(073)6165742','inactive' ),
                    ('Инна', 'Левченко', 'innalevchenko@owox.com','+38(042)7410296','+38(097)1690706','active' ),
                    ('Вячеслав', 'Лепетя', 'slava@mail.com','+38(056)2226644','+38(041)7458963','inactive' ),
                    ('Анастасия', 'Васильева', 'vasya@mail.com','+38(074)8882233','+38(066)4488993','active' ),
                    ('Юлия', 'Шпора', 'shpora@gmail.com','+38(0442)756665','+38(067)7459621','inactive' );
                    
insert into course (name) values('C++'),('C#'),('php'),('JavaScript'),('My SQL'),('HTML+CSS'),('MS SQL');

insert into user_course values(1,1),(1,6), (2,3),(2,4),(3,4),(3,7),
							  (4,2),(4,4),(5,4),(6,3),(6,4),(6,5),(7,4),
                              (7,6),(8,1),(8,7),(9,3),(10,2),(10,4),(10,6),
                              (10,7),(11,1),(11,9);