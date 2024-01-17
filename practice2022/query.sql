[문제 시작 전, 주의 사항]
#1
ALTER TABLE Customer ADD COLUMN customer_type VARCHAR(5);
#2
ALTER TABLE Employee_Dependent 
DROP FOREIGN KEY employee_dependent_ibfk_1;
ALTER TABLE Employee_Dependent 
ADD CONSTRAINT employee_dependent_new_fk
    FOREIGN KEY (employee_id) REFERENCES Employee(employee_id)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Payment 
DROP FOREIGN KEY payment_ibfk_1;
ALTER TABLE Payment 
ADD CONSTRAINT payment_new_fk
    FOREIGN KEY (loan_number) REFERENCES Loan(loan_number)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Borrower 
DROP FOREIGN KEY borrower_ibfk_1,
ADD CONSTRAINT borrower_new_fk_customer
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Borrower 
DROP FOREIGN KEY borrower_ibfk_2,
ADD CONSTRAINT borrower_new_fk_loan
    FOREIGN KEY (loan_number) REFERENCES Loan(loan_number)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Depositor 
DROP FOREIGN KEY depositor_ibfk_1,
ADD CONSTRAINT depositor_new_fk_customer
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Depositor 
DROP FOREIGN KEY depositor_ibfk_2,
ADD CONSTRAINT depositor_new_fk_account
    FOREIGN KEY (account_number) REFERENCES Account(account_number)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Manager_Worker 
DROP FOREIGN KEY manager_worker_ibfk_1,
ADD CONSTRAINT manager_worker_new_fk_manager
    FOREIGN KEY (employee_manager) REFERENCES Employee(employee_id)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Manager_Worker 
DROP FOREIGN KEY manager_worker_ibfk_2,
ADD CONSTRAINT manager_worker_new_fk_worker
    FOREIGN KEY (employee_worker) REFERENCES Employee(employee_id)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Loan_Branch 
DROP FOREIGN KEY loan_branch_ibfk_1,
ADD CONSTRAINT fk_loan_branch_loan_number_new
    FOREIGN KEY (loan_number) REFERENCES Loan(loan_number)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Loan_Branch 
DROP FOREIGN KEY loan_branch_ibfk_2,
ADD CONSTRAINT fk_loan_branch_branch_name_new
    FOREIGN KEY (branch_name) REFERENCES Branch(branch_name)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Customer_Banker 
DROP FOREIGN KEY customer_banker_ibfk_1,
ADD CONSTRAINT fk_customer_banker_customer_id_new
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id)
    ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE Customer_Banker 
DROP FOREIGN KEY customer_banker_ibfk_2,
ADD CONSTRAINT fk_customer_banker_employee_id_new
    FOREIGN KEY (employee_id) REFERENCES Employee(employee_id)
    ON UPDATE CASCADE ON DELETE CASCADE;

#3 
해당사항 없음

[문제]
#1
김지은, 이지훈, 김이현, 황지원, 이수진, 양윤모
SELECT customer_name 
FROM Customer 
WHERE customer_city = '서울특별시';
#2
이지훈, 이수진
SELECT C.customer_name
FROM Customer C
JOIN Borrower B ON C.customer_id = B.customer_id
JOIN Loan L ON B.loan_number = L.loan_number
JOIN Loan_Branch LB ON L.loan_number = LB.loan_number
JOIN Branch BR ON LB.branch_name = BR.branch_name
WHERE C.customer_city = BR.branch_city;
#3
유재민 1, 김진수 1 
SELECT employee_name, employment_length
FROM Employee
WHERE employment_length = (
    SELECT MIN(employment_length)
    FROM Employee
);
#4
강수지 3, 김세리 1, 박한국 2, 김진수 1
SELECT E.employee_name, COUNT(CB.customer_id) AS customer_count
FROM Employee E
JOIN Customer_Banker CB ON E.employee_id = CB.employee_id
GROUP BY E.employee_id, E.employee_name
HAVING COUNT(CB.customer_id) >= 1;
#5
아무것도 출력 안된다.
SELECT SUM(total_loan_amount) AS total_amount
FROM(
    SELECT SUM(L.amount) AS total_loan_amount
    FROM Customer C
    JOIN Borrower B ON C.customer_id = B.customer_id
    JOIN Loan L ON B.loan_number = L.loan_number
    WHERE C.customer_name LIKE '김%'
    GROUP BY C.customer_id, C.customer_name
) As SubQuery;
2 4 4 6 7 2
이 이 이 황 이 이 
1 4 6 6 7 9 
10 200 50  100 10 
#6
서대전, 서울대입구, 남대문
SELECT branch_name 
FROM Branch 
WHERE assets > (SELECT AVG(assets) FROM Branch);
#7
c01 김지은, c03 김태호, c08 양윤모
SELECT C.customer_id, C.customer_name
FROM Customer C
WHERE EXISTS (
    SELECT * FROM Depositor D WHERE C.customer_id = D.customer_id
)
AND NOT EXISTS (
    SELECT * FROM Borrower B WHERE C.customer_id = B.customer_id
);
#8
아무것도 출력 안된다.
SELECT C.customer_id, AVG(A.balance)
FROM Customer C
JOIN Depositor D ON C.customer_id = D.customer_id
JOIN Account A ON D.account_number = A.account_number
WHERE C.customer_city = '서울특별시'
GROUP BY C.customer_id
HAVING COUNT(D.account_number) >= 3;
#9
부산은행 마린제니스지점
SELECT B1.branch_name
FROM Branch B1
WHERE B1.branch_city = '부산광역시' AND B1.assets > ANY 
    (SELECT B2.assets 
     FROM Branch B2 
     WHERE B1.branch_name != B2.branch_name AND B2.branch_city = '부산광역시');
#10
아무것도 출력 안된다.(1,2,7,8,9)
SELECT C.customer_id, C.customer_name
FROM Customer C
JOIN Borrower B ON C.customer_id = B.customer_id
JOIN Loan L ON B.loan_number = L.loan_number
JOIN Loan_Branch LB ON L.loan_number = LB.loan_number
JOIN Branch BR ON LB.branch_name = BR.branch_name
WHERE BR.branch_city = '서울특별시'
GROUP BY C.customer_id, C.customer_name
HAVING COUNT(DISTINCT BR.branch_name) = (SELECT COUNT(DISTINCT branch_name) FROM Branch WHERE branch_city = '서울특별시');

#11
e04->5,6,7,9,10
WITH RECURSIVE manager_hierarchy AS (
    SELECT e.employee_id, e.employee_name
    FROM Employee e
    WHERE e.employee_name = '김가은'
    UNION ALL
    SELECT e.employee_id, e.employee_name
    FROM Employee e
    INNER JOIN Manager_Worker mw ON e.employee_id = mw.employee_worker
    INNER JOIN manager_hierarchy mh ON mw.employee_manager = mh.employee_id
)
SELECT employee_name FROM manager_hierarchy WHERE employee_name != '김가은';
#12
UPDATE Account
SET balance = CASE
    WHEN balance >= 10 THEN balance * 1.05
    ELSE balance * 1.03
END;
#13
c01, c02, c07 
UPDATE Customer
SET customer_type = 'VIP'
WHERE customer_id IN (
    SELECT D.customer_id
    FROM Depositor D
    JOIN Account A ON D.account_number = A.account_number
    GROUP BY D.customer_id
    HAVING SUM(A.balance) >= 100
);
#14
e01 e03 e04 e07 e08 e10 삭제
DELETE FROM Employee
WHERE employee_id NOT IN (
    SELECT employee_id
    FROM Customer_Banker
);
#15
01 04 06 08 09 남기기
DELETE FROM Loan
WHERE loan_number IN (
    SELECT loan_number
    FROM (
        SELECT L.loan_number
        FROM Loan L
        JOIN Payment P ON L.loan_number = P.loan_number
        GROUP BY L.loan_number
        HAVING SUM(P.payment_amount) >= (
            SELECT amount
            FROM Loan
            WHERE loan_number = L.loan_number
        )
    ) AS SubQuery
);
#16
CREATE VIEW all_customer AS
SELECT BR.branch_name, C.customer_name
FROM Branch BR
JOIN Loan_Branch LB ON BR.branch_name = LB.branch_name
JOIN Loan L ON LB.loan_number = L.loan_number
JOIN Borrower B ON L.loan_number = B.loan_number
JOIN Customer C ON B.customer_id = C.customer_id;
#17
SELECT customer_name 
FROM all_customer
WHERE branch_name = 'KEB하나은행 서울숲지점';
#18
예금 1 2 3 4 7 8
대출 2 4 6 7
1 3 8
CREATE VIEW only_account_customer AS
SELECT C.customer_name, C.customer_city
FROM Customer C
JOIN Depositor D ON C.customer_id = D.customer_id
LEFT JOIN Borrower B ON C.customer_id = B.customer_id
WHERE B.customer_id IS NULL;
#19
SELECT customer_name
FROM only_account_customer
WHERE customer_city = '서울특별시';
#20
CREATE VIEW customer_avg_balance AS
SELECT C.customer_name, AVG(A.balance) AS avg_balance
FROM Customer C
JOIN Depositor D ON C.customer_id = D.customer_id
JOIN Account A ON D.account_number = A.account_number
GROUP BY C.customer_name;
#21
SELECT avg_balance
FROM customer_avg_balance
WHERE customer_name = '김지은';

