SELECT 
    pizza_name, 
    price, 
    P.name AS PIZZERIA_NAME
FROM menu
LEFT JOIN public.person_order PO ON menu.id = PO.menu_id
LEFT JOIN public.pizzeria P ON menu.pizzeria_id = P.id
WHERE PO.person_id IS NULL
ORDER BY 1, 2;