/*
LeetCode 197. Rising Temperature
https://leetcode.com/problems/rising-temperature/
*/
select 
	W2.Id
from 
	Weather W1
	cross join Weather W2
where
	datediff(dd, W1.RecordDate, W2.RecordDate) = 1
	and W2.Temperature > W1.Temperature 