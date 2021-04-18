### different components of a system design
- load balancer: amazon elastic load balancer, 
- NoSql dbs: amazon dynamo db, cassandra,
- Sql Dbs: MySql, PostGl, 
- Network protocols: communication handshake: HTTP(), 
    


### networking
- TCP / IP transmition control protocol, Internel protocol, 
- HTTP: uses TCP to comminuicate, 
- UDP: user datagram protocol, UDP / IP/ solvable high latency,
- SMTP: simple mail ransfer protocol sending email, 
- POP3: Port Office Protocol, 
- IMAP: Internel mesg ascc protocol, 
- HTTP: 
- FTP: file transfer protocol, 
- rtp : realtime transfer protocol, data loss ok, real time is important, 
- dns: domain name system, name to ip address, request-> resolver -> root server -> TLD server -> auth server

### Things to remember in system design
- monolith architecture: single point of failure, steep learning curve, good for small team
- microservice architecture: decoupled system, difficult to design, easy to make modifications and deploy, 
- nosql dbs: cassandra, mongodb, neo4j, amazon dynamodb, 
- load balancing at multiple levels, : least connection / least response / least bandwidth / round robin /
- caching: app server cache, content delivery network, cache eviction,
- data partitioning: horizontal : different tables; vertical: different db servers, problems: joining,
- proxy server:  
- sql : acid, join, 
- nosql: fast, key-value, rapid development, 
- CAP theorem: consistency, availbility, partition tolerance, 
- consistent hashing: key % n -> not horizontally scalable, not load balanced, 
- 


### netflix 
- stat: 110mil subscribers, 220 countries, 3B revenue/quarter, 250mil hrs of vide / day, 1B hrs video / week, 37% of peak US traffic,
- 2008: own data center -> AWS, monolith -> microservice to reduce points of failure,  
- client, backend, CDN ( content delivery network )
- EC2, AWS S3, business logic uservice, Hadoop-spark, video processsing and encoding, openConnect CDN, 
- click play button, get url from central server, checks for license/subscribtion etc, gets correct CDN location, 
- stores videos as multiple format + multiple resolution, 
- takes original video, breaks into chunks (~4s), buckets into (format, resolution) pair, 
- does transcoding / encoding done over 300 cpu, split into chunks, once done, pushed to S3 storage, 
- stores about ~ 1200 files per media content,
- stranger things has ~10k files, 
- determines if a movie is dense or sparse, based on sends data on demand,
- original data is host on amazon S3, cost effective service for static data,
- openconnect: parners with ISP to setup OpenConnect to cache frequent data into local servers, reducing traffic, 
- data from origianl server is copied over to openconnect (write operation) when network load is low,
- netflix: serves from 3 regions, if one fails, traffic gets rerouted through the other one, 
- uses amazon DynamoDB (amazon) and apache Cassandra (originally from Facebook)
- ref [video](https://www.youtube.com/watch?v=x9Hrn0oNmJM) 
- ref [blog](http://highscalability.squarespace.com/blog/2017/12/11/netflix-what-happens-when-you-press-play.html)


### AWS
- EC2 scalable computing, S3 scalable storage, 



### Twitter
- Frontend: Ruby on rails for; Scala/Java: Backend
- Apache Thrift (Facebook) to communicate between different services, 
- MySql + FlockDB, Cassandra: storage + relationships; 
- Memcache: for caching data
- tweet, timeline , trend
- 1/1000 write vs read, 
- 140 chars
- Fanout: when someone tweets, the info is added to followers' timeline as well, 
- Celebrity tweets are pulled in at the final query time by end user.
- rate of a hashtag creates trend, 
- Trend: Apache strom / Heron, Kafka stream, Stream -> Filter -> Parse -> GeoTag -> window -> rank, 
- Filter trivial operators out, 
- Find how many hashtags within a time windows,
- Search timeline: Early bird -> parsed and categorized, scatter + gather 
- services: write, timeline, kafka stream trending, early bord for searching, 
- zookeper: maintains redis on cluster,
- gyzmoduck, tweetypie, 
- ref [video](https://www.youtube.com/watch?v=wYk0xPP_P_8&t=16s)
- ref [diagram](https://imgur.com/6TFkVL2)

### Facebook

### Tiny URL

### Yelp / map search 
- add / del/ edit entry
- search nearby places within a given caregory
- divide map into grids, 10x10 mile2, 200 million sq mile, 20 million grid, ~ 4 GB RAM, 
- for dense grids, use QuadTree to break grid into small pieces, when we reach a limit, 
- QuadTree: tree with 4 children, 
- given user location, keep searching for neighboring leaf nodes till desired result is found or max raduius is reached, 
- space to store quadtree : 12GB, 500M/500loc / grid = 1M grid points, 
- insert: add to database + insert into quadtree, 
- client -> load balance -> [app servers] -> [QuadTree servers] -> databases, 

### Ticketmaster
- 3 billion view, 10 million ticket booking / month
- 100 byte data, 2 GB / day, 4 TB / 5 yrs
- seatch(key, keywork, city, radius, startday, endday, sort_order)
- return data in JSON format, 
- ReserveSeatc(key, session, movie, shwo, seats[])
- return reservation status, 
- ActiveReservationSearch
- WaitForReservation service, 
- 

### Storage
- REDIS DB, in memory database,


### REDIS CACHE
- redis lab
- in memory distributed data structure / data base solution / used for large volume of data caching, 
- fast, modular, 
- written in C, super fast, 
- list, set, map etc
- cache can be on the service server, close to db, or somewhere in between, prefer a large distributed global cache in between 
- write through cache, write back, specially for password etc, 
- if data is changed, db broastcast a mesg, all cache updates, 
- eventual consistency, 
- thrashing, cache missing, 
- periodically write data on db, 
- LRU, LFU, eviction policy, 

### How to store images
- file 
- blob (binary large object)
- clob (char large object)
- prefer file base storage
- use CDN to experiade

### microservice
- client -> gateway -> profile service -> redirect the service, 
- image service + distributed file system to store images, decouple from profile authentication service, 
- chatting , http does not work, server client, receiver client need to poll all the time, 
- use a different protocol, web-socket/ tcp connection, xmpp connection
- use a sessions service to maintain connection between two users for direct messaging, 
- 
- 

### CACHE
  - eviction policy Least Recently Used (LRU), Least Frequently used (LFU), FIFO, 
 
### DNS
  - domain name server,
  - 3rd party, maps domain name to ip address, 
 
### CDN
  - content deliveray network, 
  - 
### Ruby on rails
- started in 2003
- MVC; Convention over configuration; DRY (Dont repeat yourself)

### General system design blogs
- ref [blog](https://github.com/checkcheckzz/system-design-interview)
- ref [highscalability.com](http://highscalability.com/blog/category/example)
- ref [free course](https://systeminterview.com/scale-from-zero-to-millions-of-users.php)
- ref [on github](https://github.com/donnemartin/system-design-primer/tree/master/solutions/system_design)


### key concepts: 
-  Scalability, Reliability, Availability, Efficiency, and Manageability,
-  Cassandra mongodb better scales horizontally, mysql scales vertically,
-  add redundancy to ensure consistemcy and availability, but at a cost, 
-  
-  
