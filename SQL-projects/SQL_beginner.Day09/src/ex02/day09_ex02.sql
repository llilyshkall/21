CREATE OR REPLACE FUNCTION fnc_trg_person_delete_audit ()
RETURNS TRIGGER AS $trg_person_delete_audit$
    begin if (tg_op = 'DELETE') then
    INSERT INTO person_audit SELECT now(), 'D', OLD.*;
end if;
        RETURN null;
end;
$trg_person_delete_audit$ language plpgsql;

CREATE OR REPLACE TRIGGER trg_person_delete_audit AFTER DELETE ON person
    for each row execute FUNCTION fnc_trg_person_delete_audit();

DELETE FROM person WHERE id = 10;