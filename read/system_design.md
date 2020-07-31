# Things to remember in system design
- monolith architecture: single point of failure, steep learning curve, good for small team
- microservice architecture: decoupled system, difficult to design, easy to make modifications and deploy, 


### netflix 
- stat: 110mil subscribers, 220 countries, 3B revenue/quarter, 250mil hrs of vide / day, 1B hrs video / week, 37% of peak US traffic, 
- client, backend, CDN ( content delivery network )
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
