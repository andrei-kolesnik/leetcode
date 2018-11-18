/*
180. Consecutive Numbers
https://leetcode.com/problems/consecutive-numbers/
*/
select 
	distinct L1.Num as ConsecutiveNums
from 
	Logs L1
	join Logs L2 on L1.Num = L2.Num and L1.Id = L2.Id - 1
	join Logs L3 on L2.Num = L3.Num and L2.Id = L3.Id - 1
order by 1
