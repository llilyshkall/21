WITH orders AS (
    SELECT
        p.name AS name,
        count(*) AS count,
        'order' AS action_type
    FROM person_order
    JOIN public.menu m on m.id = person_order.menu_id
    JOIN public.pizzeria p on p.id = m.pizzeria_id
    GROUP BY 1
    ),
     visits AS (
    SELECT
        p2.name AS name,
        count(*) AS count,
        'visit' AS action_type
    FROM person_visits
    JOIN public.pizzeria p2 on person_visits.pizzeria_id = p2.id
    GROUP BY 1
    )
SELECT
    pizzeria.name,
    (case when orders.name is null then 0 else orders.count end) +
    (case when visits.name is null then 0 else visits.count end) AS total_count
FROM pizzeria
FULL JOIN orders ON orders.name = pizzeria.name
FULL JOIN visits ON visits.name = pizzeria.name
ORDER BY 2 DESC, 1;