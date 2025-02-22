# Publisher Subscriber Models (Event driven services)

- Decouples responsibilty from server to message broker
- Provides loose transaction guarantee
- Easily scalable as new service has to just subscribe to required data
- Poor consistency
- Does not guarantee idempotency. It needs to be implemented.


### Features
- Each service consuming events from the event bus stores the event data in its own local database providing persistence
- Each service is highly available but not immediately consistent
- Easy rollback by going through log history for debugging purposes
- Easy to replace services as data can be replicated by replaying the events in the same order
- Gives transactional guarantee wherein message sent to service is atleast one or atmost one
- Helps in storing the intent of the event/data

### Drawbacks
- All services on the gateway need to store the timestamp of the responses
- Less control than request/response architecture
- Difficult to understand flow of data

