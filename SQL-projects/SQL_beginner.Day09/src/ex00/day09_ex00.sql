CREATE TABLE IF NOT EXISTS person_audit (
    created timestamp with time zone default now() not null,
    type_event char(1) not null default 'I',
    row_id bigint not null,
    name varchar not null ,
    age integer not null ,
    gender varchar not null ,
    address varchar,
    constraint ch_type_event check (type_event = 'I' or type_event = 'U' or type_event = 'D')
);
CREATE OR REPLACE FUNCTION fnc_trg_person_insert_audit()
RETURNS TRIGGER AS $person_audits$
    BEGIN if (TG_OP = 'INSERT') then
    INSERT INTO person_audit SELECT now(), 'I', NEW.*;
end if;
    RETURN null;
end;
    $person_audits$ language plpgsql;

CREATE OR REPLACE TRIGGER trg_person_insert_audit AFTER INSERT ON person
    for each row execute FUNCTION fnc_trg_person_insert_audit();

INSERT INTO person(id, name, age, gender, address)
VALUES (10, 'Damir', 22, 'male', 'Irkutsk');