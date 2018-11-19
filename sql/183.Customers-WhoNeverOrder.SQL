/*
183. Customers Who Never Order
https://leetcode.com/problems/customers-who-never-order/
*/
select Name as Customers from Customers
where not exists (select Id from Orders where Customers.Id = Orders.CustomerId)