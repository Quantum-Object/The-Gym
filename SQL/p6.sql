

CREATE PROC p

AS
SELECT C.name,A.name FROM (company_county R  INNER JOIN  company C ON C.ID=R.company_id) inner JOIN  Country A ON 
A.ID= R.Country_id ORDER BY A.name  DESC 


