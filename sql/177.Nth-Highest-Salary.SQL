/*
LeetCode# 177: Nth Highest Salary
https://leetcode.com/problems/nth-highest-salary/
*/

CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        /* Write your T-SQL query statement below. */
        select max(Salary) from 
        (
            select 
                Salary,	
                dense_rank() over (order by Salary desc) as RankNum
            from 
                Employee
        ) SalaryRanked 
        where RankNum = @N
        /* End of your T-SQL query. */
    );
END

--print dbo.getNthHighestSalary(1)
