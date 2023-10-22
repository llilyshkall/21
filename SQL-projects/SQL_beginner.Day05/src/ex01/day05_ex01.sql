SET enable_seqscan TO OFF;

EXPLAIN ANALYSE
SELECT pizza_name, p.name AS pizzeria_name
FROM menu
JOIN public.pizzeria p on p.id = menu.pizzeria_id;
