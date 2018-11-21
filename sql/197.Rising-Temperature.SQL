/*
LeetCode 197. Rising Temperature
https://leetcode.com/problems/rising-temperature/

Sample Input:
+---------+------------------+------------------+
| Id(INT) | RecordDate(DATE) | Temperature(INT) |
+---------+------------------+------------------+
|       1 |       2015-01-01 |               10 |
|       2 |       2015-01-02 |               25 |
|       3 |       2015-01-03 |               20 |
|       4 |       2015-01-04 |               30 |
+---------+------------------+------------------+
Sample Output:
+----+
| Id |
+----+
|  2 |
|  4 |
+----+
*/
select 
	W2.Id
from 
	Weather W1
	cross join Weather W2
where
	datediff(dd, W1.RecordDate, W2.RecordDate) = 1
	and W2.Temperature > W1.Temperature 