# Sales Assignment - SQL Table Creation, Insertion, and Queries

**Objective:**  
Practice SQL table creation with constraints, insertion of data, and query processing using joins and subqueries.

---

## **1. Create the Tables**

### **SALESMAN Table**
```sql
CREATE TABLE SALESMAN (
    SID VARCHAR2(4) PRIMARY KEY CHECK (SID LIKE 'S%'),
    NAME VARCHAR2(50) NOT NULL,
    CITY VARCHAR2(30) NOT NULL,
    COMMISSION NUMBER CHECK (COMMISSION > 0)
);
```

### **CONSUMER Table**
```sql
CREATE TABLE CONSUMER (
    CID VARCHAR2(4) PRIMARY KEY CHECK (CID LIKE 'C%'),
    NAME VARCHAR2(50) NOT NULL,
    CITY VARCHAR2(30) NOT NULL
);
```

### **ORDER_DETAIL Table**
```sql
CREATE TABLE ORDER_DETAIL (
    ORD_NO VARCHAR2(4) PRIMARY KEY CHECK (ORD_NO LIKE 'O%'),
    OAMOUNT NUMBER NOT NULL,
    SID VARCHAR2(4),
    CID VARCHAR2(4),
    FOREIGN KEY (SID) REFERENCES SALESMAN(SID),
    FOREIGN KEY (CID) REFERENCES CONSUMER(CID)
);
```

---

## **2. Insert the Data**

### **SALESMAN**
```sql
INSERT ALL
INTO SALESMAN VALUES('S001', 'JAMES HOOG', 'NEW YORK', 0.15)
INTO SALESMAN VALUES('S002', 'NAIL KNITE', 'PARIS', 0.13)
INTO SALESMAN VALUES('S003', 'PIT ALEX', 'LONDON', 0.09)
INTO SALESMAN VALUES('S004', 'PAUL ADAM', 'PARIS', 0.14)
SELECT * FROM dual;
```

### **CONSUMER**
```sql
INSERT ALL
INTO CONSUMER VALUES('C001', 'NICK', 'NEW YORK')
INTO CONSUMER VALUES('C002', 'DAVIS', 'PARIS')
INTO CONSUMER VALUES('C003', 'JULIAN', 'BERLIN')
INTO CONSUMER VALUES('C004', 'FABIAN', 'NEW YORK')
SELECT * FROM dual;
```

### **ORDER_DETAIL**
```sql
INSERT ALL
INTO ORDER_DETAIL VALUES('O001', 1750.50, 'S001', 'C004')
INTO ORDER_DETAIL VALUES('O002', 950.75, 'S001', 'C001')
INTO ORDER_DETAIL VALUES('O003', 5760.50, 'S004', 'C002')
INTO ORDER_DETAIL VALUES('O004', 200.00, 'S001', 'C001')
SELECT * FROM dual;
```

---

## **3. Display the name of salesperson and consumer who reside in the same city**
```sql
SELECT S.NAME AS SALESMAN, C.NAME AS CONSUMER
FROM SALESMAN S
JOIN CONSUMER C ON S.CITY = C.CITY;
```

---

## **4. Display total number of consumers belonging to each city**
```sql
SELECT CITY, COUNT(*) AS TOTAL_CONSUMERS
FROM CONSUMER
GROUP BY CITY;
```

---

## **5. Display SID and name of the salesperson getting the lowest commission**
```sql
SELECT SID, NAME
FROM SALESMAN
WHERE COMMISSION = (SELECT MIN(COMMISSION) FROM SALESMAN);
```

---

## **6. Display CID and name of the consumers who have received the order from the salesperson belonging to city PARIS or NEW YORK (using subquery)**
```sql
SELECT DISTINCT C.CID, C.NAME
FROM CONSUMER C
WHERE C.CID IN (
    SELECT O.CID
    FROM ORDER_DETAIL O
    WHERE O.SID IN (
        SELECT S.SID FROM SALESMAN S
        WHERE S.CITY IN ('PARIS', 'NEW YORK')
    )
);
```

---

## **7. Provide 5% more commission to the salesperson whose name includes 'A' as the second letter**
```sql
UPDATE SALESMAN
SET COMMISSION = COMMISSION * 1.05
WHERE SUBSTR(NAME, 2, 1) = 'A';
```

---

## **End of Assignment**
