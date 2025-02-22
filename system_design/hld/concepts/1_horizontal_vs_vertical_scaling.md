# Horizontal VS Vertical Scaling

### Horizontal Scaling
- Load balancing is required
- Resilient to single point of failure
- Data inconsistency is an issue
- Services communicate through network call (rpc) which are slow
- Scales well with increasing users

### Vertical Scaling
- No need for load balancing
- Susceptible to single of failure
- Data consistency is ensured
- Inter process communication is fast
- Has hardware limitations

### What is used in real world?
- Combination of both is used to leverage good properties of both design choices.
- Servers are scaled vertically till their hardware limit and then system can be shifted to horizontal scaling