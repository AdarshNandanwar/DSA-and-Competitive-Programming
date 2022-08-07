-- https://leetcode.com/problems/department-top-three-salaries/

# Write your MySQL query statement below
select Department, Employee, salary 
from (
    select d.name as Department, e2.name as Employee, salary, (
        select distinct salary from Employee e1 where e1.departmentId=e2.departmentId order by salary desc limit 1 offset 2
    ) as cutoff 
    from Employee e2 
    left join Department d 
    on e2.departmentId=d.id
) t 
where cutoff is null or salary>=cutoff;