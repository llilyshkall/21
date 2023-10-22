SELECT
    p.name,
    count(*) AS count_of_visits
FROM person_visits
JOIN public.person p on p.id = person_visits.person_id
GROUP BY 1
HAVING count(*) > 3;