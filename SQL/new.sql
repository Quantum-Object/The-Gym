
CREATE TABLE Company
(company_id INT PRIMARY KEY IDENTITY, 
name VARCHAR(20), 
field VARCHAR(20)
)

CREATE TABLE Country
(
country_id INT PRIMARY KEY IDENTITY, 
name VARCHAR(20)
)

CREATE TABLE Company_Country
(
company_id INT FOREIGN KEY REFERENCES Company(company_id), 
country_id INT FOREIGN KEY REFERENCES Country(country_id)
PRIMARY KEY(company_id, country_id)
)



CREATE TABLE Employee
(employee_id INT PRIMARY KEY IDENTITY,
name VARCHAR(20), 
age INT, 
has_insurance BIT, 
birth_country_id INT FOREIGN KEY REFERENCES Country(country_id),
company_id INT FOREIGN KEY REFERENCES Company(company_id)
)

INSERT INTO Country
VALUES ('Egypt'), ('Germany'), ('United States'), ('Saudi Arabia'), ('Cameron'), ('Austria'), ('Russia'), ('Iraq'), ('Palestine'), ('Oman')

INSERT INTO Company 
VALUES ('Apple', 'Software'), ('Google', 'Software'), ('SAP', 'Tech'), ('Cisco', 'Communications'), ('Ezz Steel', 'Architecture'), ('Telecom Egypt', 'Communications')


INSERT INTO Company_Country
VALUES (1, 3), (2, 3), (6, 1), (4, 3), (3, 2), (5, 1)

INSERT INTO Employee
VALUES ('Ahmed', 30, 1, 1, 2), ('Harry', 25, 1, 3, 2), ('Hassan', 35, 1, 1, 5), ('Omar', 23, 0, 1, 3),
       ('John', 28, 1, 2, 3), ('Walter', 32, 1, 6, 4), ('Randy', 37, 0, 4, 1), ('Aya', 22, 0, 1, 6),
       ('Sandy', 29, 1, 5, 3), ('Sarah', 33, 0, 5, 2)

