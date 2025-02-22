# Message Queue

### Features
- It checks `heartbeat` of all servers continuously to always know which servers are active at any time.
- If any server goes down, it can get `notified` and reassign its tasks to other servers.
- It handles `load balancing` to ensure even distribution of task assignments.
- It maintains `data persistence` through database to prevent data loss if any server goes down.

- Take tasks -> persist them -> assign task to correct server -> wait for task to complete -> if server does not acknowledge -> assign task to next server
