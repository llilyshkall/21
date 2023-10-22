CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats AS
SELECT p.name AS pizzeria_name
FROM person
JOIN public.person_visits pv on person.id = pv.person_id
JOIN public.pizzeria p on p.id = pv.pizzeria_id
JOIN public.menu m on m.pizzeria_id = pv.pizzeria_id
WHERE person.name = 'Dmitriy' AND
      pv.visit_date = '2022-01-08' AND
      m.price < 800;