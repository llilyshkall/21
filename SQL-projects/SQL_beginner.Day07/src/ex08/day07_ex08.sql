SELECT
    p.address,
    p2.name,
    count(*) count_of_orders
FROM person_order
JOIN public.person p on person_order.person_id = p.id
JOIN public.menu m on person_order.menu_id = m.id
JOIN public.pizzeria p2 on m.pizzeria_id = p2.id
GROUP BY 1, 2
ORDER BY 1 ,2;