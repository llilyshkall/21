CREATE OR REPLACE FUNCTION func_minimum(variadic arr numeric[])
RETURNS NUMERIC AS $$
    SELECT min($1[i])
    FROM generate_subscripts($1, 1) g(i);
$$ language sql;

SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);