--a)
select IDNr,Names from  students
where semster >=11
--b)
select IDNr,Names,AH from  
(select *,sum(L.hours)  AH
 from students S,Lecture L,attended A
where A.IDNr=S.IDNr AND A.lecNr=L.lecNr
GROUP BY S.IDNr )
AS M
where M.AH>12;
--c)
select Names,IDNr from students where Names LIKE 'T%'
--d)
select *
from students S,Lecture L,attended A
where A.IDNr=S.IDNr AND A.lecNr=L.lecNr AND L.name='Logic'
--c)
select S.names,count(L.Name)
 from students S,Lecture L,attended A
where A.IDNr=S.IDNr AND A.lecNr=L.lecNr
GROUP BY S.IDNr
HAVING count(L.Name)>(select count(L.Name)
 from students S,Lecture L,attended A
where A.Name='Corpans' AND A.IDNr=S.IDNr AND A.lecNr=L.lecNr
GROUP BY S.IDNr);