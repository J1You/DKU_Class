use 학사db;

-- 1(a)
select s.name, ct.cid, ct.grade
from student s join course_taken ct on s.id=ct.sid;

-- 2(a)
select s.name, c.name, ct.grade
from student s join course_taken ct on s.id=ct.sid inner join course c on ct.cid=c.id;

use 학사db;

-- A(1)
select s.name as 학생이름, c.name as 과목이름, d.name as 전공이름
from student s, course c, department d, instructor i , course_taken ct
where i.name='이장택' and i.pid=c.instructor and s.major=d.id and s.id=ct.sid and ct.cid=c.id;

-- A(2)
select s.name
from student s
where s.id not in(
   select ct.sid
   from instructor i, course c, course_taken ct
   where i.dept = 'ss' and c.instructor = i.pid and ct.cid = c.id
);

-- A(3)
select c.id, c.name
from course c
where c.id not in (
   select ct.cid
   from course_taken ct
   where ct.year_taken = 1997 or ct.year_taken = 1998
   );
   
-- A(4)
select s.name
from student s
where s.id in(
select ct.sid
from course_taken ct, course c
where c.name='기초전산' and c.id=ct.cid )
and s.id in(
select ct.sid
from course_taken ct, course c
where c.name='데이타베이스'and c.id=ct.cid);
	
use world;
    
-- B(1)
select count(*) as 중국도시수
from city ci, country co
where co.name='China' and co.code=ci.countrycode;
    
-- B(2)
select co.name, co.population
from country co
where co.population = ( select MIN(population) from country );
            
-- B(3)
select DISTINCT cl.language
from countrylanguage cl, country co
where co.region='Caribbean' and cl.countrycode=co.code;
    
-- B(4)
select code , name
from country
where code not in ( select DISTINCT countrycode from countrylanguage );
    
-- B(5)
select c1.name, c1.id, c2.id
from city c1 join city c2 on c1.name=c2.name
where c1.id <> c2.id;

use pubs;

-- C(1)
select t.title
from titles t , publishers p
where p.pub_name='Binnet & Hardley' and t.pub_id=p.pub_id;

-- C(2)
select concat(e.fname,' ',e.lname) as 직원명, j.job_desc as 직책
from employee e, jobs j
where (year(e.hire_date)=1990 or year(e.hire_date)=1991) and e.job_id=j.job_id;

use classicmodels;

-- D(1)
select o.orderNumber, c.customerName,e.lastName, o.orderDate, o.comments
from orders o, customers c,employees e
where o.status='Cancelled' 
and o.customerNumber = c.customerNumber
and c.SalesRepEmployeeNumber = e.employeeNumber;

-- D(2)
select p.productname 
from orderdetails od join products p on od.productcode = p.productcode 
where od.ordernumber = 10100;
