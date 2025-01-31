SELECT 
S.name from 
Students S INNER JOIN
(SELECT F.id
FROM 
Friends F,Packages A, Packeges B
where F.id=A.id AND F.friend_id =B.id
AND A.salary>B.salary) AS C
ON S.id=C.id;




UPDATE  Hotels
SET name ='Heliopolis - Cairo',address ='sheraton'
where name LIKE 's%n' OR opened_since='1/1/1950'





DELETE FROM Guests where birth_country_id IS NULL;


--Continents (id, name, area)


SELECT H.name,M.B.name FROM Hotels H INNER JOIN
(select * from Continents A,Countries B
where  B.continent_id=A.id  and  A.name LIKE 'A%') AS M
ON H.country_id=M.B.id;


--Get all room numbers, corresponding hotel names, and their country name of all the
--rooms that were reserved by a guest who was born in ‘Egypt‘ and has a name composed
--of 5 letters and sort them by the room number ascendingly



select * from Rooms R,Holtes H,Reserve S,
(select * from Guests G ,Countries C
where G.birth_country_id=C.id AND C.name='Egypt' AND (G.name LIKE '_____' or LEN(G.name)=5)) AS M

where S.guest_id=M.G.id AND S.room_id=R.id AND
R.hotels_id=H.id ORDER BY R.number;

-- Show the details of all the rooms that weren ‘t reserved at all.


--Hotels (id, name, address, opened_since, total_rooms, country_id)
--Guests(id, name, birth_country_id)
--Countries (id, name, population, continent_id)
--Reserve (guest_id, room_id, reservation_date) 
--Rooms (id, number, hotels_id) "very weird rooms have distinct ids over the world"
--guest from egypt and name.length =5;



select * from Reserve R RIGHT OUTER JOIN Rooms S ON
R.room_id=S.id where R.id IS NULL;


select city,LEN(city) from Station where 
LEN(city )=(select max(city) from station);

select city,LEN(city) from Station where 
LEN(city )=(select min(city) from station);




SELECT A.name From Animal B,Adopter A,Adoption X
WHERE B.ID=x.animalID AND A.SIN=X.SIN AND 
COUNT(*)=(SELECT distinct Count(type) from Animals)
GROUP BY A.SIN;