SET SERVEROUTPUT ON
SET VERIFY OFF

CREATE OR REPLACE PROCEDURE drop_stud
(
STUD_ID IN NUMBER,
FLAG IN CHAR
) IS
v_flag char(1);
v_rows NUMBER;
v_tot NUMBER;
noStudent EXCEPTION;
BEGIN

v_rows := 0;
v_tot := 0;

SELECT COUNT(*) INTO v_rows FROM STUDENT WHERE STUDENT_ID = STUD_ID;

IF (v_rows = 0) THEN
	raise noStudent;
END IF;

v_rows := 0;

IF (FLAG = '') THEN
	v_flag := 'R';
ELSE
	v_flag := FLAG;
END IF;


IF (v_flag = 'R') THEN
	SELECT count(*) into v_rows from enrollment where STUDENT_ID = STUD_ID;
	
	IF (v_rows = 0) THEN
	DELETE FROM STUDENT WHERE STUDENT_ID = STUD_ID;
	DBMS_OUTPUT.PUT_LINE('Student with ID : '||STUD_ID||' is removed. He/she was NOT enrolled in any courses');
	ELSE
	DBMS_OUTPUT.PUT_LINE('Student with ID: '||STUD_ID||' is enrolled in one or more courses. His/her removal is denied.');
	END IF;
	
ELSIF (v_flag = 'C') THEN

	SELECT COUNT(*) INTO v_rows FROM GRADE WHERE STUDENT_ID = STUD_ID;
	v_tot := v_tot + v_rows;
	DELETE FROM GRADE WHERE STUDENT_ID = STUD_ID;
	
	SELECT COUNT(*) INTO v_rows FROM ENROLLMENT WHERE STUDENT_ID = STUD_ID;
	v_tot := v_tot + v_rows;
	DELETE FROM ENROLLMENT WHERE STUDENT_ID = STUD_ID;	
	
	SELECT COUNT(*) INTO v_rows FROM STUDENT WHERE STUDENT_ID = STUD_ID;
	v_tot := v_tot + v_rows;
	DELETE FROM STUDENT WHERE STUDENT_ID = STUD_ID;
	
	DBMS_OUTPUT.PUT_LINE('Student with the Id of : '||STUD_ID||' is removed. Total # of rows deleted: '||v_tot);

END IF;

EXCEPTION
WHEN noStudent THEN
DBMS_OUTPUT.PUT_LINE('Student with the Id of: '||STUD_ID||' does NOT exist. Try again.');
END;
/

EXECUTE drop_stud(210, 'R');

EXECUTE drop_stud(410, 'R');

EXECUTE drop_stud(310, 'R');
ROLLBACK;

EXECUTE drop_stud(110, 'C');
ROLLBACK;