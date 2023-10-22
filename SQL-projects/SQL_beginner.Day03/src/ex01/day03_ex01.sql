SELECT
    id AS MENU_ID
FROM
    menu
EXCEPT
SELECT
    menu_id
FROM person_order
ORDER BY 1;