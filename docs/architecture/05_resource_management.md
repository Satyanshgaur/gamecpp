# Week 5: Templated Asset Cache Manager

## Strategy
Flyweight pattern storing resource instances in an `unordered_map`. Resources are cleaned up automatically when external reference counts drop to 1.
