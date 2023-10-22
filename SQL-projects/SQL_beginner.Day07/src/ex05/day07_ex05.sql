SELECT DISTINCT
    p.name
FROM person_order
JOIN person p on person_order.person_id = p.id
ORDER BY 1;