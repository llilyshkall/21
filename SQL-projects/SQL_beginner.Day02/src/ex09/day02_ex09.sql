SELECT
    person.name
FROM
    person
JOIN public.person_order PO ON person.id = po.person_id
JOIN public.menu M ON M.id = po.menu_id
WHERE gender = 'female' AND
      M.pizza_name IN ('pepperoni pizza', 'cheese pizza')
GROUP BY person.name
HAVING COUNT(M.pizza_name) > 1
ORDER BY 1;
