SELECT c.name as name
FROM customers c 
LEFT JOIN orders o
on o.customer_id =c.id
where o.id IS NULL;
