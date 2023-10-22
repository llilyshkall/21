SELECT
    COALESCE(PER.name, '-') AS PERSON_NAME,
    PV.visit_date,
    COALESCE(PIZ.name, '-') AS PIZZERIA_NAME
FROM
    (SELECT
         *
     FROM
         person_visits
     WHERE
         visit_date BETWEEN '2022-01-01' AND '2022-01-03') PV
FULL JOIN person PER ON PV.person_id = PER.id
FULL JOIN pizzeria PIZ ON PV.pizzeria_id = PIZ.id
order by 1, 3, 2;