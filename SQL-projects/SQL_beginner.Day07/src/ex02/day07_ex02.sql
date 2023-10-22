(SELECT
    p.name AS name,
    count(*) AS count,
    'order' AS action_type
FROM person_order
JOIN public.menu m on m.id = person_order.menu_id
JOIN public.pizzeria p on p.id = m.pizzeria_id
GROUP BY 1
ORDER BY 3, 2 DESC
LIMIT 3)
UNION ALL
(SELECT
    p2.name AS name,
    count(*) AS count,
    'visit' AS action_type
FROM person_visits
JOIN public.pizzeria p2 on person_visits.pizzeria_id = p2.id
GROUP BY 1
ORDER BY 3, 2 DESC
LIMIT 3)
ORDER BY 3, 2 DESC;

