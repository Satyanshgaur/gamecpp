# Week 1: Hello Window & Build System

## Architecture Overview
The engine begins with a decoupled `Window` and `Logger` subsystem.

```mermaid
graph TD
    App[Game Application] --> Window[Core::Window]
    App --> Logger[Core::Logger]
    Window --> SDL[SDL2 System API]
```

## Features
- CMake multi-target project build system.
- Cross-platform `Window` abstraction.
- High-resolution frame tick calculation.
