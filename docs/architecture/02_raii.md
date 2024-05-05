# Week 2: Resource Acquisition Is Initialization (RAII)

## Principle
Manual `destroy()` functions lead to memory leaks and resource dangling. RAII guarantees automatic cleanup when handles leave scope.
