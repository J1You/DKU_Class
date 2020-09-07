drop database if exists 최지윤;
create database 최지윤;
use 최지윤;

create table 최지윤_Student(
	id int NOT NULL primary key,
    name varchar(15),
    major varchar(3),
    address varchar(30),
    gpa double,
    bdate date,
    foreign key (major) references 최지윤_Department(id)
);

insert into 최지윤_Student Values ("4747","최지윤","sw","경기도 용인시 수지구 동천동","4.5","2000-04-06"),
("1412","강수아","sw","경기도 용인시 기흥구 보정동","3.9","1999-01-23"),("3673","이채민","sw","경기도 용인시 수지구 죽전동","4.1","2000-09-21"),
("2351","최다형","cs","서울 서초구 반포동","3.2","2000-05-15");

create table 최지윤_Course(
	id varchar(5) NOT NULL primary key,
    name char(25),
    instructor varchar(5),
	prerequisite varchar(10),
    foreign key (instructor) references 최지윤_Instructor(pid),
    foreign key (prerequisite) references 최지윤_Course(id)
);

insert into 최지윤_Course Values ("sw101","프로그래밍기초","sw01",null),("sw102","프로그래밍2","sw02","sw101"),
("sw103","일반수학","cs01",null),("sw104","객체지향프로그래밍","sw02","sw102"),("sw105","데이터베이스","sw03",null),
("sw106","자료구조","sw03","sw103"),("cs100","일반물리학","cs02",null),("cs111","일반물리실험","cs02","cs100");

create table 최지윤_Course_Taken(
	no int NOT NULL auto_increment primary key,
	sid int,
    cid varchar(5),
    grade char(2),
    year date,
    foreign key (sid) references 최지윤_Student(id),
    foreign key (cid) references 최지윤_Course(id)
);

insert into 최지윤_Course_Taken (sid,cid,grade,year) Values ("4747","sw101","B","2019-03-08"),
("4747","sw102","A","2019-09-03"),("4747","sw104","A","2020-03-28"),("4747","sw105","A","2020-03-28"),
("1412","sw101","B","2019-03-08"),("1412","sw103","A","2020-03-28"),("3673","sw103","A","2019-03-08"),
("3673","sw106","B","2019-09-03"),("2351","cs100","B","2019-09-03"),("2351","cs111","A","2020-03-28");

create table 최지윤_Department(
	id varchar(3) NOT NULL primary key,
    name varchar(20) 
);

insert into 최지윤_Department Values ("sw","소프트웨어학과"),("cs","일반물리학과");


create table 최지윤_Instructor(
	pid varchar(5) NOT NULL primary key,
    name varchar (15),
    dept varchar(3),
    foreign key (dept) references 최지윤_Department(id)
);

insert into 최지윤_Instructor Values ("sw01","박규식","sw"),("sw02","우진운","sw"),("sw03","이석균","sw"),
("cs01","고희정","cs"),("cs02","김연중","cs");
