SET SERVEROUTPUT ON
SET VERIFY OFF

VARIABLE LNAME VARCHAR2(225);
VARIABLE FNAME VARCHAR2(225);

CREATE OR REPLACE FUNCTION valid_stud (
StudID IN STUDENT.STUDENT_ID%TYPE
)
RETURN BOOLEAN IS
v_rows NUMBER;
BEGIN
v_rows := 0;
SELECT COUNT(*) INTO v_rows FROM STUDENT WHERE STUDENT_ID = StudID;
if(v_rows = 0) THEN
	return false;
else
	return true;
end if;
END valid_stud;
/

CREATE OR REPLACE PACKAGE manage_stud IS

PROCEDURE find_stud
(
ID IN NUMBER,
LASTNAME OUT VARCHAR2,
FIRSTNAME OUT VARCHAR2
);

PROCEDURE drop_stud
(
STUD_ID IN NUMBER,
FLAG IN CHAR
);

END manage_stud;
/

CREATE OR REPLACE PACKAGE BODY manage_stud IS 

PROCEDURE find_stud
(
ID IN NUMBER,
LASTNAME OUT VARCHAR2,
FIRSTNAME OUT VARCHAR2
)
IS
V_STUDID NUMBER;
BEGIN

SELECT LAST_NAME INTO LASTNAME FROM STUDENT WHERE STUDENT_ID = ID;
SELECT FIRST_NAME INTO FIRSTNAME FROM STUDENT WHERE STUDENT_ID = ID;
SELECT STUDENT_ID INTO V_STUDID FROM STUDENT WHERE STUDENT_ID = ID;

EXCEPTION
WHEN NO_DATA_FOUND THEN
	DBMS_OUTPUT.PUT_LINE('There is NO Student with the Id of: '||V_STUDID);
END find_stud;

PROCEDURE drop_stud
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
END drop_stud;
END manage_stud;
/

EXECUTE manage_stud.find_stud(110, :LNAME, :FNAME);
PRINT :LNAME;
PRINT :FNAME;