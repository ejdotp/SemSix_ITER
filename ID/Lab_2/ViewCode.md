# Assignment 2:  
  
### Question 1:-  
  
### (a): Display the structure of all the tables you have created in assignment (1).  
  
```sql
DESC Instructor;  
DESC Course;  
DESC Prereq;  
DESC Department;  
DESC Teaches;
```
  
### (b): Display the contents of all the tables you have created in assignment (1).  
  
```sql
SELECT * FROM Instructor;  
SELECT * FROM Course;  
SELECT * FROM Prereq;  
SELECT * FROM Department;  
SELECT * FROM Teaches;
```
  
### (c): Display the name and department of each instructor.  
  
```sql
SELECT Name, Dept_name FROM Instructor;
```
  
### (d): Display the name and salary of Comp. Sci. Instructors.  
  
```sql
SELECT Name, Salary  
FROM Instructor  
WHERE Dept_name = 'Comp. Sci.';
```
  
### (e): Display the records of instructor who belongs to Physics department and getting salary less than 90000.  
  
```sql
SELECT *  
FROM Instructor  
WHERE Dept_name = 'Physics'  
AND Salary < 90000;
```
  
### (f): Display the name of the instructors who do not belong to Comp. Sci. Department.  
  
```sql
SELECT Name  
FROM Instructor  
WHERE Dept_name <> 'Comp. Sci.';
```
  
### (g): Display the names of the different department distinctly available in Instructor table.  
  
```sql
SELECT DISTINCT Dept_name  
FROM Instructor;
```
  
### (h): Display all Course_id's that are taught in Spring semester of 2009.  
  
```sql
SELECT Course_id  
FROM Teaches  
WHERE Semester = 'Spring'  
AND Year = 2009;
```
  
### (i): Display course titles that are taught in Comp. Sci. Department and do not have credit equals to 3.  
  
```sql
SELECT Title  
FROM Course  
WHERE Dept_name = 'Comp. Sci.'  
AND Credits <> 3;
```
  
### (j): Display all columns of course table sorted in descending order of department names.  
  
```sql
SELECT *  
FROM Course  
ORDER BY Dept_name DESC;
```
  
### (k): Add a date of join column to instructor table.  
  
```sql
ALTER TABLE Instructor  
ADD Date_of_Join DATE;
```
  
### (l): Insert date values to existing rows.  
  
```sql
UPDATE Instructor  
SET Date_of_Join = TO_DATE('&Date_of_Join', 'DD-MM-YYYY')  
WHERE ID = '&ID';
```
  
### (m): Change the name of dept_name to department in all the tables.  
  
```sql
ALTER TABLE Instructor RENAME COLUMN Dept_name TO Department;  
ALTER TABLE Course RENAME COLUMN Dept_name TO Department;  
ALTER TABLE Department RENAME COLUMN Dept_name TO Department;
```
  
### (n): Change the name of "Prereq" table with new name "Prerequired"  
  
```sql
ALTER TABLE Prereq  
RENAME TO Prerequired;
```
  
### (o): Change Course_id column name to Sub code.  
  
```sql
ALTER TABLE Course RENAME COLUMN Course_id TO Sub_code;  
ALTER TABLE Prerequired RENAME COLUMN Course_id TO Sub_code;  
ALTER TABLE Teaches RENAME COLUMN Course_id TO Sub_code;
```
  
### (p): Change the data type of name to varchar (50).  
  
```sql
ALTER TABLE Instructor  
MODIFY Name VARCHAR2(50);
```
  
### (q): Change the name of Instructor table to Faculty_Info.  
  
```sql
ALTER TABLE Instructor  
RENAME TO Faculty_Info;
```
  
### (r): Change the Column size of Course_id in Course table from 10 to 8.  
  
```sql
ALTER TABLE Course  
MODIFY Sub_code VARCHAR2(8);
```
  
### (s): Delete the content of the table Prereq along with its description.  
  
```sql
DROP TABLE Prerequired CASCADE CONSTRAINTS;
```
  
### (t): Change the column name "Building of Department table by new column name "Builder.  
  
```sql
ALTER TABLE Department  
RENAME COLUMN Building TO Builder;
```
  
