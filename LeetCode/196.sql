-- https://leetcode.com/problems/delete-duplicate-emails/

# Write your MySQL query statement below
delete from Person where id in (
    select id from (
        select id from Person p1 where id <> (select min(id) from Person p2 where p1.email=p2.email)
    ) t
);