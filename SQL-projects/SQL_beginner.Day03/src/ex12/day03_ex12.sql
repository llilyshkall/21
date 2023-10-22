INSERT INTO person_order (id, person_id, menu_id, order_date)
SELECT (SELECT MAX(id) FROM person_order) + gen_id AS id,
        person.id AS person_id,
        (SELECT id FROM menu WHERE pizza_name='greek pizza'),
        '2022-02-25' AS order_date
FROM generate_series(1, (SELECT COUNT(*) FROM person)) AS gen_id
INNER JOIN person on id = gen_id;