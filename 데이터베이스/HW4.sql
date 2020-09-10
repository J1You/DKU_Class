SET SQL_SAFE_UPDATES = 0;
use 학사db;

-- 1. 다음의 요구사항대로 명령문을 작성하고 이를 실행 후 결과를 보이시오.
-- (a) Student의 gpa를 모두 0.0으로 수정하시오.
UPDATE Student Set gpa=0.0;
select * from Student;

-- (b) 현재 course_taken의 내용을 기반으로 각 학생의 gpa를 계산 후 수정하는 update문을 쓰시오.

Update Student Set gpa=( 
	select avg(grade) from course_taken where id=sid group by sid 
    ) ;
select * from student;

-- 2. 학생 테이블에 Instructor에 대한 외래키인 advisor라는 속성을 추가하고자 한다.
-- (a) 위의 내용을 추가하는 명령문들을 쓰시오.

Alter table Student ADD advisor char(15);
ALTER TABLE student ADD CONSTRAINT FK_STUDENT_INSTRUCTOR FOREIGN KEY student(advisor)
REFERENCES instructor(name) ON UPDATE CASCADE;
select * from student;

-- (b) 같은 학과 교수로 advisor(지도교수)를 배정하는데 이는 임의 순서로 처리하고, 전공이 미정인 학생들의 지도교수는 null로 표현하시오. 이를 위한 명령문을 쓰고 처리 결과를 보이시오.


update student set advisor = 
	case when major="cs" then (
		select name from instructor where dept="cs" 
        order by rand() limit 1 )
    when major="ss" then (
		select name from instructor where dept="ss"
        order by rand() limit 1 )
    end;
select * from student;

-- 3. 과목번호는 종종 교육과정의 변화에 따라 수정되며, 그리고 외부 강사는 수급에 따라 수시로 변경된다. 이를 전제로 다음 문제에 답하시오.
-- (a) 과목번호의 수정 시 다른 테이블에 자동 반영되도록, 그리고 강사가 삭제되었을 때 과목 테이블에서 강사번호에 대한 외래키를 NULL로 설정될 수 있도록 외래키 제약조건들을 수정하시오. 


ALTER TABLE course_taken DROP FOREIGN KEY FK_COURSE_TAKEN_COURSE;
ALTER TABLE course_taken ADD CONSTRAINT FK_COURSE_TAKEN_COURSE FOREIGN KEY (cid)
REFERENCES course(id) ON UPDATE CASCADE;

ALTER TABLE course DROP FOREIGN KEY FK_COURSE_INSTRUCTOR;
ALTER TABLE course ADD CONSTRAINT FK_COURSE_INSTRUCTOR FOREIGN KEY (instructor)
REFERENCES instructor(pid) ON UPDATE CASCADE ON DELETE SET NULL;
select * from instructor;
delete from instructor where pid='cs10';
select * from course;
-- (b) 위의 내용이 제대로 처리되는 경우의 예를 보이시오.
update course set id="cs210" where id="cs211"; 
select * from course_taken;

-- 4. 학생들의 성적 조회 용 뷰를 생성하고 이를 통해 자신의 수강 과목들의 성적을 조회하려고 한다. 뷰의 정의는 courseRecord(student_id, student_name, course_name, course_grade)으로 이루어진다. 
-- (a) view를 생성하는 명령문을 보이시오.
CREATE VIEW courseRecord(student_id, student_name, course_name, course_grade) AS
	(	select s.id, s.name, c.name, ct.grade 
		from student s join course_taken ct on s.id=ct.sid join course c on c.id=ct.cid
	);
select * from courseRecord;

-- (b) 이를 통해 특정 학생의 수강 과목들의 성적을 조회하는 예제와 실행 결과를 보이시오. 
select * from courseRecord
where student_name="한나라";
