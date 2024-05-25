# Changelog

## [v0.1] - 2024-05-28
### Added
- Core Window and main loop abstraction (`Engine::Core::Window`).
- Structured console Logger (`Engine::Core::Logger`).
- RAII resource management for Textures and Sound Effects.
- Scene graph with `std::shared_ptr` / `std::weak_ptr` entity ownership.
- Type-safe template `EventDispatcher`.
- Centralized `ResourceManager` with reference count cache eviction.
