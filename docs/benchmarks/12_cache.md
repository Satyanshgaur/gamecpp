# Week 12 Cache Locality Benchmarks

Comparing Array of Structs (AoS) vs Struct of Arrays (SoA) iteration times across 1,000,000 particle updates:

- **AoS Frame Update:** 4.12 ms
- **SoA Frame Update:** 1.05 ms (3.9x speedup due to vector cache line prefetching)
