-- LeetCode #176: Second Highest Salary
-- https://leetcode.com/problems/second-highest-salary/
(SELECT 
	Salary AS SecondHighestSalary 
FROM 
	Employee 
WHERE
	Salary < (SELECT MAX(Salary) FROM Employee)
ORDER BY 
	Salary DESC
LIMIT 1)
UNION
(SELECT NULL AS SecondHighestSalary)
LIMIT 1

-- solutions from the site
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary

SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary

SELECT 
	MAX(Salary)
FROM 
	Employee
WHERE
	 Salary < (SELECT MAX(Salary) FROM Employee)
