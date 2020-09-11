-- 1(a)
drop database if exists 최지윤7;

CREATE DATABASE IF NOT EXISTS 최지윤7;
USE 최지윤7;

CREATE TABLE IF NOT EXISTS 최지윤_student7 (
	id7 CHAR(10) NOT NULL primary key,
	name7 CHAR(10),
    major7 CHAR(10),
    gpa7 float
);

CREATE TABLE IF NOT EXISTS 최지윤_course7 (
	cid7 char(10) NOT NULL primary key,
    name7 char(20),
    instructor7 char(10)
);

CREATE TABLE IF NOT EXISTS 최지윤_course_taken7 (
	sid7 char(10) NOT NULL,
    cid7 char(10) NOT NULL,
    grade7 float,
    year_taken7 int,
    primary key (sid7,cid7),
    foreign key(sid7) references 최지윤_student7(id7),
	foreign key(cid7) references 최지윤_course7(cid7)
);


-- 1(b)

insert into 최지윤_student7(id7,name7,major7,gpa7) 
	select id,name,major,gpa from 학사db.student where id not like '_____7' ;

insert into 최지윤_course7(cid7,name7,instructor7) 
	select id,name,instructor from 학사db.course;
    
insert into 최지윤_course_taken7(sid7,cid7,grade7,year_taken7) 
	select sid,cid,grade,year_taken from 학사db.course_taken where sid not like '_____7';
    
-- 1(c)

select * from 최지윤_student7 s join 최지윤_course_taken7 ct on s.id7=ct.sid7 join 최지윤_course7 c on c.cid7=ct.cid7 order by id7;

-- 2(a)

drop procedure if exists AddCourseGrade7;
Delimiter //
create procedure AddCourseGrade7 ( In pStud_name7 char(20), In pCo_name7 char(20), In pGrade7 float, out pIsError7 int )
	BEGIN
	declare s_id char(10);
    declare c_id char(10);
    declare continue handler for sqlexception set pIsError7=4;
    set pIsError7=0;
   
    select id7 into s_id from 최지윤_student7 where name7 = pStud_name7;
	select cid7 into c_id from 최지윤_course7 where name7 = pCo_name7;

	if s_id is null and c_id is null then set PIsError7=3;
    elseif c_id is null then set pIsError7=2;
    elseif s_id is null then set PIsError7=1;
    else
		insert into 최지윤_course_taken7(sid7, cid7, grade7,year_taken7) values(s_id, c_id, pGrade7,year(now()));
    end if;
    END //
Delimiter ;

-- 2(b)
call AddCourseGrade7('한나라','알고리즘',4.3,@isError);
select @isError ;

call AddCourseGrade7('최지윤','알고리즘',4.3,@isError);
select @isError ;

call AddCourseGrade7('한나라','멀티미디어',4.3,@isError);
select @isError ;

call AddCourseGrade7('최지윤','멀티미디어',4.3,@isError);
select @isError ;

call AddCourseGrade7('한나라','데이타베이스',4.3,@isError);
select @isError ;

-- 3
SET SQL_SAFE_UPDATES = 0;

Delimiter //
create procedure ComputeGPA3()
begin 
	declare cursor_end bool;
    declare stu_id char(10);
	declare stu_Cursor cursor for select id from student;
    declare continue handler for not found set cursor_end=1;
    open stu_Cursor;
    cursor_loop :Loop
		Fetch stu_cursor into stu_id;
        if cursor_end then leave cursor_loop; end if;
        update 최지윤_student7 set gpa7= (select avg(grade7) from 최지윤_course_taken where stu_id=sid7 group by sid7);
	end Loop;
    close stu_Cursor;
end //
Delimiter ;
call ComputeGPA3();
select * from 최지윤_student7;

-- 4(a)

drop table 최지윤_course_taken_Audit7;
create table 최지윤_course_taken_Audit7 (
	no int NOT NULL auto_increment primary key,
    sid char(10) not null,
    cid char(10) not null,
    user varchar(30),
    nowdate date ,
    action varchar(20)
);

-- Insert Trigger
delimiter //
create trigger Insert_trigger before insert on 최지윤_course_taken7 for each row
begin
	insert into 최지윤_course_taken_Audit7 
		set action='Insert', sid=new.sid7 , cid=new.cid7, user=user(), nowdate=now();
end// 
delimiter ;

-- Update Trigger
delimiter //
create trigger Update_trigger before update on 최지윤_course_taken7 for each row
begin
	insert into 최지윤_course_taken_Audit7 
		set action='Update', sid=old.sid7 , cid=old.cid7, user=user(), nowdate=now();
end// 
delimiter ;

-- Delete Trigger
delimiter //
create trigger Delete_trigger before delete on 최지윤_course_taken7 for each row
begin
	insert into 최지윤_course_taken_Audit7 
		set action='Delete', sid=old.sid7 , cid=old.cid7, user=user(), nowdate=now();
end// 
delimiter ;

-- 4(b)

Insert into 최지윤_course_taken7 values ('930405','cs322',4.2,2020);

Update 최지윤_course_taken7 set grade7=4.4 where sid7='930405' and cid7='cs322';

delete from 최지윤_course_taken7 where sid7='930405' and cid7='cs322';

select * from 최지윤_course_taken_Audit7;