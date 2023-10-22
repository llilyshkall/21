SELECT
    order_date, CONCAT(name, ' (age:', age, ')') AS PERSON_INFORMATION
FROM
    person_order
NATURAL JOIN (SELECT name, age, id AS person_id FROM person) AS person
ORDER BY 1, 2;