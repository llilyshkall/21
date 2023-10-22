WITH tmp AS (SELECT pizza_name,
                    price,
                    p.id AS pizzeria_id,
                    name AS pizzeria_name
             FROM menu m
             JOIN public.pizzeria p on p.id = m.pizzeria_id),
     pop AS (SELECT *
             FROM tmp)
SELECT tmp.pizza_name,
       tmp.pizzeria_name AS pizzeria_name_1,
       pop.pizzeria_name AS pizzeria_name_2,
       tmp.price
FROM tmp
JOIN pop on tmp.price = pop.price
WHERE tmp.pizza_name = pop.pizza_name AND
      tmp.pizzeria_id > pop.pizzeria_id
ORDER BY 1;