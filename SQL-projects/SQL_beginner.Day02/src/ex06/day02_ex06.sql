SELECT
    pizza_name,
    P.name AS PIZZERIA_NAME
FROM
    menu
JOIN public.person_order PO ON menu.id = PO.menu_id
JOIN public.pizzeria P ON menu.pizzeria_id = P.id
JOIN public.person P2 ON P2.id = PO.person_id
WHERE
    P2.name='Denis' OR
    P2.name='Anna'
ORDER BY 1, 2;