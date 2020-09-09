use pubs;

-- A(1) 
select p.pub_name, count(*) as employees_num
from publishers p, employee e
where p.pub_id=e.pub_id
group by p.pub_id, p.pub_name ;

-- A(2-i)
select t.title, sum(s.qty) as 수량, sum( t.price * s.qty) as 금액
from titles t, sales s
where t.title_id= s.title_id and year(s.ord_date)=1993
group by t.title_id, t.title;

-- A(2-ii)
select t.title, sum(s.qty) as 수량, sum( t.price * s.qty) as 금액
from titles t, sales s
where t.title_id= s.title_id and year(s.ord_date)=1993
group by t.title_id, t.title
UNION
select title, 0 as 수량, 0 as 금액
from titles 
where title_id not in ( select title_id from sales where year(ord_date)=1993 );

-- A(4)
select title
from titles
where title_id in (
	select ta.title_id
	from titleauthor ta
	group by ta.title_id
	having count(*) = 1)
;

-- A(5)
select concat(a.au_fname, ' ',a.au_lname) as 저자이름
from authors a, titleauthor ta
where a.au_id=ta.au_id
group by a.au_id, a.au_lname, a.au_fname
having count(*) = ( select count(*) from titleauthor group by au_id 
order by count(*) desc limit 1);
			
use classicmodels;

-- B(1)
select month(o.orderDate) as 월, sum(od.quantityOrdered * od.priceEach) as 매출
from orders o, orderdetails od
where o.orderNumber=od.orderNumber and year(o.orderDate)=2004
group by month(o.orderDate);

select * from customers;
select * from orders;
select * from orderdetails;
-- B(2)
select c.customerName as 회사명, count(distinct o.orderNumber) as 주문회수, avg( od.quantityOrdered * od.priceEach) as 평균주문금액, max(od.quantityOrdered * od.priceEach) as 최대쥬뮨금액
from customers c, orders o, orderdetails od
where c.customerNumber=o.customerNumber and o.orderNumber=od.orderNumber
group by c.customerNumber, c.customerName;
use classicmodels;



-- B(3)
select c.customerName as 회사명, o.orderDate as 주문날짜, sum(od.quantityOrdered * od.priceEach) as 주문금액
from customers c, orders o, orderdetails od
where c.customerNumber=o.customerNumber and o.orderNumber=od.orderNumber
group by c.customerNumber, c.customerName, o.orderDate
having sum(od.quantityOrdered * od.priceEach) = (
select sum(od.quantityOrdered * od.priceEach) from customers c,orders o, orderdetails od
where o.orderNumber=od.orderNumber and c.customerNumber=o.customerNumber group by c.customerNumber, c.customerName,o.orderdate order by sum(od.quantityOrdered * od.priceEach) desc limit 1)
;
