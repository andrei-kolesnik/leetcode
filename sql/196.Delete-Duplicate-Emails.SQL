/*
LeetCode 196. Delete Duplicate Emails
https://leetcode.com/problems/delete-duplicate-emails/

Sample Input:

truncate table Person
insert into Person (Id, Email) values
(1, 'john@example.com'),
(2, 'bob@example.com'),
(3, 'john@example.com')

Sample Output:
+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
*/

delete from Person where Id in (
	select P1.Id 
	from (select * from Person) P1 
	join (select * from Person) P2 on P1.Email = P2.Email and P1.Id > P2.Id
);
select * from Person;
