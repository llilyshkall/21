SELECT DISTINCT p.name AS PIZZERIA_NAME
FROM pizzeria p
JOIN public.person_visits pv on p.id = pv.pizzeria_id
JOIN public.person p2 on pv.person_id = p2.id
WHERE p2.name='Andrey'
EXCEPT
SELECT DISTINCT p3.name AS PIZZERIA_NAME
FROM menu m
JOIN public.person_order po on m.id = po.menu_id
JOIN public.pizzeria p3 on m.pizzeria_id = p3.id
JOIN public.person p4 on p4.id = po.person_id
WHERE p4.name='Andrey'
ORDER BY 1;