# Things to remember in system design
- monolith architecture: single point of failure, steep learning curve, good for small team
- microservice architecture: decoupled system, difficult to design, easy to make modifications and deploy, 


# netflix 
- stores videos as multiple format + multiple resolution, 
- takes original video, breaks into chunks (~4s), buckets into (format, resolution) pair, 
- determines if a movie is dense or sparse, based on sends data on demand,
- original data is host on amazon S3, cost effective service for static data,
- openconnect: parners with ISP to setup OpenConnect to cache frequent data into local servers, reducing traffic, 
- data from origianl server is copied over to openconnect (write operation) when network load is low, 
- ref [video](https://www.youtube.com/watch?v=x9Hrn0oNmJM) 
- ref [blog](http://highscalability.squarespace.com/blog/2017/12/11/netflix-what-happens-when-you-press-play.html)
