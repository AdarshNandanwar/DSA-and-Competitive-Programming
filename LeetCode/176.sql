-- https://leetcode.com/problems/second-highest-salary/

# Write your MySQL query statement below
select max(distinct salary) as secondHighestSalary from Employee where salary != (select max(distinct salary) from Employee);

# Write your MySQL query statement below
select max(salary) as secondHighestSalary from Employee where salary <> (select max(salary) from Employee);