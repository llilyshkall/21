SELECT
    visit_date AS action_date,
    (SELECT
         name
     FROM
         person
     WHERE person_visits.person_id = person.id) AS PERSON_NAME
FROM
    person_visits
INTERSECT
SELECT
    order_date AS action_date,
    (SELECT
         name
     FROM
         person
     WHERE person_order.person_id = person.id) AS PERSON_NAME
FROM
    person_order
ORDER BY action_date, PERSON_NAME DESC;