CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(
    in pperson varchar default 'Dmitriy',
    in pprice numeric default 500,
    in pdate date default '2022-01-08'::date)

RETURNS TABLE(pizzeria varchar) AS $$
    BEGIN
        RETURN QUERY
            SELECT pizzeria.name FROM pizzeria
                JOIN public.person_order po on pizzeria.id = po.person_id
                JOIN public.menu m on m.id = po.menu_id
                JOIN public.person_visits pv on pizzeria.id = pv.person_id
                JOIN public.person p on p.id = po.person_id
                WHERE p.name = pperson AND
                      m.price < pprice AND
                      po.order_date = pdate AND
                      pv.visit_date = pdate;
        RETURN ;
    END;
$$ language plpgsql;
