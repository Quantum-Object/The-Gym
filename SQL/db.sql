-- Create a test database
CREATE DATABASE TestDB;

-- Use the test database
USE TestDB;

-- Create a test table
CREATE TABLE Employees (
    ID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(100),
    Position VARCHAR(50),
    Salary DECIMAL(10, 2)
);

-- Insert some test data
INSERT INTO Employees (Name, Position, Salary) VALUES
('Alice', 'Developer', 75000.00),
('Bob', 'Designer', 65000.00),
('Charlie', 'Manager', 85000.00);

-- Query the test data
SELECT * FROM Employees;
