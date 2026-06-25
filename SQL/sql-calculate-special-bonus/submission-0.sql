SELECT employee_id,
    CASE
        when employee_id%2!=0 AND left(name,1)!='M'
        THEN salary
        else 0
    END AS bonus
from employees
order by employee_id;