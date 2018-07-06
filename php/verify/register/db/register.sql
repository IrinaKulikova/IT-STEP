DROP database IF EXISTS register;

CREATE DATABASE IF NOT EXISTS register
       DEFAULT CHARACTER SET UTF8 
       COLLATE utf8_general_ci;

use register;

CREATE TABLE IF NOT EXISTS user
(
id int primary key auto_increment,
login varchar(60) not null unique,
email varchar(64) not null unique,
password varchar(64) not null,
activation varchar(64) not null,
status ENUM('active','inactive')
)ENGINE = InnoDB;