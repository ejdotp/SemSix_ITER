# Assignment 2:  
  
### Copy codes line by line:   
  
### Question 1:-  
  
### (a):  
  
```sql
DESC Instructor; 
```  
```sql
DESC Course;
```  
```sql  
DESC Prereq;
```  
```sql  
DESC Department;
```  
```sql  
DESC Teaches;
```  
  
### (b):  
  
```sql
SELECT * FROM Instructor;  
```  
```sql
SELECT * FROM Course;  
```  
```sql
SELECT * FROM Prereq;  
```  
```sql
SELECT * FROM Department;  
```  
```sql
SELECT * FROM Teaches;
```  
  
### (c):  
  
```sql
SELECT Name, Dept_name FROM Instructor;
```
  
### (d):  
  
```sql
SELECT Name, Salary FROM Instructor WHERE Dept_name = 'Comp. Sci.';
```
  
### (e):  
  
```sql
SELECT * FROM Instructor WHERE Dept_name = 'Physics' AND Salary < 90000;
```
  
### (f):  
  
```sql
SELECT Name FROM Instructor WHERE Dept_name <> 'Comp. Sci.';
```
  
### (g):  
  
```sql
SELECT DISTINCT Dept_name FROM Instructor;
```
  
### (h):  
  
```sql
SELECT Course_id FROM Teaches WHERE Semester = 'Spring' AND Year = 2009;
```
  
### (i):  
  
```sql
SELECT Title FROM Course WHERE Dept_name = 'Comp. Sci.' AND Credits <> 3;
```
  
### (j):  
  
```sql
SELECT * FROM Course ORDER BY Dept_name DESC;
```
  
### (k):  
  
```sql  
ALTER TABLE Instructor ADD Date_of_Join DATE;
```
  
### (l):  
  
```sql  
UPDATE Instructor SET Date_of_Join = TO_DATE('&Date_of_Join', 'DD-MM-YYYY') WHERE ID = '&ID';
```
  
### (m):  
  
```sql  
ALTER TABLE Instructor RENAME COLUMN Dept_name TO Department;  
```  
```sql  
ALTER TABLE Course RENAME COLUMN Dept_name TO Department;  
```  
```sql  
ALTER TABLE Department RENAME COLUMN Dept_name TO Department;
```  
  
### (n):  
  
```sql  
ALTER TABLE Prereq RENAME TO Prerequired;
```
  
### (o):  
  
```sql  
ALTER TABLE Course RENAME COLUMN Course_id TO Sub_code;  
```  
```sql  
ALTER TABLE Prerequired RENAME COLUMN Course_id TO Sub_code;  
```  
```sql  
ALTER TABLE Teaches RENAME COLUMN Course_id TO Sub_code;
```
  
### (p):  
  
```sql
ALTER TABLE Instructor MODIFY Name VARCHAR2(50);
```
  
### (q):  
  
```sql
ALTER TABLE Instructor RENAME TO Faculty_Info;
```
  
### (r):  
  
```sql
ALTER TABLE Course MODIFY Sub_code VARCHAR2(8);
```
  
### (s):  
  
```sql
DROP TABLE Prerequired;
```
  
### (t):  
  
```sql
ALTER TABLE Department RENAME COLUMN Building TO Builder;
```
  
