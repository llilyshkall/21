CREATE OR REPLACE FUNCTION fnc_fibonacci (in pstop integer default 10)
RETURNS SETOF integer language SQL AS $$
    WITH RECURSIVE f(a,b) AS (
            VALUES (0,1)
        UNION ALL
            SELECT
                greatest(a,b),
                a + b AS a
            FROM f
            WHERE b < pstop
       )
    select a from f;
$$;

select * from fnc_fibonacci(100);
select * from fnc_fibonacci();