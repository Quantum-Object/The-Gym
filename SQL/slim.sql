--Employee(emp_id, emp_name, street, city)
CREATE TABLE Employee(
    emp_id INT,
    emp_name VARCHAR(50),
    street VARCHAR(100),
    city VARCHAR(50),
    PRIMARY KEY (emp_id)
);

--Company(company_name, city)
CREATE TABLE Company(
    company_name VARCHAR(50),
    city VARCHAR(50),
    PRIMARY KEY (company_name)
);

--Works(emp_id, company_name, salary)
CREATE TABLE Works(
    emp_id INT,
    company_name VARCHAR(50),
    salary INT,
    PRIMARY KEY (emp_id, company_name),
    FOREIGN KEY (emp_id) REFERENCES Employee(emp_id)
    ON UPDATE CASCADE ON DELETE CASCADE,
    FOREIGN KEY (company_name) REFERENCES Company(company_name)
    ON UPDATE CASCADE ON DELETE CASCADE
);



--List the names of all employees who live in the same city as their managers.

SELECT X.emp_name FROM
Employee X,Employee Y, managers M
WHERE X.emp_id=M.emp_id AND Y.emp_id=M.manager_id AND X.city=Y.city;

-- Find the names of all employees who earn more than every employee of Small Bank Corporation.
--we have salary in works oK!

--Works(emp_id, company_name, salary)

SELECT X.name FROM 
Employee X INNER JOIN
( SELECT S.emp_id FROM Works S WHERE S.salary > (SELECT max(A.salary) 
FROM Works A WHERE
 A.company_name='Small Bank Corporation')) AS R ON  X.emp_id=R.emp_id;



