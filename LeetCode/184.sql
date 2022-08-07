-- https://leetcode.com/problems/department-highest-salary/

# Write your MySQL query statement below
select d.name as Department, e.name as Employee, salary from Employee as e left join Department as d on e.departmentId=d.id where salary=(select max(salary) from Employee as e2 where e2.departmentId=e.departmentId);