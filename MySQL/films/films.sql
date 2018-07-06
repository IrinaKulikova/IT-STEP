DROP database IF EXISTS FILMS;

CREATE DATABASE IF NOT EXISTS films
       DEFAULT CHARACTER SET UTF8 
       COLLATE utf8_general_ci;

use films;

CREATE TABLE IF NOT EXISTS genres
(
id int primary key auto_increment,
name varchar(100) default 'unknow'
)ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS nationalities
(
id int primary key auto_increment,
name varchar(60) default 'unknow' 
)ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS directors
(
id int primary key auto_increment,
firstname varchar(60) not null,
lastname varchar(60) not null,
id_nationality int,
	   CONSTRAINT fk_nationality_id_directions
       FOREIGN KEY(id_nationality)
       REFERENCES nationalities(id)
       ON DELETE SET NULL
	   ON UPDATE CASCADE,
birth date
)ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS actors
(
id int primary key auto_increment,
firstname varchar(60) not null,
lastname varchar(60) not null,
id_nationality int,
	   CONSTRAINT fk_nationality_id_actors
       FOREIGN KEY(id_nationality)
       REFERENCES nationalities(id)
       ON DELETE SET NULL
	   ON UPDATE CASCADE,
birth date
)ENGINE = InnoDB;


CREATE TABLE IF NOT EXISTS movies
(
id int primary key auto_increment,
id_director int,
	   CONSTRAINT fk_director_id_movies
       FOREIGN KEY(id_director)
       REFERENCES directors(id)
       ON DELETE SET NULL
	   ON UPDATE CASCADE,
title varchar(60) not null,
`release year` date,
rating decimal(4,2) default '0',
plot text,
movielength int default '0'
)ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS movie_actor
(
id_actor int DEFAULT NULL,
	   CONSTRAINT fk_actor_id_movie_actor
       FOREIGN KEY(id_actor)
       REFERENCES actors(id)
       ON DELETE SET NULL
	   ON UPDATE CASCADE,
id_movie int DEFAULT NULL,
	   CONSTRAINT fk_movie_id_movie_actor
       FOREIGN KEY(id_movie)
       REFERENCES movies(id)
       ON DELETE SET NULL
	   ON UPDATE CASCADE
)ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS movie_genre
(
id_movie int DEFAULT NULL,
	   CONSTRAINT fk_movie_id_movie_genre
       FOREIGN KEY(id_movie)
       REFERENCES movies(id)
       ON DELETE SET NULL
	   ON UPDATE CASCADE,
id_genre int DEFAULT NULL,
	   CONSTRAINT fk_genre_id_movie_genre
       FOREIGN KEY(id_genre)
       REFERENCES genres(id)
       ON DELETE SET NULL
	   ON UPDATE CASCADE
)ENGINE = InnoDB;

insert into genres(name) 
            values
            ('комедия'),
            ('триллер'),
            ('детектив'),
            ('екшен'),
            ('драмма'),
            ('исторический'),
            ('ужасы');
            
insert into nationalities(name) 
			values
            ('американец'),
            ('англичанин'),
            ('русский'),
            ('француз'), 
            ('украинка');
            
insert into actors(firstname,lastname,id_nationality,birth)
			values 
            ('Алиса','Милано',1,'1972-12-19'),
            ('Ольга','Сумская',5,'1966-08-22'), 
            ('Сэми','Насэри',3,'1961-07-02'),
            ('Никита','Михалков',4,'1945-10-21'),
			('Брюс','Виллис', 1,'1955-03-19'),
			('Джон','Траволта',1,'1954-02-18'),
			('Боб', 'О́денкерк',1,'1962-10-22');
            
insert into directors(firstname,lastname,id_nationality,birth)
            values
            ('Стивен', 'Спилберг', 1, '1946-12-18'),
            ('Квентин','Тарантино',1,'1963-03-27'),
            ('Богдан','Ступка',5,'1941-08-27'),
            ('Федор','Бондарчук',3,'1967-05-09'),
            ('Льюк','Бессон',4,'1959-03-18'),
			('Джон','МикТиррнан',1,'1951-01-08');
            
insert into movies(id_director,title,`release year`,rating,plot,movielength) 
			values
            (5,'Такси 1','2003-00-00', 7.9 , 'о сумасшедшем водителе',96), 
            (4,'Статский Советник','2005-00-00', 8.5 , 'можно смотреть',125),
            (2,'Криминальное чтиво','1994-00-00', 9.1, 'классика американского кино',178), 
            (5,'Опасная восьмерка','2015-00-00', 8.4 , 'о легендарном охотнике за головами',187), 
            (3,'Тарас Бульба','2009-00-00', 9.4 , 'по повести Николая Васильевича Гоголя',115),          
			(6,'Крепкий орешек','1988-00-00', 9.1 , 'фильм о крутом парне',131),          
			(6,'Адская поездка','2008-00-00', 8.5 , 'о байкере по имени Пистолеро',112),
			(4,'Адмиралъ','2008-00-00', 7.5 , 'о чем-то....',92),            
            (6,'Дед Мороз. Битва магов','2016-00-00', 6.5 , 'трэш',101),
			(4,'Черное зеркало','2013-00-00', 8.5 , 'отражение пороков нашей жизни',92),
			(6,'Отель Бейтс','2011-00-00', 8.6 , 'о психе убийце',92),
			(4,'Лучше звоните Солу 2','2015-00-00', 9.1 , 'о идеальном юристе',50), 
			(4,'Лучше звоните Солу 3','2017-00-00', 9.0 , 'о идеальном юристе',55); 

insert into movie_genre(id_movie, id_genre)
			values
            ( 1 , 4 ),( 1 , 3 ), 
            ( 2 , 5 ), ( 2 , 6 ),
            ( 3 , 2 ), ( 3 , 3 ),
            ( 4 , 2 ), ( 4 , 3 ),
            ( 5 , 5 ), ( 5 , 6 ), 
            ( 6 , 4 ), ( 6 , 3 ) ,
            ( 7 , 2 ), ( 7 , 7 ),
            ( 8 , 5),(8 , 6),
			( 9 , 1),( 9 , 4),
            (10, 4),(10 , 5),
            (11 , 7), ( 11 , 2 ),
            (12 , 3), ( 12 , 4) , (12 , 5),
			(13 , 3), ( 13 , 4) , (13 , 5);
            
insert into movie_actor(id_movie, id_actor)
			values
            ( 1 , 3 ), ( 1 , 1 ),
            ( 2 , 2 ), ( 2 , 4 ),
            ( 3 , 5 ), ( 3 , 6 ),
            ( 4 , 5 ), ( 5 , 6 ), ( 5 , 1 ),
            ( 6 , 1 ) , ( 6 , 5),
            ( 7 , 3 ), ( 7, 7 ),
            ( 8, 2 ), ( 8 , 4 ),
            ( 9, 1 ), ( 9, 4 ),
            ( 10 , 1 ), ( 10 , 3 ),
            ( 11 , 1 ), ( 11 , 6 ),
            ( 12 , 7 ), (12 , 7), 
            (13 , 3), ( 13 , 7 );
            
-- 1. Выбрать все фильмы и отсортировать по названию
select  m.id, d.lastname as director, m.title, m.`release year`, m.rating, m.plot, m.movielength
from movies as m
join directors as d
on m.id_director=d.id
order by title;

-- 2. Выбрать все фильмы и отсортировать по году выпуска
select  m.id, d.lastname as director, m.title, m.`release year`, m.rating, m.plot, m.movielength
from movies as m
join directors as d
on m.id_director=d.id
order by `release year`;

-- 3. Выбрать все фильмы и отсортировать по рейтингу
select  m.id, d.lastname as director, m.title, m.`release year`, m.rating, m.plot, m.movielength
from movies as m
join directors as d
on m.id_director=d.id
order by rating;

-- 4. Выбрать все фильмы выпущенные в прошлом году
select  * from movies as m
where `release year` like '2017-00-00';

-- 5. Выбрать все фильмы по заданному жанру (комедия, боевик, ...)
select m.id, m.title, `release year`, m.rating, m.plot, m.movielength, g.name
from movies as m
join movie_genre as mg 
join genres as g 
on g.id=mg.id_genre and m.id=mg.id_movie
where g.name like 'триллер';

-- 6. Выбрать все фильмы по заданному актеру 
select m.id, m.title, `release year`, m.rating, m.plot, m.movielength, a.lastname, a.firstname
from movies as m
join movie_actor as ma 
join actors as a 
on a.id=ma.id_actor and m.id=ma.id_movie
where a.lastname like 'Милано';

-- 7. Выбрать все фильмы по заданному продюсеру
select m.id, m.title, `release year`, m.rating, m.plot, m.movielength, d.lastname, d.firstname
from movies as m
join directors as d 
on m.id_director=d.id
where d.lastname like 'Бессон';





-- представления VIEWS
-- 1. Для представления данных актеров (Имя, Фамилия) и количестова фильмов в которых эти актеры снялись
create view actor_count_movies
as 
select a.firstname, a.lastname, count(a.id) as `count movies`
from actors as a, movie_actor as ma 
where a.id=ma.id_actor 
group by a.id;
-- отображаем
select * from  actor_count_movies;

-- 2. Количество фильмов каждого жанра
create view genre_count
as 
select g.name, count(g.id) as `count movies`
from genres as g, movie_genre as mg
where g.id=mg.id_genre
group by g.id;

select * from genre_count;

-- 3. Количество фильмов снятых режисером
create view director_count_movies
as
select d.firstname as `name director`, d.lastname as `surname director`, count(m.id) as `count movies`
from directors as d, movies as m
where d.id=m.id_director
group by m.id_director;

select * from  director_count_movies;

-- 4. Средний рейтинг фильмов каждого жанра
create view genre_rating
as 
select g.name, avg(m.rating) as `average rating`
from genres as g, movies as m, movie_genre as mg
where g.id=mg.id_genre and m.id=mg.id_movie
group by g.id;

select * from genre_rating;



-- 1. Создать процедуру добавления нового фильма в базу данных.
-- Процедура принимает следующие входные параметры:
-- 	Название фильма (Title)
-- 	Год релиза (ReleasyYear)
-- 	Рейтинг (Rating)
-- 	Сюжет (Plot)
-- 	Длительность (MovieLength)
-- 	Жанр (GenreName)
-- 	Режисер (FirstName, LastName)
-- Предусмотреть добавление корректных связей между таблицами Movies <-> Generes, Movies->Directors.
-- Если режисера в таблице Directors нет, то необходимо создать новую запись, если есть - получить
-- DirectorID.
-- Если жанр фильма в таблице Genres отсутсвует - его необходимо добавить в таблицу.


drop procedure if exists get_id_director;
drop procedure if exists get_id_genre;
drop procedure if exists add_movie;

delimiter $
create procedure get_id_director(directorname varchar(60),directorsurname varchar(60), inout id_new_director int)
begin
    select id into id_new_director
       from directors
			where firstname = directorname and lastname = directorsurname;            
 -- если такого режессера нет, добавляем его в таблицу
        if id_new_director like 0 then
		insert into directors(firstname, lastname, id_nationality, birth) value(directorname, directorsurname, null, null);
        select last_insert_id() into id_new_director;
    end if;
end$
delimiter ;


delimiter $
create procedure get_id_genre(genrename varchar(60), inout id_new_genre int)
begin
   	select id into id_new_genre
		from genres
			where genrename like `name`;

-- если такого жанра нет, добавляем
	if id_new_genre like 0 then
		insert into genres(name) values(genrename);
		select last_insert_id() into id_new_genre;
    end if;
end$
delimiter ;


delimiter $
create procedure add_movie( titlemovie varchar(60),
							realeseyear date,
                            ratingmovie decimal(4,2),
                            plotmovie text,
                            lengthmovie int, 
                            genrename varchar(100), 
                            directorname varchar(60), 
                            directorsurname varchar(60))
begin
-- ищем режесерра
	     declare id_new_director int default 0;
		 declare id_new_genre int default 0;
		 declare id_movie int default 0;         
-- ищем директора картины
		 call  get_id_director(directorname, directorsurname, id_new_director);
-- ищем жанр
		 call  get_id_genre(genrename, id_new_genre);
-- ищем такой фильм
			select id into id_movie
				from movies
					where title=titlemovie and 
					realeseyear=`release year` and 
					id_director=id_new_director and
					rating= ratingmovie and
					plotmovie=plot and  
					lengthmovie=movielength;	
		if id_movie like 0 then
        insert into movies(id_director,title,`release year`,rating,plot,movielength)
        value(id_new_director,titlemovie,realeseyear,ratingmovie,plotmovie,lengthmovie);
        select last_insert_id() into id_movie;
        insert into movie_genre value(id_movie,id_new_genre);
        end if;
end$
delimiter ;

-- такой фильм есть, директора есть, жанр есть
call add_movie('Такси 1','2003-00-00', 7.9 ,'о сумасшедшем водителе',96,'екшен','Льюк','Бессон');

-- такого фильма нет, директора есть, жанр есть
call add_movie('название фильма','1999-00-00',8.33,'крутой дорогой фильмец',155,'ужасы','Стивен', 'Спилберг');

-- такого фильма нет, директора нет, жанра нет
call add_movie('фильм без названия','2018-00-00',8.33,'фильм, которого ещё нет',155,'хорор','Ба', 'Бай');

-- 2. Создать функцию вычисления возвраста (актеров и режисеров) по дате рождения. 
-- Для вычисления разницы между двумя датами в годах воспользоваться кодом:
-- 	DATE_FORMAT(FROM_DAYS(TO_DAYS(now()) - TO_DAYS(@dateofbirth)), '%Y') + 0;

drop function if exists  get_age ;

delimiter $
create function get_age(firstnamesearch varchar(60), lastnamesearch varchar(60))
returns int
begin
	declare birthsearch date default 0;
    declare age int default 0;
    select birth from actors where firstname=firstnamesearch and lastname=lastnamesearch into birthsearch;
	if birthsearch <> 0 then
   select DATE_FORMAT(FROM_DAYS(TO_DAYS(now()) - TO_DAYS(birthsearch)), '%Y') + 0 into age;
   end if;
   return age;
end$
delimiter ;

select get_age('Алиса','Милано') as `age actor`;

select get_age('Ольга','Сумская') as `age actor` ;

select get_age('Инна','Пупкина') as `age actor` ;

-- Возраст всех актеров
select id, firstname, lastname, get_age(firstname,lastname) as age from actors;


-- Написать триггер, который реализует каскадное удаление всех связанных данных с жанром.
-- т.е. при удалении жанра необходимо удалить все фильмы относящиеся к этому жанру.

ALTER TABLE `movies` ADD `delete` enum('Y','N') default 'N';

drop trigger if exists delete_genre_trigger;

create temporary table if not exists to_remove
	as 
    select m.id from movies as m 
             join movie_genre as mg 
             on m.id=mg.id_movie;

delimiter $
create trigger delete_genre_trigger
	before delete on genres
    for each row
begin	
	update `movies` set `delete`='Y' where id in 
    		(select * from to_remove);	
    delete from movie_genre where id_genre = OLD.id;   
    delete from movie_genre where id_movie in (select * from to_remove);    
    delete from movies where `delete` like 'Y';    
    drop table if exists to_remove; 
    end$
delimiter ;

delete from genres where name like 'ужасы';
