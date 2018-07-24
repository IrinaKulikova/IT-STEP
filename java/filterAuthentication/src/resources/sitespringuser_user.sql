drop database if exists sitespringuser;

create database sitespringuser 
	character set utf8 
		collate utf8_general_ci;

use sitespringuser;

CREATE TABLE sitespringuser.user
(
    id int(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
    password varchar(60) NOT NULL,
    login varchar(60) NOT NULL
);

INSERT INTO sitespringuser.user (password, login) VALUES ('111', 'vasya@gmail.com');
INSERT INTO sitespringuser.user (password, login) VALUES ('123', 'inna@gmail.com');
INSERT INTO sitespringuser.user (password, login) VALUES ('000', 'cg.irenecooper@gmail.com');