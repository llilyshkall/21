CREATE OR REPLACE FUNCTION fnc_trg_person_update_audit()
RETURNS TRIGGER AS $person_audit$
    begin if (TG_OP = 'UPDATE') then
    insert into person_audit SELECT now(), 'U', OLD.*;
    RETURN OLD;
end if;
    RETURN null;
end;
    $person_audit$ language plpgsql;

CREATE OR REPLACE TRIGGER trg_person_update_audit AFTER INSERT ON person
for each row execute function fnc_trg_person_update_audit();

UPDATE person SET name = 'Bulat' WHERE id = 10;
UPDATE person SET name = 'Danil' WHERE id = 10;