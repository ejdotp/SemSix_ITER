# Assignment 1:

### 1. Create the following Tables with their respective columns, data types and size.  
  
```sql
CREATE TABLE Instructor (
    ID NUMBER(5),
    Name VARCHAR2(30),
    Dept_name VARCHAR2(20),
    Salary NUMBER(6)
);

CREATE TABLE Course (
    Course_id VARCHAR2(10),
    Title VARCHAR2(30),
    Dept_name VARCHAR2(20),
    Credits NUMBER(2)
);

CREATE TABLE Prereq (
    Course_id VARCHAR2(10),
    Prereq_id VARCHAR2(10)
);

CREATE TABLE Department (
    Dept_name VARCHAR2(20),
    Building VARCHAR2(20),
    Budget NUMBER(10)
);

CREATE TABLE Teaches (
    ID NUMBER(5),
    Course_id VARCHAR2(10),
    Sec_id NUMBER(2),
    Semester VARCHAR2(10),
    Year NUMBER(4)
);
```
  
### 2. Insert data into Instructor table with the data below:  
  
```sql
INSERT ALL  
    INTO Instructor VALUES(10101, 'Srinivasan', 'Comp. Sci.', 65000)  
    INTO Instructor VALUES(12121, 'Wu', 'Finance', 90000)  
    INTO Instructor VALUES(15151, 'Mozart', 'Music', 40000)  
    INTO Instructor VALUES(22222, 'Einstein', 'Physics', 95000)  
    INTO Instructor VALUES(32343, 'El Said', 'History', 60000)  
    INTO Instructor VALUES(33456, 'Gold', 'Physics', 87000)  
    INTO Instructor VALUES(45565, 'Katz', 'Comp. Sci.', 75000)  
    INTO Instructor VALUES(58583, 'Califieri', 'History', 62000)  
    INTO Instructor VALUES(76543, 'Singh', 'Finance', 80000)  
    INTO Instructor VALUES(76766, 'Crick', 'Biology', 72000)  
    INTO Instructor VALUES(83821, 'Brandt', 'Comp. Sci.', 92000)  
    INTO Instructor VALUES(98345, 'Kim', 'Elec. Eng.', 80000)  
SELECT * FROM dual;  
```
  
### 3.Insert data into Course table with the data below:  
  
```sql
INSERT ALL
    INTO Course VALUES('BIO-101', 'Intro. to Biology', 'Biology', 4)
    INTO Course VALUES('BIO-301', 'Genetics', 'Biology', 4)
    INTO Course VALUES('BIO-399', 'Computational Biology', 'Biology', 3)
    INTO Course VALUES('CS-101', 'Intro. to Computer Science', 'Comp. Sci.', 4)
    INTO Course VALUES('CS-190', 'Game Design', 'Comp. Sci.', 4)
    INTO Course VALUES('CS-315', 'Robotics', 'Comp. Sci.', 3)
    INTO Course VALUES('CS-319', 'Image Processing', 'Comp. Sci.', 3)
    INTO Course VALUES('CS-347', 'Database System Concepts', 'Comp. Sci.', 3)
    INTO Course VALUES('EE-181', 'Intro. to Digital Systems', 'Elec. Eng.', 3)
    INTO Course VALUES('FIN-201', 'Investment Banking', 'Finance', 3)
    INTO Course VALUES('HIS-351', 'World History', 'History', 3)
    INTO Course VALUES('MU-199', 'Music Video Production', 'Music', 3)
    INTO Course VALUES('PHY-101', 'Physical Principles', 'Physics', 4)
SELECT * FROM dual; 
```
  
### 4. Insert data into Prereq table with the data below:  
  
```sql
INSERT ALL
    INTO prereq VALUES('BIO-301', 'BIO-101')
    INTO prereq VALUES('BIO-399', 'BIO-101')
    INTO prereq VALUES('CS-190', 'CS-101')
    INTO prereq VALUES('CS-315', 'CS-101')
    INTO prereq VALUES('CS-319', 'CS-101')
    INTO prereq VALUES('CS-347', 'CS-101')
    INTO prereq VALUES('EE-181', 'PHY-101')
SELECT * FROM dual;
```
  
### 5. Insert data into Department table with the data below:  
  
```sql
INSERT ALL
    INTO DEPARTMENT VALUES('Biology', 'Watson', 90000)
    INTO Department VALUES('Comp. Sci.', 'Taylor', 100000)
    INTO Department VALUES('Elec. Eng.', 'Taylor', 85000)
    INTO Department VALUES('Finance', 'Painter', 120000)
    INTO Department VALUES('History', 'Painter', 50000)
    INTO Department VALUES('Music', 'Packard', 80000)
    INTO Department VALUES('Physics', 'Watson', 70000)
SELECT * FROM dual;
```
  
### 6. Insert data into Teaches table with the data below:  
  
```sql
INSERT ALL
    INTO TEACHES VALUES(10101, 'CS-101', 1, 'Fall', 2009)
    INTO Teaches VALUES(10101, 'CS-315', 1, 'Spring', 2010)
    INTO Teaches VALUES(10101, 'CS-347', 1, 'Fall', 2009)
    INTO Teaches VALUES(12121, 'FIN-201', 1, 'Spring', 2010)
    INTO Teaches VALUES(15151, 'MU-199', 1, 'Spring', 2010)
    INTO Teaches VALUES(22222, 'PHY-101', 1, 'Fall', 2009)
    INTO Teaches VALUES(32343, 'HIS-351', 1, 'Spring', 2010)
    INTO Teaches VALUES(45565, 'CS-101', 1, 'Spring', 2010)
    INTO Teaches VALUES(45565, 'CS-319', 1, 'Spring', 2010)
    INTO Teaches VALUES(76766, 'BIO-101', 1, 'Summer', 2009)
    INTO Teaches VALUES(76766, 'BIO-301', 1, 'Summer', 2010)
    INTO Teaches VALUES(83821, 'CS-190', 1, 'Spring', 2010)
    INTO Teaches VALUES(83821, 'CS-190', 2, 'Spring', 2009)
    INTO Teaches VALUES(83821, 'CS-319', 1, 'Spring', 2010)
    INTO Teaches VALUES(98345, 'EE-181', 1, 'Spring', 2009)
SELECT * FROM dual;
```
  
