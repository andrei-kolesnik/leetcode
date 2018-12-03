/*
LeetCode 601. Human Traffic of Stadium
https://leetcode.com/problems/human-traffic-of-stadium/

create table Stadium (
	id int not null,
	date date not null,
	people int not null
)

Input 1:
insert into Stadium (id, date, people)
values
(1, '2017-01-01', 10),
(2, '2017-01-02', 109),
(3, '2017-01-03', 150),
(4, '2017-01-04', 99),
(5, '2017-01-05', 145),
(6, '2017-01-06', 1455),
(7, '2017-01-07', 199),
(8, '2017-01-08', 188)
+------+------------+-----------+
| id   | date       | people    |
+------+------------+-----------+
| 1    | 2017-01-01 | 10        |
| 2    | 2017-01-02 | 109       |
| 3    | 2017-01-03 | 150       |
| 4    | 2017-01-04 | 99        |
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-08 | 188       |
+------+------------+-----------+
Output 1:
+------+------------+-----------+
| id   | date       | people    |
+------+------------+-----------+
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-08 | 188       |
+------+------------+-----------+

Input 2:
delete from Stadium 
insert into Stadium (id, date, people)
values
(1, '2017-01-01', 10),
(2, '2017-01-02', 109),
(3, '2017-01-03', 150),
(4, '2017-01-04', 100)
+------+------------+-----------+
| id   | date       | people    |
+------+------------+-----------+
| 1    | 2017-01-01 | 10        |
| 2    | 2017-01-02 | 109       |
| 3    | 2017-01-03 | 150       |
| 4    | 2017-01-04 | 100       |
+------+------------+-----------+
Output 2:
+------+------------+-----------+
| id   | date       | people    |
+------+------------+-----------+
| 2    | 2017-01-02 | 109       |
| 3    | 2017-01-03 | 150       |
| 4    | 2017-01-04 | 100       |
+------+------------+-----------+
*/
-- MS SQL
with S100 as	
(
	select 
		S1.id as id1, 
		S2.id as id2
	from 
		Stadium S1, Stadium S2
	where
		S2.id - S1.id >= 2 and
		not exists (
			select S3.id 
			from Stadium S3 
			where 
				S3.people < 100 and 
				S3.id between S1.id and S2.id
		)
)
select distinct
	S.id,
	S.date,
	S.people
from 
	Stadium S, S100
where
	S.id between S100.id1 and S100.id2
order by S.id

-- MySQL
select distinct
	S.id,
	S.date,
	S.people
from 
	Stadium S, (
	select 
		S1.id as id1, 
		S2.id as id2
	from 
		Stadium S1, Stadium S2
	where
		S2.id - S1.id >= 2 and
		not exists (
			select S3.id 
			from Stadium S3 
			where 
				S3.people < 100 and 
				S3.id between S1.id and S2.id
		)
    ) S100
where
	S.id between S100.id1 and S100.id2
order by S.id