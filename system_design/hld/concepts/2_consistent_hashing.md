# Consistent Hashing

### Why is it required?
- While adding or removing servers, we want to minimize the changes on the servers. This is to ensure important local data like cache is preserved.
- Normal hashing mechanisms require all servers to redistribute the load when server count is modified.
- In consistent hashing, the hash range is made circular. Each request is routed to its nearest server in clockwise direction.
- When any server goes down, the next clockwise server serves the extra requests. Practically, the load distribution is not even.
- To ensure balanced load, we introduce virtual servers by increasing the number of hash functions used.
- Say we use `k` hash functions to get `k` virtual servers points on the circular space. This distributes the servers across the space more evenly.
- Picking suitable value for `k` like `log(m)` removes the chance for skewed load.
- If one server goes down, its corresponding `k` points are removed and nearest server in clockwise direction is choosed.