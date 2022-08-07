-- https://leetcode.com/problems/consecutive-numbers/

# Write your MySQL query statement below
select distinct num as ConsecutiveNums from Logs as l1 inner join Logs as l2 using(num) inner join Logs as l3 using(num) where l1.id=l2.id-1 and l2.id=l3.id-1;