/*
262. Trips and Users
https://leetcode.com/problems/trips-and-users/

Sample Input:

create table dbo.Users (
	[Users_Id] int not null primary key clustered,
	[Banned] char(3) not null ,
	[Role] char(6) not null 
)

insert into dbo.Users (Users_Id, Banned, Role )
values 
(1 , 'No', 'client'),
(2 , 'Yes', 'client'),
(3 , 'No', 'client'),
(4 , 'No', 'client'),
(10, 'No', 'driver'),
(11, 'No', 'driver'),
(12, 'No', 'driver'),
(13, 'No', 'driver')

+----------+--------+--------+
| Users_Id | Banned |  Role  |
+----------+--------+--------+
|    1     |   No   | client |
|    2     |   Yes  | client |
|    3     |   No   | client |
|    4     |   No   | client |
|    10    |   No   | driver |
|    11    |   No   | driver |
|    12    |   No   | driver |
|    13    |   No   | driver |
+----------+--------+--------+

create table dbo.Trips (
 Id int not null primary key clustered,
 Client_Id int not null,
 Driver_Id int not null,
 City_Id int not null,
 Status char(20) not null,
 Request_at date
 
insert into Trips (Id, Client_Id, Driver_Id, City_Id, Status, Request_at) values
(1, 1, 10, 1, 'completed', '2013-10-01'),
(2, 2, 11, 1, 'cancelled_by_driver', '2013-10-01'),
(3, 3, 12, 6, 'completed', '2013-10-01'),
(4, 4, 13, 6, 'cancelled_by_client', '2013-10-01'),
(5, 1, 10, 1, 'completed', '2013-10-02'),
(6, 2, 11, 6, 'completed', '2013-10-02'),
(7, 3, 12, 6, 'completed', '2013-10-02'),
(8, 2, 12, 12, 'completed', '2013-10-03'),
(9, 3, 10, 12, 'completed', '2013-10-03'),
(10, 4, 13, 12, 'cancelled_by_driver', '2013-10-03')

+----+-----------+-----------+---------+--------------------+----------+
| Id | Client_Id | Driver_Id | City_Id |        Status      |Request_at|
+----+-----------+-----------+---------+--------------------+----------+
| 1  |     1     |    10     |    1    |     completed      |2013-10-01|
| 2  |     2     |    11     |    1    | cancelled_by_driver|2013-10-01|
| 3  |     3     |    12     |    6    |     completed      |2013-10-01|
| 4  |     4     |    13     |    6    | cancelled_by_client|2013-10-01|
| 5  |     1     |    10     |    1    |     completed      |2013-10-02|
| 6  |     2     |    11     |    6    |     completed      |2013-10-02|
| 7  |     3     |    12     |    6    |     completed      |2013-10-02|
| 8  |     2     |    12     |    12   |     completed      |2013-10-03|
| 9  |     3     |    10     |    12   |     completed      |2013-10-03| 
| 10 |     4     |    13     |    12   | cancelled_by_driver|2013-10-03|
+----+-----------+-----------+---------+--------------------+----------+

Write a SQL query to find the cancellation rate of requests made by 
unbanned users between Oct 1, 2013 and Oct 3, 2013. 
For the above tables, your SQL query should return the following rows 
with the cancellation rate being rounded to two decimal places.

Sample Output:
+------------+-------------------+
|     Day    | Cancellation Rate |
+------------+-------------------+
| 2013-10-01 |       0.33        |
| 2013-10-02 |       0.00        |
| 2013-10-03 |       0.50        |
+------------+-------------------+
)
*/
with TripsUnbanned as (
	select 
		T.status,
		T.Request_at
	from 
		Trips T
		join Users Cli on T.Client_Id = Cli.Users_Id and Cli.Banned <> 'Yes'
		join Users Dri on T.Driver_Id = Dri.Users_Id and Dri.Banned <> 'Yes'
),
TripCountAll as
(
	select 
		Request_at, 
		count(*) as CountAll
	from 
		TripsUnbanned
	group by
		Request_at
),
TripCountCan as
(
	select 
		Request_at, 
		count(*) as CountCan
	from 
		TripsUnbanned
	where 
		Status like 'cancelled%'
	group by
		Request_at
)
select 
	TA.Request_at as 'Day',
	cast(isnull(TC.CountCan, 0) / cast(TA.CountAll as float) as decimal(4, 2)) as 'Cancellation Rate'
from 
	TripCountAll TA	
	left outer join TripCountCan TC on TA.Request_at = TC.Request_at
where 
	TA.Request_at between '2013-10-01' and '2013-10-03';
