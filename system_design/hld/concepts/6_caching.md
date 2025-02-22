# Caching

- Reduce network calls and latency
- Avoid repeated computations through storage
- Reduce database load
- We need to optimize cache storage by trying to keep data that will be accessed next

### Cache policy
- How to manage writes and in what order?
- What data to evict on overflow? (LRU, LFU)
- How to manage eventual consistency?

### Cache placement
- Where to place the cache? In the server (in-memory) or in database or as global cache in external system?
- Usually combination of all three options are used.
By using external cache system, it can scale and can be deployed independently and multiple services can use the same cache

### Drawbacks
- Poor cache policies can hurt performance