/*
626.Exchange-Seats.SQL
https://leetcode.com/problems/exchange-seats/
Input:
+---------+---------+
|    id   | student |
+---------+---------+
|    1    | Abbot   |
|    2    | Doris   |
|    3    | Emerson |
|    4    | Green   |
|    5    | Jeames  |
+---------+---------+
Output:
+---------+---------+
|    id   | student |
+---------+---------+
|    1    | Doris   |
|    2    | Abbot   |
|    3    | Green   |
|    4    | Emerson |
|    5    | Jeames  |
+---------+---------+

create table Seat (
	id int not null,
	student varchar(16) not null
);

insert into Seat (id, student)
values
(1, 'Abbot'),
(2, 'Doris'),
(3, 'Emerson'),
(4, 'Green'),
(5, 'Jeames')
*/
select 
	case when id % 2 = 0 then id-1 else 
		case when id = (select count(*) from seat) then id else id+1 end 
	end as id, 
	student
from 
	Seat
order by 1;