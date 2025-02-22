# Database Sharding

### Features
- Partitioning which uses some key to break data into different pieces and allocate that to different servers is called hrizontal partitioning. It depends on one key which is an attribute of the data being stored.
- Each individual shard data can be indexed on another attribute for faster reads.
- Master slave architecture can be used for shards. All writes happen on master and slaves replicate data on their end and serve read requests. If master goes down, slaves decide a new master amongst them.


### Problems
- Join queries are complicated and expensive
- Fixed number of shards
- Using hierarchical sharding, shard number can be made dynamic and handled through some mapping manager that maps requests to correct shard with data
