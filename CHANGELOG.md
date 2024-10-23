# Changelog

All notable changes to the `gamecpp` engine project are documented below.

## [v1.0]
### Added
- Integrated complete arcade game demo in `game/src/main.cpp`.
- Final release polish, documentation suite, and build verification.

## [v0.9]
### Added
- Real-time scope profiler (`Engine::Profiler::ProfileScope`).
- A* Grid Pathfinding and Behavior Tree decision nodes.
- Lightweight Neural Inference matrix runtime for embedded AI.
- Multiplayer position snapshot interpolation and prediction.
- Automated engine unit test suite in `tests/`.

## [v0.8]
### Added
- BSD Socket networking supporting TCP and UDP datagrams.
- C++20 Coroutines for async task execution.
- Binary and JSON serialization stream writers.
- Offline `AssetPacker` CLI tool for resource bundling.
- Dynamic script engine property binding environment.

## [v0.5]
### Added
- Custom `ArenaAllocator` and `PoolAllocator`.
- Struct-of-Arrays (SoA) component storage layout.
- SIMD vectorized math and bounding box collision solver.
- Multi-threaded `ThreadPool` and parallel `JobSystem`.

## [v0.2]
### Added
- 2D Quad Batch Renderer and `Camera2D` orthographic projection.
- Key & Mouse input management state mapping.
- Entity Component System (`ECSManager`).
- Keyframe sprite animation state machine.
- 2D AABB Physics collision solver and velocity integrator.

## [v0.1]
### Added
- Cross-platform SDL2 Window wrapper and event loop.
- Colored console Logger.
- RAII resource management wrappers.
- Smart pointer scene graph tree (`shared_ptr` / `weak_ptr`).
- Type-safe template `EventDispatcher`.
- Centralized `ResourceManager` with reference count cache eviction.
