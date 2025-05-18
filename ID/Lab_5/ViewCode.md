# Assignment 5 - Subqueries and Joins

**Subject:** Introduction to Databases  
**Subject Code:** CSE 3151

---

## **Objective**

- Write SQL queries using the concepts of **Subqueries** and **Joins**.
- Practice advanced filtering and aggregation based on existing schemas from Assignment 4.

---

## **Part A: SQL Queries Using Subqueries**

| No. | Question |
|-----|----------|
| 1 | Find out the name, phone_no and cust_no of customer having Account_no “A0004”. |
| 2 | Find out the name of the customer who has not taken any loan. |
| 3 | Find out the account_no and Balance of customer with cust_no = “C0010”. |
| 4 | Find out the branch_city where “ASLESHA TIWARI” has taken a loan. |
| 5 | Find out the installment details of customer named “ANKITA SINGH”. |
| 6 | Find out the branch name and branch city, in which “ABHIJIT MISHRA” has an account. |
| 7 | Create a table named ACCOUNT_TYPE from ACCOUNT table with two columns ACCOUNT_NO and TYPE without data. |
| 8 | Insert into ACCOUNT_TYPE those accounts with balance < 50000. |
| 9 | Update ACCOUNT_TYPE set TYPE='FD' where CUST_NO = 'C0007'. |
| 10 | Delete from ACCOUNT_TYPE where balance < 20000. |
| 11 | Find account_no with balance greater than SOME of FD accounts. |
| 12 | Find account_no with balance greater than ALL of FD accounts. |
| 13 | Display details of branches where some loans are taken (EXISTS). |
| 14 | Display loan details where no installment is paid (NOT EXISTS). |
| 15 | Increase balances using CASE: >80000 → 6%, else 5%. |

### **Solutions**
```sql
-- 1
SELECT NAME, PHONE_NO, CUST_NO
FROM CUSTOMER
WHERE CUST_NO = (SELECT CUST_NO FROM DEPOSITOR WHERE ACCOUNT_NO = 'A0004');

-- 2
SELECT NAME FROM CUSTOMER
WHERE CUST_NO NOT IN (SELECT CUST_NO FROM LOAN);

-- 3
SELECT ACCOUNT_NO, BALANCE FROM ACCOUNT
WHERE ACCOUNT_NO IN (
    SELECT ACCOUNT_NO FROM DEPOSITOR WHERE CUST_NO = 'C0010'
);

-- 4
SELECT BRANCH_CITY FROM BRANCH
WHERE BRANCH_CODE = (
    SELECT BRANCH_CODE FROM LOAN
    WHERE CUST_NO = (SELECT CUST_NO FROM CUSTOMER WHERE NAME = 'ASLESHA TIWARI')
);

-- 5
SELECT I.*
FROM INSTALLMENT I
WHERE LOAN_NO IN (
    SELECT L.LOAN_NO FROM LOAN L
    WHERE L.CUST_NO = (SELECT CUST_NO FROM CUSTOMER WHERE NAME = 'ANKITA SINGH')
);

-- 6
SELECT B.BRANCH_NAME, B.BRANCH_CITY
FROM BRANCH B
WHERE B.BRANCH_CODE IN (
    SELECT A.BRANCH_CODE FROM ACCOUNT A
    WHERE A.ACCOUNT_NO IN (
        SELECT D.ACCOUNT_NO FROM DEPOSITOR D
        WHERE D.CUST_NO = (SELECT CUST_NO FROM CUSTOMER WHERE NAME = 'ABHIJIT MISHRA')
    )
);

-- 7
CREATE TABLE ACCOUNT_TYPE AS
SELECT ACCOUNT_NO, TYPE FROM ACCOUNT WHERE 1=0;

-- 8
INSERT INTO ACCOUNT_TYPE (ACCOUNT_NO, TYPE)
SELECT ACCOUNT_NO, TYPE FROM ACCOUNT WHERE BALANCE < 50000;

-- 9
UPDATE ACCOUNT_TYPE
SET TYPE = 'FD'
WHERE ACCOUNT_NO IN (
    SELECT ACCOUNT_NO FROM DEPOSITOR WHERE CUST_NO = 'C0007'
);

-- 10
DELETE FROM ACCOUNT_TYPE
WHERE ACCOUNT_NO IN (
    SELECT ACCOUNT_NO FROM ACCOUNT WHERE BALANCE < 20000
);

-- 11
SELECT ACCOUNT_NO FROM ACCOUNT
WHERE BALANCE > SOME (
    SELECT BALANCE FROM ACCOUNT WHERE TYPE = 'FD'
);

-- 12
SELECT ACCOUNT_NO FROM ACCOUNT
WHERE BALANCE > ALL (
    SELECT BALANCE FROM ACCOUNT WHERE TYPE = 'FD'
);

-- 13
SELECT * FROM BRANCH B
WHERE EXISTS (
    SELECT * FROM LOAN L WHERE L.BRANCH_CODE = B.BRANCH_CODE
);

-- 14
SELECT * FROM LOAN L
WHERE NOT EXISTS (
    SELECT * FROM INSTALLMENT I WHERE I.LOAN_NO = L.LOAN_NO
);

-- 15
UPDATE ACCOUNT
SET BALANCE = BALANCE * CASE
    WHEN BALANCE > 80000 THEN 1.06
    ELSE 1.05
END;
```

---

## **Part B: SQL Queries Using Joins**

| No. | Question |
|-----|----------|
| 1 | Find Loan_nos where loans are taken from branches in MUMBAI. |
| 2 | Find account types in branches located in DELHI. |
| 3 | Find names and phone numbers of customers with account balance > 100000. |
| 4 | Find installment_no and amount for customer 'RAJ ANAND SINGH'. |
| 5 | Find names of customers without any SB account. |
| 6 | Find names of customers who paid installment of 50000. |
| 7 | Find phone numbers of customers with account at SALTLAKE branch. |
| 8 | Find Branch_name and Branch_city of customer 'ABHIJIT MISHRA'. |
| 9 | Find account types and balances of 'SWAROOP RAY'. |
| 10 | Find branch codes where total balance > average of all branches. |

### **Solutions**
```sql
-- 1
SELECT LOAN_NO FROM LOAN L
JOIN BRANCH B ON L.BRANCH_CODE = B.BRANCH_CODE
WHERE B.BRANCH_CITY = 'MUMBAI';

-- 2
SELECT DISTINCT A.TYPE FROM ACCOUNT A
JOIN BRANCH B ON A.BRANCH_CODE = B.BRANCH_CODE
WHERE B.BRANCH_CITY = 'DELHI';

-- 3
SELECT DISTINCT C.NAME, C.PHONE_NO FROM CUSTOMER C
JOIN DEPOSITOR D ON C.CUST_NO = D.CUST_NO
JOIN ACCOUNT A ON D.ACCOUNT_NO = A.ACCOUNT_NO
WHERE A.BALANCE > 100000;

-- 4
SELECT I.INST_NO, I.INST_AMOUNT FROM INSTALLMENT I
JOIN LOAN L ON I.LOAN_NO = L.LOAN_NO
JOIN CUSTOMER C ON L.CUST_NO = C.CUST_NO
WHERE C.NAME = 'RAJ ANAND SINGH';

-- 5
SELECT DISTINCT C.NAME FROM CUSTOMER C
WHERE C.CUST_NO NOT IN (
    SELECT D.CUST_NO FROM DEPOSITOR D
    JOIN ACCOUNT A ON D.ACCOUNT_NO = A.ACCOUNT_NO
    WHERE A.TYPE = 'SB'
);

-- 6
SELECT DISTINCT C.NAME FROM CUSTOMER C
JOIN LOAN L ON C.CUST_NO = L.CUST_NO
JOIN INSTALLMENT I ON L.LOAN_NO = I.LOAN_NO
WHERE I.INST_AMOUNT = 50000;

-- 7
SELECT DISTINCT C.PHONE_NO FROM CUSTOMER C
JOIN DEPOSITOR D ON C.CUST_NO = D.CUST_NO
JOIN ACCOUNT A ON D.ACCOUNT_NO = A.ACCOUNT_NO
JOIN BRANCH B ON A.BRANCH_CODE = B.BRANCH_CODE
WHERE B.BRANCH_NAME = 'SALTLAKE BRANCH';

-- 8
SELECT DISTINCT B.BRANCH_NAME, B.BRANCH_CITY FROM BRANCH B
JOIN ACCOUNT A ON B.BRANCH_CODE = A.BRANCH_CODE
JOIN DEPOSITOR D ON A.ACCOUNT_NO = D.ACCOUNT_NO
JOIN CUSTOMER C ON D.CUST_NO = C.CUST_NO
WHERE C.NAME = 'ABHIJIT MISHRA';

-- 9
SELECT A.TYPE, A.BALANCE FROM ACCOUNT A
JOIN DEPOSITOR D ON A.ACCOUNT_NO = D.ACCOUNT_NO
JOIN CUSTOMER C ON D.CUST_NO = C.CUST_NO
WHERE C.NAME = 'SWAROOP RAY';

-- 10
WITH BRANCH_BALANCE AS (
    SELECT BRANCH_CODE, SUM(BALANCE) AS TOTAL_BAL
    FROM ACCOUNT GROUP BY BRANCH_CODE
),
AVG_BAL AS (
    SELECT AVG(TOTAL_BAL) AS AVG_BALANCE FROM BRANCH_BALANCE
)
SELECT BRANCH_CODE FROM BRANCH_BALANCE
WHERE TOTAL_BAL > (SELECT AVG_BALANCE FROM AVG_BAL);
```

---

## **End of Assignment**
