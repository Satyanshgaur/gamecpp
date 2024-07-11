# Week 11 Benchmark: Arena Allocator vs Malloc

| Allocator Type | 100k Allocations (ms) | Memory Overhead |
|----------------|-----------------------|-----------------|
| `malloc`/`free`| ~14.2 ms              | High (headers)  |
| `ArenaAllocator` | ~0.8 ms             | Zero overhead   |

**Result:** ~17.7x performance improvement by eliminating OS heap allocations in frame loops.
