/*
185. Department Top Three Salaries
https://leetcode.com/problems/department-top-three-salaries/
Sample Input:

Employee
+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
| 5  | Janet | 69000  | 1            |
| 6  | Randy | 85000  | 1            |
+----+-------+--------+--------------+
Department 
+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+

Sample Outout:
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| IT         | Randy    | 85000  |
| IT         | Joe      | 70000  |
| Sales      | Henry    | 80000  |
| Sales      | Sam      | 60000  |
+------------+----------+--------+
*/
with SalaryRanked as
(
	select 
		DepartmentId,
		Salary,
		dense_rank() over (partition by DepartmentId order by Salary desc) as SalaryRank
	from
		Employee
)
select distinct
	D.Name as Department,
	E.Name as Employee,
	SR.Salary as Salary
from
	SalaryRanked SR
	join Department D on SR.DepartmentId = D.Id
	join Employee E on E.DepartmentId = SR.DepartmentId and E.Salary = SR.Salary
where 
	SR.SalaryRank <= 3
order by 
	D.Name,
	SR.Salary desc,
	E.Name