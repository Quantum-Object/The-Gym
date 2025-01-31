--BNo Area ZIP Built
--BNo ANo Bedrooms Baths

SELECT
* FROM  Contract WHERE Tenant lIKE '% Sameh';


SELECT
* FROM Contract WHERE Rent*2 <= Balance;


SELECT * FROM

Building INNER JOIN Apartment ON Building.BNo = Apartment.BNo
WHERE (Bedrooms BETWEEN 2 AND 3) AND Baths = 2;



-- 1 1
SELECT * FROM Building B,(SELECT * FROM Apartment WHERE bedrooms = 1 and baths=1) AS X
WHERE B.BNo = X.BNo
GROUP BY B.Area
HAVING X.rent = MIN(X.rent);


SELECT * from Building B,Apartment A 
WHERE A.BNO = B.BNo AND B.Area = 'Zamalek' ORDER BY A.Rent,A.bedrooms DESC;


UPDATE Content
Set Balance=0 where Start< '1999-01-21'