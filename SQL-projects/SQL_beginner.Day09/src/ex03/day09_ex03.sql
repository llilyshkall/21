DROP TRIGGER IF EXISTS trg_person_delete_audit ON person;
DROP TRIGGER IF EXISTS trg_person_insert_audit ON person;
DROP TRIGGER IF EXISTS trg_person_update_audit ON person;
DROP FUNCTION IF EXISTS fnc_trg_person_delete_audit();
DROP FUNCTION IF EXISTS fnc_trg_person_insert_audit();
DROP FUNCTION IF EXISTS fnc_trg_person_update_audit();

CREATE OR REPLACE FUNCTION fnc_trg_person_audit()
RETURNS TRIGGER AS $trg_person_audit$
    begin if (TG_OP = 'DELETE') then
        insert into person_audit SELECT now(), 'D', OLD.*;
    elsif (TG_OP = 'UPDATE') then
        insert into person_audit SELECT now(), 'U', OLD.*;
    elsif (TG_OP = 'INSERT') then
        insert into person_audit SELECT now(), 'I', NEW.*;
    end if;
        RETURN null;
    end;
    $trg_person_audit$ language plpgsql;

CREATE OR REPLACE TRIGGER trg_person_audit AFTER INSERT OR UPDATE OR DELETE ON person
    for each row execute FUNCTION fnc_trg_person_audit();

INSERT INTO person(id, name, age, gender, address)  VALUES (10,'Damir', 22, 'male', 'Irkutsk');
UPDATE person SET name = 'Bulat' WHERE id = 10;
UPDATE person SET name = 'Damir' WHERE id = 10;
DELETE FROM person WHERE id = 10;