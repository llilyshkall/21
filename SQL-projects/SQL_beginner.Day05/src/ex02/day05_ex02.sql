CREATE INDEX idx_person_name ON person(upper(name));

SET enable_seqscan TO OFF;

EXPLAIN ANALYSE
SELECT name
FROM person;