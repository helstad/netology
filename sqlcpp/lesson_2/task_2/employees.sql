CREATE TABLE Employees (
    employee_id SERIAL PRIMARY KEY,
    employee_name VARCHAR(255) NOT NULL,
    department VARCHAR(255),
    manager_id INT,
    FOREIGN KEY (manager_id) REFERENCES Employees(employee_id)
);
