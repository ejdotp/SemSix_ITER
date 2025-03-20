# Assignment 3 - SQL Queries Using SQL Operators, Aggregate & Scalar Functions

**Subject:** Introduction to Databases
**Subject Code:** CSE 3151

## **Objective**

- Solve queries using SQL operators, aggregate functions, and scalar functions over tables based on Assignment 1.

---

## **Question 1: SQL Queries Using SQL Operators**

### **1(a) Display the Sub_codes, Titles, and Credits of courses offered in Physics, Music, Finance, and Biology departments.**

```sql
SELECT Sub_code, Title, Credits  
FROM Course  
WHERE Department IN ('Physics', 'Music', 'Finance', 'Biology');
```

### **1(b) Display records of instructors whose name starts with 'K' and salary is more than 65,000.**

```sql
SELECT *  
FROM Faculty_Info  
WHERE Name LIKE 'K%'  
AND Salary > 65000;
```

### **1(c) Display name, department, gross salary, and net salary of instructors with 105% DA, 20% HRA, 30% IT.**

```sql
SELECT Name, Department,  
       (Salary + (Salary * 1.05) + (Salary * 0.20)) AS Gross_Salary,  
       ((Salary + (Salary * 1.05) + (Salary * 0.20)) - (Salary * 0.30)) AS Net_Salary  
FROM Faculty_Info;
```

### **1(d) Display records of instructors with a salary range between 60,000 and 80,000.**

```sql
SELECT *  
FROM Faculty_Info  
WHERE Salary BETWEEN 60000 AND 80000;
```

### **1(e) Display records of instructors whose second letter in their name is ‘r’.**

```sql
SELECT *  
FROM Faculty_Info  
WHERE Name LIKE '_r%';
```

### **1(f) Display names of instructors in the Comp. Sci. Department in descending order of salary.**

```sql
SELECT Name  
FROM Faculty_Info  
WHERE Department = 'Comp. Sci.'  
ORDER BY Salary DESC;
```

### **1(g) Update all Faculty_Info records with a 15% salary hike.**

```sql
UPDATE Faculty_Info  
SET Salary = Salary * 1.15;
COMMIT;
```

### **1(h) Update records with a 3% salary hike for Comp. Sci. Dept instructors with a salary less than 70,000.**

```sql
UPDATE Faculty_Info  
SET Salary = Salary * 1.03  
WHERE Department = 'Comp. Sci.'  
AND Salary < 70000;
COMMIT;
```

### **1(i) Display the annual salary of each instructor.**

```sql
SELECT Name, Salary * 12 AS Annual_Salary  
FROM Faculty_Info;
```

### **1(j) Update the title of the course 'Game Design' to 'Game Theory'.**

```sql
UPDATE Course  
SET Title = 'Game Theory'  
WHERE Title = 'Game Design';
COMMIT;
```

### **1(k) Delete instructor records from the History department.**

```sql
DELETE FROM Faculty_Info  
WHERE Department = 'History';
COMMIT;
```

### **1(l) Delete course records where Sub_code starts with 'BIO'.**

```sql
DELETE FROM Course  
WHERE Sub_code LIKE 'BIO%';
COMMIT;
```

---

## **Question 2: SQL Queries Using Aggregate Functions**

### **2(a) Display the average salary of instructors in the Physics department.**

```sql
SELECT AVG(Salary) AS Avg_Salary  
FROM Faculty_Info  
WHERE Department = 'Physics';
```

### **2(b) Display the department name and average salary of instructors in each department.**

```sql
SELECT Department, AVG(Salary) AS Avg_Salary  
FROM Faculty_Info  
GROUP BY Department;
```

### **2(c) Display the ID, Name, and Department of the instructor with the highest salary.**

```sql
SELECT ID, Name, Department  
FROM Faculty_Info  
WHERE Salary = (SELECT MAX(Salary) FROM Faculty_Info);
```

### **2(d) Display the number of instructors in the Comp. Sci. Department.**

```sql
SELECT COUNT(*) AS Instructor_Count  
FROM Faculty_Info  
WHERE Department = 'Comp. Sci.';
```

### **2(e) Display the total credits of all courses offered in the Comp. Sci. Department.**

```sql
SELECT SUM(Credits) AS Total_Credits  
FROM Course  
WHERE Department = 'Comp. Sci.';
```

---

## **Question 3: SQL Queries Using Scalar Functions**

### **3(a) Display your name with the first letter in uppercase when entered in lowercase.**

```sql
SELECT INITCAP('your_name') AS Capitalized_Name FROM DUAL;
```

### **3(b) Display the 2nd to 6th characters of your name.**

```sql
SELECT SUBSTR('your_name', 2, 5) AS Extracted_Chars FROM DUAL;
```

### **3(c) Find the length of your full university name.**

```sql
SELECT LENGTH('Your University Name') AS Name_Length FROM DUAL;
```

### **3(d) Display all instructor names with their first letter in uppercase.**

```sql
SELECT INITCAP(Name) AS Capitalized_Name FROM Faculty_Info;
```

### **3(e) List the department name of each instructor as a three-letter code.**

```sql
SELECT SUBSTR(Department, 1, 3) AS Dept_Code FROM Faculty_Info;
```

### **3(f) Display the month of joining for each instructor.**

```sql
SELECT Name, TO_CHAR(Date_of_Join, 'Month') AS Joining_Month FROM Faculty_Info;
```

### **3(g) Display the date of joining for each instructor in `DD/MM/YY` format.**

```sql
SELECT Name, TO_CHAR(Date_of_Join, 'DD/MM/YY') AS Joining_Date FROM Faculty_Info;
```

### **3(h) Find the square root of `6464312`.**

```sql
SELECT SQRT(6464312) AS Square_Root FROM DUAL;
```

### **3(i) Display the string “HELLO ITER” in lowercase with a column heading `lower_case`.**

```sql
SELECT LOWER('HELLO ITER') AS lower_case FROM DUAL;
```
