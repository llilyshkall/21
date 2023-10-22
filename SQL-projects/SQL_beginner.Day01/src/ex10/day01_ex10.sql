SELECT
    p.name AS PERSON_NAME, m.pizza_name AS PIZZA_NAME, p2.name AS PIZZERIA_NAME
FROM
    person_order
JOIN person p on person_order.person_id = p.id
JOIN public.menu m on m.id = person_order.menu_id
JOIN public.pizzeria p2 on m.pizzeria_id = p2.id
ORDER BY 1, 2, 3;
