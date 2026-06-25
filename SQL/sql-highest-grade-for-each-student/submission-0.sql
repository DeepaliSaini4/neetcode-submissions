select s.student_id, min(s.exam_id)as exam_id,top.max_score as score
from exam_results s
join (
    select student_id,max(score) as max_score
    from exam_results
    group by student_id
)as top
on s.student_id = top.student_id 
and s.score = top.max_score
group by s.student_id, top.max_score
ORDER BY s.student_id ASC;