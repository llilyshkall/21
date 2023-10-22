DROP FUNCTION IF EXISTS fnc_persons_male();
DROP FUNCTION IF EXISTS fnc_persons_female();

CREATE OR REPLACE FUNCTION fnc_persons(in pgender varchar default 'female')
RETURNS SETOF person AS $$
    SELECT * FROM person WHERE gender = pgender
$$ language sql;
