CREATE OR REPLACE VIEW v_generated_dates AS
SELECT date(generated_date) as generated_date
FROM generate_series('2022-01-01'::date, '2022-01-31', '1 day'::interval) as generated_date
ORDER BY 1;