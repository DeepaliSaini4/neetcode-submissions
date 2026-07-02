select u.name, COALESCE(r.td,0) as travelled_distance
from users u
left join 
( select user_id, sum(distance) as td
 from rides
 group by user_id
)r on r.user_id = u.id
order by travelled_distance DESC, u.name ASC;

