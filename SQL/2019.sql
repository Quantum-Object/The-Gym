Customer(CID, name, address)
Magazine(title, publisher,topic, frequency, url)
Pricing(title, publisher, period, discount, price)
Pricing.(title, publisher) references Magazine
Subscribes(cid,title, publisher, period, discount, from)
Subscribes.(cid) refs Customer
Subscribes.(title, publisher, period, discount) references Pricing


SELECT M.publisher
FROM Magazine M
GROUP BY M.publisher
HAVING COUNT(DISTINCT M.topic) = (SELECT COUNT(DISTINCT M.topic) FROM Magazine M);

GO

CREATE VIEW no_sub AS
SELECT * FROM Magazine M
WHERE NOT EXISTS 
(SELECT * FROM Subscribes S 
WHERE S.title = M.title AND S.publisher = M.publisher
)


GO 



SELECT  TOP 1 M.title,COUNT(S.cid) FROM Magazine M,Subscribes S
WHERE  M.title = S.title AND M.publisher = S.publisher AND M.topic='science'
GROUP BY M.title,M.publisher ORDER BY COUNT(S.cid) DESC;

