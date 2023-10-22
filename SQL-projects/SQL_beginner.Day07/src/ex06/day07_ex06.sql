SELECT
   p.name,
   count(*) AS count_of_orders,
   round(avg(m.price), 2) AS average_price,
   MAX(m.price) AS max_price,
   MIN(m.price) AS min_price
FROM person_order po
JOIN public.menu m on po.menu_id = m.id
JOIN public.pizzeria p on m.pizzeria_id = p.id
GROUP BY 1
ORDER BY 1;