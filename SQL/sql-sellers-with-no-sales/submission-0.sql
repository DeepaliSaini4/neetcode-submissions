select s.seller_name
from seller s
left join 
(
    select o.sale_date, seller_id
    from orders o
    where EXTRACT(YEAR FROM sale_date) = 2020
) o
on o.seller_id = s.seller_id
where o.sale_date IS NULL
order by s.seller_name;
