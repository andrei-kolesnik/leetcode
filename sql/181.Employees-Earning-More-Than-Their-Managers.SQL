/*
LeetCode 181. Employees Earning More Than Their Managers
https://leetcode.com/problems/employees-earning-more-than-their-managers/
*/
select 
	E.Name as Employee
from 
	Employee E
	join Employee M on E.ManagerID = M.Id and E.Salary > M.Salary