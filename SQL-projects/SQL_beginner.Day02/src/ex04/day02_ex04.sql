SELECT
    pizza_name AS PIZZA_NAME,
    p.name AS PIZZERIA_NAME,
    price
FROM
    menu
JOIN public.pizzeria p ON menu.pizzeria_id = p.id
WHERE
    menu.pizza_name = 'pepperoni pizza' OR
    menu.pizza_name = 'mushroom pizza'
order by 1, 2;