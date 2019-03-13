SET SERVEROUTPUT ON
SET VERIFY OFF

ACCEPT Reg_ID NUMBER PROMPT 'Enter Region Id: ';
DECLARE

TYPE countryNames_type IS TABLE OF COUNTRIES.COUNTRY_NAME%TYPE
INDEX BY BINARY_INTEGER;
countryNames countryNames_type;

CURSOR c1 IS 
SELECT region_id, COUNTRIES.country_id, COUNTRY_NAME FROM countries LEFT JOIN LOCATIONS ON COUNTRIES.COUNTRY_ID = LOCATIONS.COUNTRY_ID
WHERE LOCATIONS.COUNTRY_ID IS NULL
ORDER BY COUNTRY_NAME;
noCity c1%ROWTYPE;

CURSOR c2 IS 
SELECT region_id, COUNTRIES.country_id, country_name
FROM COUNTRIES
LEFT JOIN LOCATIONS
ON COUNTRIES.COUNTRY_ID = LOCATIONS.COUNTRY_ID
WHERE LOCATIONS.COUNTRY_ID IS NULL AND COUNTRIES.REGION_ID = &Reg_ID ORDER BY COUNTRY_NAME;
noRegion c2%ROWTYPE;

CURSOR c3 IS 
SELECT region_id, COUNTRIES.country_id, COUNTRY_NAME FROM countries LEFT JOIN LOCATIONS ON COUNTRIES.COUNTRY_ID = LOCATIONS.COUNTRY_ID
WHERE LOCATIONS.COUNTRY_ID IS NULL for update
ORDER BY COUNTRY_NAME;
cityUpdate c3%ROWTYPE;

v_rows NUMBER;
v_regID varchar2(7);
v_valueGet NUMBER;
v_2ndval varchar2(40);
v_2ndlast varchar2(40);
BEGIN

SELECT COUNT(*) INTO v_rows FROM REGIONS WHERE REGION_ID = &Reg_ID; 

OPEN c3;
LOOP
FETCH c3 INTO noRegion;
EXIT WHEN c3%NOTFOUND;

	UPDATE COUNTRIES
	SET
	flag = ('EMPTY_' + noRegion.REGION_ID)
	WHERE
	CURRENT OF c3;
	
END LOOP;
CLOSE c3;

v_rows := 1;
OPEN c1;
LOOP
FETCH c1 INTO noCity;
EXIT WHEN c1%NOTFOUND;
countryNames(v_rows) := noCity.COUNTRY_NAME;

v_rows := v_rows + 5;

END LOOP;
CLOSE c1;
v_rows := 0;
v_valueGet := countryNames.FIRST;

WHILE v_valueGet IS NOT NULL LOOP
v_rows := v_rows + 1;
DBMS_OUTPUT.PUT_LINE('Index Table Key: '||v_valueGet||' has a value of '||countryNames(v_valueGet));
v_valueGet := countryNames.NEXT(v_valueGet);
END LOOP;

DBMS_OUTPUT.PUT_LINE('=====================================================');
DBMS_OUTPUT.PUT_LINE('Total number of elements in index tabl or Number of countries with NO cities is: '||v_rows);
v_2ndval := countryNames.FIRST;
v_2ndval := countryNames.NEXT(v_2ndval);
DBMS_OUTPUT.PUT_LINE('Second element in index table is: '||v_2ndval);
v_2ndlast := countryNames.LAST;
v_2ndlast := countryNames.PRIOR(v_2ndval);
DBMS_OUTPUT.PUT_LINE('Second element in index table is: '||v_2ndlast);

DBMS_OUTPUT.PUT_LINE('=====================================================');

v_rows := 0;
OPEN c2;
LOOP
FETCH c2 INTO noRegion;
EXIT WHEN c2%NOTFOUND;

v_rows := v_rows + 1;
DBMS_OUTPUT.PUT_LINE('In the region '||&Reg_ID||' There is country '||noRegion.country_name||' with NO city.');

END LOOP;
CLOSE c2;

DBMS_OUTPUT.PUT_LINE('=====================================================');
DBMS_OUTPUT.PUT_LINE('Total # of countries with NO cities listed in the Region '||&Reg_ID||' is: '||v_rows);

EXCEPTION 
WHEN NO_DATA_FOUND THEN
DBMS_OUTPUT.PUT_LINE('This region ID does NOT exist: '||&Reg_ID);
END;
/
SELECT * FROM COUNTRIES;
ROLLBACK;