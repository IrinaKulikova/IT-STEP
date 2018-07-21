drop database if exists collectioncd;

create database collectioncd 
	character set utf8 
		collate utf8_general_ci;

use collectioncd;

CREATE TABLE genre
(
    id int(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
    name varchar(60)
);

CREATE TABLE contry
(
    id int(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
    name varchar(255)
);

CREATE TABLE author
(
    id int(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
    name varchar(60),
    lastname varchar(60),
    genre_id int,
    contry_id int,
    CONSTRAINT author_genre_id_fk FOREIGN KEY (genre_id) REFERENCES genre (id)ON DELETE SET NULL ON UPDATE SET NULL,
    CONSTRAINT author_contry_id_fk FOREIGN KEY (contry_id) REFERENCES contry (id) ON DELETE SET NULL ON UPDATE SET NULL
);

CREATE TABLE album
(
    id int(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
    author_id int(11),
    name varchar(60),
    tracks int(11),
    CONSTRAINT album_author_id_fk FOREIGN KEY (author_id) REFERENCES author (id) ON DELETE CASCADE ON UPDATE CASCADE
);

INSERT INTO collectioncd.genre (name) VALUES ('pop');
INSERT INTO collectioncd.genre (name) VALUES ('rock');
INSERT INTO collectioncd.genre (name) VALUES ('rap');
INSERT INTO collectioncd.genre (name) VALUES ('disco');

INSERT INTO collectioncd.contry (name) VALUES ('USA');
INSERT INTO collectioncd.contry (name) VALUES ('Russia');
INSERT INTO collectioncd.contry (name) VALUES ('Ukraine');

INSERT INTO collectioncd.author (name, lastname, genre_id, contry_id) VALUES ('Полина', 'Гагарина', 1, 2);
INSERT INTO collectioncd.author (name, lastname, genre_id, contry_id) VALUES ('Баста', null, 3, 2);
INSERT INTO collectioncd.author (name, lastname, genre_id, contry_id) VALUES ('Sting', null, 1, 1);

INSERT INTO collectioncd.album (author_id, name, tracks) VALUES (1, 'Облака', 10);
INSERT INTO collectioncd.album (author_id, name, tracks) VALUES (1, 'девять', 9);
INSERT INTO collectioncd.album (author_id, name, tracks) VALUES (2, 'Баста', 12);
INSERT INTO collectioncd.album (author_id, name, tracks) VALUES (3, 'dreams', 11);