WITH female AS (SELECT p.name AS PIZZERIA_NAME
                FROM person_order po
                JOIN public.menu m on po.menu_id = m.id
                JOIN public.pizzeria p on p.id = m.pizzeria_id
                JOIN public.person p2 on p2.id = po.person_id
                WHERE gender='female'),
    male AS (SELECT p.name AS PIZZERIA_NAME
                FROM person_order po
                JOIN public.menu m on po.menu_id = m.id
                JOIN public.pizzeria p on p.id = m.pizzeria_id
                JOIN public.person p2 on p2.id = po.person_id
                WHERE gender='male')
(SELECT *
FROM male
EXCEPT
SELECT *
FROM female)
UNION
(SELECT *
FROM female
EXCEPT
SELECT *
FROM male)
