/*
LeetCode 627. Swap Salary
https://leetcode.com/problems/swap-salary/
Input:
| id | name | sex | salary |
|----|------|-----|--------|
| 1  | A    | m   | 2500   |
| 2  | B    | f   | 1500   |
| 3  | C    | m   | 5500   |
| 4  | D    | f   | 500    |

Output:
| id | name | sex | salary |
|----|------|-----|--------|
| 1  | A    | m   | 2500   |
| 2  | B    | f   | 1500   |
| 3  | C    | m   | 5500   |
| 4  | D    | f   | 500    |

CREATE TABLE salary (
	id INT NOT NULL,
	name CHAR(1) NOT NULL,
	sex CHAR(1) NOT NULL,
	salary INT NOT NULL
);

TRUNCATE TABLE salary;
INSERT INTO salary (id, name, sex, salary)
VALUES
(1, 'A', 'm', 2500),
(2, 'B', 'f', 1500),
(3, 'C', 'm', 5500),
(4, 'D', 'f',  500);
*/
SELECT * FROM salary;

UPDATE salary 
SET sex = (CASE sex WHEN 'm' THEN 'f' WHEN 'f' THEN 'm' END)

