# Design Patterns

## 1. Singleton pattern
- It is a creational design pattern.
- It ensures a class has only one instance and provides a global point of access to it.
- Only the singleton class is permitted to create its own objects.
- This can be achieved by making the constructor private and providing a static method for external objects to access it.

### Lazy Initialization
- Creates an instance only when required. If instance exists, returns it directly.

### Eager Initialization
- Creates an instance immediately when the class is loaded.

### Synchronized
- Static method get locked during call.
- Very slow when multiple threads are accessing it.

### Double locking
- Only place lock if object is not instantiated.
- Checks if object is instantiated two times: first when static method is called, second when lock is placed.

## 2. Factory pattern
- It is a creational design pattern.
- Logic for creating an object is shifted to single Factory class.
- Factory class will contain all conditions that decide which class object to create and this provides single place of change for all object creation logic.

## 3. Abstract Factory Pattern
- It is a creational design pattern.
- Multiple classes can be divided into categories. Each category will have its own Factory class.
- There is a factory producer which returns the specific category factory which is used to create category objects.


