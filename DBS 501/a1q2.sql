-- SET SERVEROUTPUT ON
ACCEPT user_input PROMPT 'Enter the beginning of the Course Description in UPPER case: '
DECLARE
  CURSOR c1 IS
  SELECT section_id, COUNT(student_id) num_of_std
  FROM section
  LEFT JOIN enrollment
  USING (section_id)
  WHERE course_no IN(
    SELECT DISTINCT course_no
      FROM course
      WHERE prerequisite IN (
        SELECT DISTINCT course_no
        FROM course
        WHERE UPPER(description) LIKE '&user_input%'))
  GROUP BY section_id
  ORDER BY section_id;
  
  sec_rec c1%ROWTYPE;  
BEGIN
  OPEN c1;
  FETCH c1 INTO sec_rec;
  
  IF c1%ROWCOUNT = 0 THEN
    DBMS_OUTPUT.PUT_LINE('There is NO PREREQUISITE course that starts on: &user_input.. Try again.');
  ELSE
    CLOSE c1;
    FOR idx IN c1 LOOP
      IF idx.num_of_std < 7 THEN
        DBMS_OUTPUT.PUT_LINE('There are ' || idx.num_of_std || ' students for section ID ' || idx.section_id );
      ELSE
        DBMS_OUTPUT.PUT_LINE('There are too many students for section ' || idx.section_id );
        DBMS_OUTPUT.PUT_LINE('^^^^^^^^^^^^^^^^^^^^^^^^^^' );
      END IF;
    END LOOP;
  END IF;
END;