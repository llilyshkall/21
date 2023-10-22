CREATE OR REPLACE VIEW v_price_with_discount AS
SELECT
    p.name AS name,
    m.pizza_name AS pizza_name,
    m.price AS price,
    round(m.price - m.price * 0.1)::integer AS discount_price
FROM person_order
JOIN public.person p on p.id = person_order.person_id
JOIN public.menu m on m.id = person_order.menu_id
ORDER BY 1, 2;
