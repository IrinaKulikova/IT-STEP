drop database if exists itcompany;

create database if not exists itcompany
	default character set utf8
    collate utf8_general_ci;
    
use itcompany;

-- должность
create table position
(
id int primary key auto_increment,
name varchar(60) not null
);


-- отдел
create table department
(
id int primary key auto_increment,
name varchar(60) not null
);

-- заказщик
create table customer
(
id int primary key auto_increment,
name varchar(60) not null
);


-- заказ
create table `order`
(
id int primary key auto_increment,
name varchar(255) not null,
`description` text,
startdate date,
enddate date,
status enum('executed', 'not executed') default 'not executed'
);


-- заказщик-заказ
create table customer_order
(
customer_id int,
constraint fk_customer_id_customer_order
	foreign key(customer_id)
	references customer (id)
    on update cascade
    on delete set null,
order_id int,
constraint fk_order_id_customer_order
	foreign key(order_id)
	references `order` (id)
    on update cascade
    on delete set null
);


-- задача
create table task
(
id int primary key auto_increment,
name varchar(255) not null,
`description` text,
order_id int,
	constraint fk_order_id_task
	foreign key(order_id)
	references `order`(id)
    on update cascade
    on delete set null
);


-- сотрудник
create table employee
(
id int primary key auto_increment,
name varchar(60) not null,
surname varchar(60) not null,
position_id int,
	constraint fk_position_id_employee
	foreign key(position_id)
	references `position`(id)
    on update cascade
    on delete set null,
department_id int,
	constraint fk_deportment_id_employee
	foreign key(department_id)
	references department(id)
    on update cascade
    on delete set null
);


-- сотрудник-задача-время
create table employee_task
(
employee_id int,
	constraint fk_employee_id_employee_task
	foreign key(employee_id )
	references employee(id)
    on update cascade
    on delete set null,
task_id int,
	constraint fk_task_id_employee_task
	foreign key(task_id )
	references task (id)
    on update cascade
    on delete set null,
starttime datetime,
endtime datetime
);


-- 2.	Создать запросы для наполнения базы данных тестовыми данными (не менее трех работников, не менее пяти заказчиков и не менее двух выполненных и двух текущих заказов).
insert into department(`name`) values('development'), ('sale department');

insert into `position`(`name`) values('PM'),('DesignerUI'),('Frontend developer'),('Backend Developer');

insert into customer(`name`) values('приват банк'),('облэнерго'),('теплоэнерго'),('атб'),('varus');

insert into `order`(name, `description`,startdate,enddate,`status`) 
			values('интернет магазин','разработать магазин по оптовым продажам','2016-01-01','2018-01-01','executed'),
            ('програма учета товаров на складе','создать программу для учета доступных товаров у поставщиков','2016-01-01','2019-01-01','not executed'),
            ('android приложение','личный кабинет польователей и отслежевание показателей счётчиков','2017-01-01','2018-02-01','executed'),
			('ios приложение','личный кабинет польователей и отслежевание показателей счётчиков','2018-06-01','2019-0-01','not executed'),
            ('настольное приложение учета клиетов','приложение для...........','2018-02-01','2018-10-01','not executed'),
			('игра','фейсбук приложение','2015-01-01','2016-08-01','executed'),
			('мультиплатформенное приложение','курс валют','2018-03-15','2018-10-01','not executed'),
			('интернет магазин атб','хозтовавр..........','2018-03-10','2019-00-01','not executed');
            
insert into customer_order(customer_id, order_id) values(4,1),(4,2),(3,3),(3,4),(1,5),(4,8),(1,7),(5,6);

insert into task(`name`, `description`,  order_id) values ('разработать дизайн сайта','использовать ...........',1),
														  ('сверстать сайт','используемые технологи .... ',1),
                                                          ('разработать базу данных','технологии .....',1),
                                                          ('разработать интерфейс приложения','техлогогия',3),
                                                          ('связаться с заказщикам по вопросам','',2),
                                                          ('обсудить технический вопрос','реализация .....',3),
                                                          ('наполнить базу данных','пользователи...',4),
                                                          ('написать клиент приложение','технологиии',4),
                                                          ('утвердить дизайн','меню.........',5),
                                                          ('пофиксить что-то','exception',6),
                                                          ('разработать страницу личный кабинет','технологиии',7),
                                                          ('наполнить магазин товарами','',8);
                                                          
insert into employee(`name`,`surname`,position_id,department_id)
					values('Инна', 'Хмеленко', 1,1),
                    ('Леша', 'Пчелкин', 3,1),
                    ('Паша','Петров',4,1),
                    ('Елена','Мишина',2,1),
                    ('Коля','Сизых',4,1);
                    
                  
insert into employee_task values(1,5,'2018-03-22 09:00:00','2018-03-22 11:30:00'),
								(1,6,'2018-03-22 15:00:00','2018-03-22 16:30:00'),
                                (2,3,'2018-03-01 09:00:00','2018-03-01 18:00:00'),
								(5,3,'2018-03-01 10:00:00','2018-03-01 15:00:00'),
								(2,3,'2018-03-02 09:00:00','2018-03-02 15:00:00'), 
								(2,3,'2018-03-03 09:00:00','2018-03-03 18:00:00'), 
								(2,3,'2018-03-04 12:00:00','2018-03-04 14:00:00'), 
								(2,3,'2018-03-05 15:00:00','2018-03-05 18:00:00'),
                                (3,3,'2018-03-06 09:00:00','2018-03-06 18:00:00'), 
								(3,3,'2018-03-07 12:00:00','2018-03-07 18:00:00'),
                                (4,1,'2018-03-02 16:00:00','2018-03-02 18:00:00'), 
								(4,1,'2018-03-03 11:00:00','2018-03-03 17:00:00'),
                                (4,4,'2018-03-10 09:40:00','2018-03-10 13:30:00'), 
								(4,4,'2018-03-11 09:50:00','2018-03-11 17:10:00'),
                                (1,9,'2018-03-20 12:11:00','2018-03-20 14:30:00'),
								(2,10,'2018-03-21 09:00:00',null),
                                (4,11,'2018-03-22 09:00:00',null), 
								(4,12,'2018-03-21 09:00:00',null),
                                (4,12,'2018-03-22 09:00:00',null),
                                (4,10,'2018-03-20 12:00:00','2018-03-20 18:00:00');


-- 3.	Создать запрос, который позволит посмотреть список клиентов с которыми не работает ни один работник компании
-- a
create view show_empty_orders_1
as
select  c.id,c.name from  customer as c
			  left outer join  customer_order as co      
				on c.id = co.customer_id 
				where co.order_id is null;    
-- b
create view show_empty_orders_2
as
select id, name from customer
			where id not in (select customer_id from customer_order);



-- 4.	Написать запрос, который позволит просмотреть все задачи определенного работника в отсортированном виде по времени работы над их выполнением (функция mysql timediff)

drop procedure if exists time_employee_task;

delimiter $
create procedure time_employee_task(employee_surname varchar(60))
begin
select e.name, et.task_id, e.surname,  sum(HOUR(et.endtime)*60+MINUTE(et.endtime)-(HOUR(et.starttime)*60+MINUTE(et.starttime)))/60 as `hours` from  employee_task as et
			  join employee as e
			  on e.id = et.employee_id 
					where e.surname like employee_surname and et.endtime is not null
					group by et.task_id
					order by `hours` desc;
 end$
 delimiter ;

 

-- 5.	Написать запрос, который позволит пересмотреть список задач, которые выполняются сейчас
create view show_tasks_now
as
select * from  employee_task where endtime is null ;



-- 6.	Создать запрос, который покажет работника, получившего наибольшее количество задач.
create view best_employee as
select e.id, e.name, e.surname, count(e.id) as count from  employee_task as et
			  join employee as e
			  on e.id = et.employee_id 
				group by(e.id)
				order by count desc
					limit 1;              



-- 7.	Создать запрос, который позволит отобразить клиентов, не сотрудничавших с двумя указанными работниками
delimiter $
create procedure show_company_without_two_employee(firstsurname_employee varchar(60), secondsurname_employee varchar(60))
begin
select distinct c.id, c.name as `company name`  from employee as e
            join  employee_task as et
            on e.id=et.employee_id
				join task as t 
				on  t.id=et.task_id
					join customer_order as co
					on t.order_id=co.customer_id
						join customer as c
						on c.id=co.customer_id
							where e.surname != firstsurname_employee and e.surname != secondsurname_employee;
end$
delimiter ;



-- 8.	Создать запрос, который повысит стоимость заказа выполняемого указанным работником на 10%
ALTER TABLE `order` ADD `price` decimal( 11, 2 ) default 1000;
ALTER TABLE `order` ADD `currency` enum( 'euro', 'dollar', 'грн') default 'dollar';

update `order` set `price`=10000 where id = 1;
update `order` set `price`=15000 where id = 2;
update `order` set `price`=17000 where id = 3;
update `order` set `price`=5000 where id = 4;
update `order` set `price`=2000 where id = 5;
update `order` set `currency`='euro' where id = 1;
update `order` set `currency`='euro' where id = 3;
update `order` set `currency`='euro' where id = 4;

drop procedure if exists up_price_by_employee;

delimiter $
create procedure up_price_by_employee(surname_employee varchar(60))
begin

drop TABLE if exists up_price_order;
create TEMPORARY TABLE up_price_order
as
select distinct o.id from `order` as o
		 join task as t
         on o.id = t.order_id
			join employee_task as et
            on et.task_id=t.id
				join employee as e
                on e.id=et.employee_id
					where e.surname like surname_employee;
                    
update `order` set price = price*1.1 where id in (select id from up_price_order);

end$
delimiter ;


-- 9. Создать запрос, который удалит все заказы определенного заказчика за последний месяц
delimiter $
create procedure delete_last_month_orders_company(name_seach_company varchar(255))
begin

drop table if exists delete_order_customer_lastmonth;
-- находим id удаляемых заказов сохраняем их во временную таблицу
CREATE TEMPORARY TABLE  delete_order_customer_lastmonth
as
select o.id from customer as c
         join `order` as o
		 join customer_order as co
			on o.id = co.order_id and c.id = co.customer_id
			where  c.name like name_seach_company and TO_DAYS(o.startdate)+30 > TO_DAYS(now());
-- select * from delete_order_customer_lastmonth;

drop table if exists delete_task_customer_lastmonth;

-- находим id удаляемых задач и сохраняем во временную таблицу
CREATE TEMPORARY TABLE delete_task_customer_lastmonth
as
select t.id from task as t
		where t.order_id in (select * from delete_order_customer_lastmonth);
-- select * from delete_task_customer_lastmonth;

-- удаляем в таблице сотрудник-задачи все задачи связанные с заказом клинета, которые нужно удалить
delete from employee_task where task_id in (select * from delete_task_customer_lastmonth);
-- select * from employee_task;

-- удаляем все задачи вязанные с удаляемыми заказами
delete from task where order_id in (select * from delete_order_customer_lastmonth);
-- select * from task;
	
delete from customer_order where order_id in (select * from delete_order_customer_lastmonth);
-- select * from customer_order;

-- удаляем заказы
delete from `order` where id in (select * from  delete_order_customer_lastmonth);
-- select * from `order`;

-- удаляем временные таблицы
drop table if exists delete_order_customer_lastmonth;
drop table if exists delete_task_customer_lastmonth;

end$
delimiter ;












-- тесты
-- 3.	Создать запрос, который позволит посмотреть список клиентов с которыми не работает ни один работник компании
select * from show_empty_orders_1;
select * from show_empty_orders_2;

-- 4.	Написать запрос, который позволит просмотреть все задачи определенного работника в отсортированном виде по времени работы над их выполнением (функция mysql timediff)
select * from show_tasks_now;

-- 5.	Написать запрос, который позволит пересмотреть список задач, которые выполняются сейчас.
call time_employee_task('Хмеленко');
call time_employee_task('Пчелкин');
call time_employee_task('Петров');
call time_employee_task('Мишина');
call time_employee_task('Сизых');

-- 6	Создать запрос, который покажет работника, получившего наибольшее количество задач.
select * from best_employee;

-- 7.	Создать запрос, который позволит отобразить клиентов, не сотрудничавших с двумя указанными работниками
call show_company_without_two_employee('Мишина','Петров');
call show_company_without_two_employee('Хмеленко','Петров');
call show_company_without_two_employee('Мишина','Хмеленко');

-- 8.	Создать запрос, который повысит стоимость заказа выполняемого указанным работником на 10%
call up_price_by_employee('Хмеленко');
call up_price_by_employee('Сизых');
call up_price_by_employee('Пчёлкин');
select * from `order`;

-- 9.	Создать запрос, который удалит все заказы определенного заказчика за последний месяц
call delete_last_month_orders_company('varus');
call delete_last_month_orders_company('приват банк');
call delete_last_month_orders_company('облэнерго');
call delete_last_month_orders_company('теплоэнерго');
call delete_last_month_orders_company('атб');
select * from `order`;
