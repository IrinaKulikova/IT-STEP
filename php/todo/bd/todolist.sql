drop database if exists todo;

create database if not exists todo 
			default character set utf8
				collate utf8_general_ci;

use todo;

create table tasks
(
	id int primary key auto_increment,
    title varchar(255) not null,
    status ENUM('true','false') default 'false'
);

insert into tasks (title,status) values('купить тетрадь', 'false'),('позвонить бабушке','true');