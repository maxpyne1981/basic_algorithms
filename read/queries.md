# sql query examples

## read data from database

### select column
- select * from table; // select everything
- select column1, column2 from table; // select only two columns

### dictinct / count
- select DISTINCT column1, column2 from table; // select only two columns
- select Country FROM Customers;
- select DISTINCT Country FROM Customers;
- select COUNT(DISTINCT Country) FROM Customers;


### conditional 
- SELECT * FROM Customers WHERE Country='USA';
- SELECT * FROM Customers WHERE CustomerID=1; // <, >, =, <= , >=, != or <>, BETWEEN, LIKE, IN
- SELECT column1, column2, FROM table_name WHERE condition1 AND condition2 AND condition3; 
- SELECT column1, column2, FROM table_name WHERE condition1 OR condition2 OR condition3; 
- SELECT column1, column2, FROM table_name WHERE NOT condition;
- SELECT * FROM Customers WHERE Country='Germany' AND (City='Berlin' OR City='München');


### order by
- SELECT column1, column2, FROM table_name ORDER BY column1, column2 ASC|DESC;


### read min/max/count/limit/sum/average values
- SELECT column_name(s) FROM table_name WHERE condition LIMIT number;
- SELECT * FROM Customers LIMIT 3;
- SELECT MIN(column_name) FROM table_name WHERE condition;
- SELECT MIN(Price) AS SmallestPrice FROM Products; // as keyword
- SELECT MAX(Price) AS LargestPrice FROM Products;
- SELECT COUNT(ProductID) FROM Products;
- SELECT AVG(Price) FROM Products;
- SELECT SUM(Quantity) FROM OrderDetails;

## LIKE regular expression on conditional; % one or more char, _ single char
- SELECT * FROM Customers WHERE CustomerName LIKE 'a%';

- % zero or more chars, bl% black, blue 
- _ single char, h_t, hat, hot, 
- [] any single char within, h[oat] hat, hot
- ^ any char not in bracker h[^oa]t hit, hut but not hot, hat
- - range of char c[a-b]t cat, cbt

- select * from Users where mail REGEXP '^[a-z][a-z0-9-./_]*@leetcode.com$'

### join
- SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate 
    FROM Orders 
    INNER JOIN Customers 
    ON Orders.CustomerID=Customers.CustomerID;


- SELECT                p.project_id
                        ROUND(AVG(e.experience_years), 2) AS average_years
    FROM                Project AS p
    INNER JOIN          Employee AS e
    ON                  p.employee_id = e.employee_id
    GROUP BY            p.project_id    

### inner join, A intersection B
- SELECT column_name(s)
    FROM table1
    INNER JOIN table2
    ON table1.column_name = table2.column_name;

- SELECT Orders.OrderID, Customers.CustomerName
    FROM Orders
    INNER JOIN Customers ON Orders.CustomerID = Customers.CustomerID;    
    

### left join, A + (A intersection B)
- SELECT column_name(s)
    FROM table1
    LEFT JOIN table2
    ON table1.column_name = table2.column_name;

- SELECT Customers.CustomerName, Orders.OrderID
    FROM Customers
    LEFT JOIN Orders ON Customers.CustomerID = Orders.CustomerID
    ORDER BY Customers.CustomerName;

### right join, (A intersection B) + B

- SELECT column_name(s)
    FROM table1
    RIGHT JOIN table2
    ON table1.column_name = table2.column_name;

- SELECT Customers.CustomerName, Orders.OrderID
    FROM Customers
    RIGHT JOIN Orders ON Customers.CustomerID = Orders.CustomerID
    ORDER BY Customers.CustomerName;

### full outer join, A union B
- SELECT column_name(s)
    FROM table1
    FULL OUTER JOIN table2
    ON table1.column_name = table2.column_name
    WHERE condition;

- SELECT Customers.CustomerName, Orders.OrderID
    FROM Customers
    FULL OUTER JOIN Orders ON Customers.CustomerID=Orders.CustomerID
    ORDER BY Customers.CustomerName;

### group by
- SELECT column_name(s)
    FROM table_name
    WHERE condition
    GROUP BY column_name(s)
    ORDER BY column_name(s);

- SELECT COUNT(CustomerID), Country
    FROM Customers
    GROUP BY Country
    ORDER BY COUNT(CustomerID) DESC;

### having
- SELECT COUNT(CustomerID), Country
    FROM Customers
    GROUP BY Country
    HAVING COUNT(CustomerID) > 5;


### examples
# Write your MySQL query statement below
- SELECT a.product_id,ROUND(SUM(b.units*a.price)/SUM(b.units),2) as average_price
    FROM Prices as a
    JOIN UnitsSold as b
    ON a.product_id=b.product_id AND (b.purchase_date BETWEEN a.start_date AND a.end_date)
    GROUP BY product_id;


- select email from 
    (
    
        select email, count(email) as num 
        from Person 
        group by email
    
    )  as viewtable 
    where num > 1;    

## modify database

### inserting data
- INSERT INTO table_name (column1, column2, column3) VALUES (value1, value2, value3);


