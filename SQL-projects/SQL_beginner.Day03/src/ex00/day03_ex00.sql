SELECT 
    menu.pizza_name, 
    menu.price,
    pizzeria.name AS PIZZERIA_NAME, 
    person_visits.visit_date
FROM
    person
JOIN public.person_visits ON person_visits.person_id = person.id
JOIN public.pizzeria ON pizzeria.id = person_visits.pizzeria_id
JOIN public.menu ON pizzeria.id = menu.pizzeria_id
WHERE
    price >= 800 AND price <= 1000 AND person.name='Kate'
ORDER BY 1, 2, 3;