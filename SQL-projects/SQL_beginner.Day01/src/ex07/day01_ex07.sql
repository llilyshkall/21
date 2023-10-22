SELECT
    order_date, CONCAT(name, ' (age:', age, ')') AS PERSON_INFORMATION
FROM
    person_order
JOIN public.person on person_order.person_id = person.id
ORDER BY 1, 2;