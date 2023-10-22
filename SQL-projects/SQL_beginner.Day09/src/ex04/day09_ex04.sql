CREATE OR REPLACE FUNCTION fnc_persons_female()
RETURNS SETOF person AS $$
    SELECT *
    FROM person WHERE gender = 'female'
$$ language sql;

CREATE OR REPLACE FUNCTION fnc_persons_male()
RETURNS SETOF person AS $$
    SELECT *
    FROM person WHERE gender = 'male'
$$ language sql;

SELECT * FROM fnc_persons_male();
SELECT * FROM fnc_persons_female();