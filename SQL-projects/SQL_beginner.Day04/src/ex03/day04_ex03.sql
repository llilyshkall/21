SELECT
    generated_date::DATE
FROM
    v_generated_dates
LEFT JOIN person_visits AS PV ON generated_date = PV.visit_date
WHERE PV.visit_date IS NULL;