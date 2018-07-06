drop  database if exists javaacademy;

create database if not exists javaacademy
	default character set utf8
    collate utf8_general_ci;

use javaacademy;

CREATE TABLE if not exists `group`
(
  id int(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
	name varchar(255)
);

CREATE TABLE if not exists student
(
    id int(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
    first_name varchar(255),
    last_name varchar(255),
    age int(11),    
    group_id int,
	  constraint fk_group_id
		foreign key(group_id)
		references `group` (id)
			on update set null
			on delete set null
);

INSERT INTO `group` (name) VALUES ('СТУ-16О-1'),('СПУ-16П-1');
INSERT INTO student (first_name, last_name, age, group_id) VALUES ('Вася', 'Пупкин', 23,1),
																  ('Маша','Петрова',26,2),('Инна','Иванова',18,1);