WITH female AS (SELECT
                    p.name AS PIZZERIA_NAME
                FROM
                    pizzeria p
                JOIN public.person_visits pv on P.id = pv.pizzeria_id
                JOIN public.person p2 on pv.person_id = p2.id
                WHERE p2.gender = 'female'),
    male AS (SELECT
                    p.name AS PIZZERIA_NAME
                FROM
                    pizzeria p
                JOIN public.person_visits pv on P.id = pv.pizzeria_id
                JOIN public.person p2 on pv.person_id = p2.id
                WHERE p2.gender = 'male')
(SELECT *
FROM male
EXCEPT ALL
SELECT *
FROM female)
UNION ALL
(SELECT *
FROM female
EXCEPT ALL
SELECT *
FROM male)
ORDER BY 1;

