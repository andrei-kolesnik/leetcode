/*
596. Classes More Than 5 Students
https://leetcode.com/problems/classes-more-than-5-students/

Sample input:

create table dbo.Courses (
	student char(1) not null,
	class varchar(16) not null
);

--truncate table Courses;
insert into Courses (student, class)
values
('A', 'Math'),       
('B', 'English'),    
('C', 'Math'),       
('D', 'Biology'),    
('E', 'Math'),       
('F', 'Computer'),   
('G', 'Math'),       
('H', 'Math'),       
('I', 'Math');

insert into Courses (student, class)
values
('B', 'English'),
('B', 'English'),
('B', 'English'),
('B', 'English');


+---------+------------+
| student | class      |
+---------+------------+
| A       | Math       |
| B       | English    |
| C       | Math       |
| D       | Biology    |
| E       | Math       |
| F       | Computer   |
| G       | Math       |
| H       | Math       |
| I       | Math       |
+---------+------------+

Sample output:
+---------+
| class   |
+---------+
| Math    |
+---------+
*/
select
	class
from 
	(select distinct student, class from Courses) DCourses
group by
	class
having count(*) >= 5;