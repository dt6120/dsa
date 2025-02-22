# Solid Principles

### S - Single Responsibility
- Class should have a single responsibility.

### O - Open Closed
- Class should be open for extension but closed for modification.

### L - Liskov Substitution
- Parent class objects in a program may be replaced with objects of subclass without altering any desirable properties of the program.
- A child class should be able to do everything the parent class can do.

### I - Interface Seggregation
- Split a set of actions into smaller sets such that a class only executes the set of actions it requires.
- Interface should not include methods that are not required by all clients.
- If a class has methods that it can cannot perform, it creates confusion and bugs.

### D - Dependency Inversion
- High level modules should not depend on low level modules. Both should depend on the abstraction.
- Abstraction should not depend on details. Details should depend on abstraction.
- High level module just needs to know what low level module can do, not how it does it.
- Both modules should follow the abstraction details to work with each other.
