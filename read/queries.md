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


## modify database

### inserting data
- INSERT INTO table_name (column1, column2, column3) VALUES (value1, value2, value3);

