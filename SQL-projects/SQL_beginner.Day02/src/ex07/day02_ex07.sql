SELECT
    P.name as PIZZERIA_NAME
FROM
    person
JOIN public.person_visits PV ON person.id = PV.person_id
JOIN public.pizzeria P ON P.id = PV.pizzeria_id
JOIN public.menu M ON M.pizzeria_id = PV.pizzeria_id
WHERE
    person.name='Dmitriy' AND
    PV.visit_date='2022-01-08' AND
    M.price<800;