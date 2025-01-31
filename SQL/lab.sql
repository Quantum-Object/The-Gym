CREATE PROCEDURE Empp
AS
SELECT E.emp_name,C.city_name,D.dept_name
FROM 
Employee E INNER JOIN City C ON  E.city_id=C.city_id
LEFT OUTER JOIN department D ON E.de_id=D.de_id



EXEC Empp;