drop database if exists academy;

create database if not exists academy
	default character set utf8
    collate utf8_general_ci;
    
use academy;

create table if not exists groups
(
id int primary key auto_increment,
name varchar(50)
)engine=InnoDB;


create table if not exists courses
(
id int primary key auto_increment,
number int
)engine=InnoDB;


create table if not exists students
(
id int primary key auto_increment,
firstname varchar(50) not null,
secondname varchar(50),
lastname varchar(50) not null,
id_group int,
	constraint fk_id_group_students
		foreign key(id_group)
			references groups(id)
				on delete set null
				on update cascade,
id_course int,
	constraint fk_id_course_student
		foreign key (id_course)
			references courses(id)
				on delete set null
                on update cascade
)engine=InnoDB;


create table if not exists cities
(
id int primary key auto_increment,
name varchar(50)
)engine=InnoDB;

create table if not exists streets
(
id int primary key auto_increment,
name varchar(50)
)engine=InnoDB;


create table if not exists teachers
(
id int primary key auto_increment,
firstname varchar(50),
secondname varchar(50),
lastname varchar(50),
id_city int,
	constraint fk_id_city_teacher
		foreign key (id_city)
			references cities(id)
            on delete set null
            on update cascade,
id_street int,
	constraint fk_id_street_teacher
		foreign key (id_street)
			references streets(id)
            on delete set null
            on update cascade,
house varchar(10),
flat varchar(10),
maritalstatus enum('Y','N','-') default '-'
)engine=InnoDB;



create table if not exists phoneteacher
(
id_teacher int,
	constraint fk_id_teacher_phoneteacher
		foreign key(id_teacher)
			references teachers(id)
			on delete set null
            on update cascade,
phone varchar(20)
)engine=InnoDB;


create table if not exists subjects
(
id int primary key auto_increment,
name varchar(120) not null
)engine=InnoDB;


create table if not exists teachergroup
(
id_teacher int,
	constraint fk_id_teacher_teachergroup
		foreign key (id_teacher)
			references teachers(id)
            on delete set null
            on update cascade,
id_group int,
	constraint fk_id_group_teachergroup
		foreign key (id_group)
			references groups(id)
            on delete set null
            on update cascade
)engine=InnoDB;


create table if not exists studentattendance
(
id_student int,
	constraint fk_id_student_studentattendance
		foreign key (id_student)
			references students(id)
            on delete set null
            on update cascade, 
`day` date not null,
id_subject int,
	constraint fk_id_subject_studentattendance
		foreign key (id_subject)
			references subjects(id)
			on delete set null
            on update cascade,
attendance enum('Y','N') default 'N'
)engine=InnoDB;

create table if not exists marks
(
id int primary key auto_increment,
mark int
)engine=InnoDB;


create table if not exists studentacademicperformance
(
id_student int,
	constraint fk_id_student_studentacademicperformance
		foreign key (id_student)
			references students(id)
            on delete set null
            on update cascade,
id_subject int,
	constraint fk_id_subject_studentacademicperformance
		foreign key (id_subject)
			references subjects(id)
            on delete set null
            on update cascade,
id_mark int,
	CONSTRAINT fk_id_mark_studentacademicperformance
		foreign key (id_mark)
			references marks(id)
            on delete set null
            on update cascade
)engine=InnoDB;

create table if not exists directions
(
id int primary key auto_increment,
name varchar(50)
)engine=InnoDB;

create table if not exists directiongroup
(
id_direction int,
	constraint fk_id_direction_directiongroup
		foreign key (id_direction)
			references directions(id)
            on delete set null
            on update cascade,
id_group int,
	constraint fk_id_group_directiongroup
		foreign key (id_group)
			references groups(id)
            on delete set null
            on update cascade
)engine=InnoDB;

insert into marks(mark) values (1),(2),(3),(4),(5),(6),(7),(8),(9),(10),(11),(12);

insert into groups(name) values ('back-end'),
								('front-end'), 
                                ('full-stack'),
                                ('web графика'),
                                ('дизайн интерьеров');

insert into directions (name) values ('программисты'),('дизайнеры');

insert into directiongroup (id_direction, id_group) values(1,1),(1,2),(1,3),(2,4),(2,5);

insert into courses(number) values (1),(2),(3);

insert into cities(name) values ('Днепр'),
								('Новомосковск'),
                                ('Каменское');

insert into streets(name) values ('Пушкина'),
								('Чкалова'),
                                ('Гоголя'),
                                ('Яворницкого'),
                                ('Мониторная'),
                                ('Шелгунова');

insert into subjects(name) values ('Javascript'),
								  ('C#'),
                                  ('Php'),
                                  ('Java'),
                                  ('3d Max'),
                                  ('Векторная графика'),
                                  ('Разработка дизайна сайтов');

insert into students(firstname, secondname, lastname,id_group, id_course)
			values
            ('Николай','Владимирович','Ересов',1,2),
            ('Александр','Валерьевич','Петров',2,1),
            ('Элина','Петровна','Михайлова',4,3),
            ('Марина','Ивановна','Соковнина',5,1),
            ('Илья','Георгиевич','Юзиков',2,1),
            ('Ксенья','Николаевна','Федорец',3,3),
            ('Инна','Павловна','Левченко',2,1),
            ('Лариса','Александровна','Хмеленко',1,2),
            ('Максим','Спартакович','Зайцев',5,1),
            ('Мария','Абрамовна','Глазова',3,2),
            ('Сергей','Петрович','Иванов',1,1),
            ('Олег','Артурович','Сидоров',2,1);
 
 insert into teachers(firstname, secondname, lastname,id_city,id_street,house,flat,maritalstatus)
			values
            ('Павел','Петрович','Петров',1,2,'12а','6','Y'),
            ('Оксана','Владимировна','Кущ',2,3,'56д','147','N'),
            ('Евгений','Павлович','Нагиев',3,5,'163','47','Y'),
            ('Нина','Ивановна','Бондаренко',1,6,'96','57','N'),
            ('Татьяна','Владимировна','Белая',2,4,'28а','-','Y');

insert into teachergroup
			values
            (1,2),(3,1),(2,2),(1,3),(2,3),(3,2),(4,4),(5,5),(4,5),(5,4);


insert into phoneteacher(id_teacher,phone)
			values
            (1,'+380502147589'),
            (1,'+380973587896'),
            (2,'+380931111111'),
            (3,'+380630125478'),
            (4,'+380441477777'),
            (5,'+380672225911'),
            (5,'+380973698745');
            
insert into studentattendance
			values
            (1,'2017-02-26',4,'Y'),
            (1,'2017-02-26',1,'Y'),
			(1,'2017-02-27',4,'Y'),
            (1,'2017-02-27',1,'Y'),
			(1,'2017-02-28',4,'N'),
            (1,'2017-02-28',1,'Y'),
			(2,'2017-02-26',1,'Y'),
			(2,'2017-02-26',3,'Y'),
			(2,'2017-02-27',1,'N'),
			(2,'2017-02-27',3,'Y'),
            (2,'2017-02-28',1,'Y'),
			(2,'2017-02-28',3,'N'),
            (3,'2017-02-26',6,'N'),
			(3,'2017-02-26',7,'Y'),
			(3,'2017-02-27',6,'Y'),
			(3,'2017-02-27',7,'Y'),
            (3,'2017-02-28',6,'Y'),
			(3,'2017-02-28',7,'Y'),
            (4,'2017-02-26',6,'N'),
			(4,'2017-02-26',5,'Y'),
			(4,'2017-02-27',6,'N'),
			(4,'2017-02-27',5,'N'),
            (4,'2017-02-28',6,'Y'),
			(4,'2017-02-28',5,'Y'),
            (5,'2017-02-26',1,'Y'),
			(5,'2017-02-26',2,'Y'),
			(5,'2017-02-27',1,'Y'),
			(5,'2017-02-27',2,'Y'),
            (5,'2017-02-28',1,'Y'),
			(5,'2017-02-28',2,'Y'),
            (5,'2017-02-26',1,'Y'),
			(6,'2017-02-26',2,'Y'),
			(6,'2017-02-27',2,'N'),
			(6,'2017-02-27',2,'Y'),
            (6,'2017-02-28',2,'Y'),
			(6,'2017-02-28',2,'Y'),
            (7,'2017-02-26',3,'Y'),
			(7,'2017-02-26',3,'Y'),
			(7,'2017-02-27',3,'N'),
			(7,'2017-02-27',3,'Y'),
            (7,'2017-02-28',3,'Y'),
			(7,'2017-02-28',3,'Y'),
            (8,'2017-02-26',1,'Y'),
			(8,'2017-02-26',1,'Y'),
			(8,'2017-02-27',1,'Y'),
			(8,'2017-02-27',1,'Y'),
            (8,'2017-02-28',1,'Y'),
			(8,'2017-02-28',1,'Y'),
            (9,'2017-02-26',6,'Y'),
			(9,'2017-02-26',7,'Y'),
			(9,'2017-02-27',6,'Y'),
			(9,'2017-02-27',7,'Y'),
            (9,'2017-02-28',6,'Y'),
			(9,'2017-02-28',7,'Y'),
            (10,'2017-02-26',2,'Y'),
			(10,'2017-02-26',2,'Y'),
			(10,'2017-02-27',2,'N'),
			(10,'2017-02-27',2,'Y'),
            (10,'2017-02-28',2,'Y'),
			(10,'2017-02-28',2,'Y'),
            (11,'2017-02-26',3,'Y'),
			(11,'2017-02-26',4,'Y'),
			(11,'2017-02-27',3,'Y'),
			(11,'2017-02-27',4,'Y'),
            (11,'2017-02-28',3,'N'),
			(11,'2017-02-28',4,'Y'),
            (12,'2017-02-26',4,'Y'),
			(12,'2017-02-26',4,'Y'),
			(12,'2017-02-27',4,'Y'),
			(12,'2017-02-27',4,'Y'),
            (12,'2017-02-28',4,'Y'),
			(12,'2017-02-28',4,'Y');
            
            
insert into studentacademicperformance
		values(1,4,10),(1,1,9),(2,1,11),(3,5,11),(3,6,12),(4,5,11),(4,6,12),(4,7,10),
			  (4,5,11),(5,1,11),(5,2,12),(6,2,10),(6,2,8),(7,2,10),(8,3,6),(8,4,7),
              (9,6,10),(9,7,11),(10,1,10),(10,2,11),(10,4,12),(11,2,12),(12,3,12),(12,4,12);
              
              
-- Выбрать всех студентов определенной группы.
select g.name `group`, s.id `id student`, s.firstname `first name student`, s.secondname `second name student`, s.lastname `last name student`
from students as s
 join groups as g
 on s.id_group=g.id
 where g.name like 'front-end';

-- Выбрать преподавателей которые читают пары в определенной группе
select  g.name `group`, t.firstname `first name teacher`, t.secondname `second name teacher`, t.lastname `last name teacher`
from teachers as t
join teachergroup as tg
on t.id=tg.id_teacher
join groups as g
on tg.id_group=g.id
where g.name like 'full-stack';

-- Выбрать всех студентов у которых читает определенный преподаватель
select s.id `id student`, s.firstname `first name student`, s.secondname `second name student`, s.lastname `last name student`, g.name `group`, t.id `id teacher`, t.firstname `first name teacher`, t.secondname `second name teacher`,t.lastname `last name teacher`
from students as s
join groups as g
on s.id_group=g.id 
join teachergroup as tg
on g.id=tg.id_group
join teachers as t
on tg.id_teacher=t.id
where t.lastname like 'Нагиев' order by s.id;

-- Выбрать  всех студентов с определенной фамилией
select s.id `id student`, s.firstname `first name student`, s.secondname `second name student`, s.lastname `last name student`, s.id_group
from students as s
 where s.lastname like 'Юзиков';

-- Изменить группу определенному студенту
update students
	set id_group = 3 
		where lastname like 'Юзиков';

-- проверяем, группа изменилась
select s.firstname, s.secondname, s.lastname, s.id_group
from students as s
 where s.lastname like 'Юзиков';

-- Изменить № телефона определенного преподавателя
update phoneteacher
	set phone = '+30663698521' 
		where phone like '+380931111111';
        
-- Удалить определенного студента
delete from students 
where lastname like 'Юзиков';

-- проверяем, студент удалён
select s.id, s.firstname, s.secondname, s.lastname, g.name `group`
from students as s
 join groups as g
 on s.id_group=g.id;

-- Добавить нового преподавателя
 insert into teachers(firstname, secondname, lastname,id_city,id_street,house,flat,maritalstatus)
			values
            ('Артур','Геннадиевич','Мамедов',1,2,'18','98','Y');

insert into teachergroup
			values
            (6,2),(6,3);

insert into phoneteacher(id_teacher,phone)
			value
            (3,'+380666666666');
            

-- Добавить в таблицу студентов поле № телефона
alter table students 
	add column phone varchar(20);

-- Установить всем студентам номер телефона 123456
update students
	set phone='123456'
		where phone is null;

select * from students;

-- средний балл студентов
select s.id `id student`, s.firstname `first name student`, s.secondname `second name student`, s.lastname `last name student`, count(mark), avg(mark) from students as s
join studentacademicperformance as sap
on s.id=sap.id_student	
join marks as m
on sap.id_mark=m.id
group by s.id;



