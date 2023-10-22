WITH DAYS AS
    (SELECT generate_series('2022-01-01', '2022-01-10', '1 day'::INTERVAL) AS MISSING_DATE)
SELECT
    days.MISSING_DATE::DATE
FROM days
LEFT JOIN (SELECT
               *
           FROM
               person_visits
           WHERE person_id < 3) AS PV ON days.MISSING_DATE = PV.visit_date
WHERE PV.visit_date IS NULL;