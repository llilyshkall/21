SELECT
    person.name
FROM
    person
JOIN public.person_order PO ON person.id = po.person_id
JOIN public.menu M on M.id = PO.menu_id
WHERE (person.address='Moscow' OR person.address='Samara') AND
      (M.pizza_name='pepperoni pizza' OR M.pizza_name='mushroom pizza') AND
      person.gender = 'male'
ORDER BY 1 desc;