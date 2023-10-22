SELECT
    name AS NAME,
    rating AS RATING
FROM
    pizzeria
LEFT JOIN public.person_visits PV ON pizzeria.id = pv.pizzeria_id
WHERE
    visit_date IS NULL;