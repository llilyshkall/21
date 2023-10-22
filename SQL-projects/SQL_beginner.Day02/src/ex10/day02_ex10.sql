SELECT
    pn1.name AS PERSON_NAME1,
    pn2.name AS PERSON_NAME2,
    pn1.address AS COMMON_ADDRESS
from
    person as PN1
JOIN public.person PN2 ON PN1.address = PN2.address
WHERE
    PN1.address = PN2.address AND
    PN1.id > PN2.id
ORDER BY 1, 2, 3;