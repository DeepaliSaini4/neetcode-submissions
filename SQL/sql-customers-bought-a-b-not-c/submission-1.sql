select c.customer_id, c.customer_name
from customers c 
LEFT JOIN orders o
on c.customer_id = o.customer_id
group by c.customer_id
having count(distinct case when o.product_name ='A' then 1 end)>0
        and count(distinct case when o.product_name = 'B' then 1 end)>0 
        and count(distinct case when o.product_name='C' then 0 end) = 0
order by c.customer_name;
