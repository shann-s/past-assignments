DECLARE
c_con constant varchar2(5) := '704b';
b_decision boolean;
v_namestring varchar2(32);
v_numbers number (8,2);
v_currentdate DATE := sysdate;
BEGIN
v_currentdate := v_currentdate+7;
DBMS_OUTPUT.PUT_LINE('Constant variable: '||c_con);
DBMS_OUTPUT.PUT_LINE('One week from today: '||v_currentdate);
IF (v_namestring LIKE '%SQL%') 
	then
	DBMS_OUTPUT.PUT_LINE('DBS501');
ELSE
	IF c_con = '704b' THEN
		IF v_namestring IS NOT NULL THEN
			DBMS_OUTPUT.PUT_LINE('Course Name: '||v_namestring||' Room Name: '||c_con);
		ELSE
			DBMS_OUTPUT.PUT_LINE('Course is unknown. Room Name: '||c_con);
		END IF;
	ELSE
		DBMS_OUTPUT.PUT_LINE('Course and Location could not be detemined');
	END IF;
END IF;
END;
/
