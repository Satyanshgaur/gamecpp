```markdown
# C++ Systems Journey
### Building a Modern Real-Time Engine from First Principles
*A 26-week engineering roadmap documenting the evolution from beginner C++ to systems programming.*

---

# Vision

This repository is **not** a collection of tutorials.

It is the public record of becoming a systems engineer.

Every week adds one meaningful capability to the engine while introducing one major C++ or systems programming concept.

Someone should be able to:

- Checkout any weekly folder.
- Build it.
- Run it.
- Observe the improvements.
- Read why those improvements were made.

The repository should tell a story.

```

Week 1
↓

Window

↓

Renderer

↓

Sprites

↓

Physics

↓

Thread Pool

↓

SIMD

↓

Networking

↓

Asset Pipeline

↓

Multiplayer

↓

Complete Engine

```

By Week 26, the project should no longer feel like a tutorial.

It should feel like a genuine software project with six months of engineering history.

---

# Repository Structure

```

cpp-engine-lab/

README.md
ROADMAP.md
CHANGELOG.md

versions/
v0.1/
v0.2/
...

weekly/

```
001_hello_window/
002_raii/
003_smart_pointers/
...
```

shared/
assets/
docs/
benchmarks/
screenshots/

```

Every week should be completely runnable.

---

# Weekly Folder Structure

Every folder should contain exactly the same structure.

```

012_ecs/

README.md

src/

include/

tests/

benchmarks/

assets/

screenshots/

notes.md

architecture.md

```

---

## README.md

Contains

- What existed before
- Problem
- Goal
- New concepts
- Features added
- Benchmarks
- Screenshots
- Future improvements

---

## architecture.md

Explain

```

Current architecture

Previous architecture

Tradeoffs

Design decisions

Possible future improvements

```

Use diagrams whenever possible.

---

## notes.md

Personal engineering journal.

Include

- Mistakes
- Dead ends
- Bugs
- Things learned
- Interesting references

This makes the repository feel authentic.

---

## Benchmarks

Every optimization week should include

```

Before

After

CPU usage

Memory usage

FPS

Frame time

```

Graphs are encouraged.

---

# Development Rules

Every week must satisfy these requirements.

- Every version compiles.
- Previous functionality never breaks.
- New functionality is tested.
- README updated.
- Architecture diagram updated.
- Screenshots updated.
- Benchmarks included if performance changes.

---

# Git Strategy

One feature branch per week.

Example

```

feature/week08-ecs

feature/week13-threadpool

feature/week19-networking

```

Merge into main only after completion.

---

# Commit Style

Good

```

Add resource manager

Implement ECS component storage

Optimize sprite rendering

Replace malloc with arena allocator

Add multithreaded asset loading

```

Bad

```

Update

Fix

Changes

Done

```

---

# Weekly Roadmap

---

# Phase 1
## Foundations

Weeks 1-5

Goal

Build the minimum engine while learning modern C++.

---

## Week 1

### Hello Window

Topics

- Build system
- CMake
- SDL2
- Basic project layout

Features

- Window
- Main loop
- Event polling

Deliverables

- Black window
- FPS counter

Documentation

- Why SDL?
- Engine architecture

---

## Week 2

### RAII

Topics

- Constructors
- Destructors
- Ownership

Features

- Window class
- Texture class
- Audio class

Replace

```

Manual cleanup

↓

Automatic cleanup

```

Goal

Never call destroy functions manually.

---

## Week 3

### Smart Pointers

Topics

- unique_ptr
- shared_ptr
- weak_ptr

Features

- Entity ownership
- Scene management

Game Progress

Player object exists.

---

## Week 4

### Templates

Topics

- Generic programming
- Type safety

Features

- Event system
- Resource manager
- Component storage

---

## Week 5

### Resource Management

Topics

- Asset loading
- File organization

Features

- Texture cache
- Font loading
- Audio loading

---

# Publish

```

v0.1

The Engine Boots

```

Repository now contains

- Window
- Rendering
- Assets
- Input

---

# Phase 2
## Building the Engine

Weeks 6-10

Goal

Transform the application into a small engine.

---

## Week 6

Renderer

- Sprite rendering
- Camera
- Draw calls

---

## Week 7

Input System

- Keyboard
- Mouse
- Controller abstraction

---

## Week 8

Entity Component System

Topics

- Data-oriented design

Features

- Components
- Systems
- Entities

Game

Multiple objects.

---

## Week 9

Animation

- Sprite animation
- Timelines
- Animation state

---

## Week 10

Physics

- Collision
- Velocity
- Gravity

---

Publish

```

v0.2

Playable Demo

```

---

# Phase 3
## Performance Engineering

Weeks 11-15

This phase separates your project from ordinary tutorials.

---

## Week 11

Memory Allocators

Implement

- Arena allocator
- Pool allocator

Replace

```

malloc

↓

Custom allocator

```

Benchmark

Allocation speed.

---

## Week 12

Cache Optimization

Topics

- Cache lines
- Data layout

Benchmark

Frame time improvement.

---

## Week 13

SIMD

Topics

- SSE
- AVX

Optimize

- Physics
- Collision

Benchmark

Old vs New.

---

## Week 14

Thread Pool

Features

- Worker threads
- Job queue

Use

- Texture loading
- AI
- Physics

---

## Week 15

Job System

Parallelize

- Animation
- Physics
- Resource loading

---

Publish

```

v0.5

Performance Update

```

---

# Phase 4
## Systems Programming

Weeks 16-20

Goal

Turn the engine into real systems software.

---

## Week 16

Networking

- TCP
- UDP
- Client-server

---

## Week 17

Coroutines

Implement

- Async loading
- Timers

---

## Week 18

Serialization

- Save files
- JSON
- Binary

---

## Week 19

Asset Pipeline

- Compression
- Packaging
- Build tools

---

## Week 20

Scripting

Integrate

- Lua

or

- Custom scripting language

---

Publish

```

v0.8

Engine Feature Complete

```

---

# Phase 5
## Advanced Topics

Weeks 21-25

These are the portfolio-defining weeks.

---

## Week 21

Profiling

Integrate

- Tracy

Measure

- CPU
- Memory
- Frame time

---

## Week 22

AI

Implement

- Pathfinding
- Behavior Trees

---

## Week 23

Inference Runtime

Experiment

Run a tiny ONNX model inside the engine.

Show how AI can be embedded into native applications.

---

## Week 24

Multiplayer

Implement

- Client
- Server
- Synchronization

---

## Week 25

Polish

Improve

- Documentation
- Code quality
- Testing
- Benchmarks

---

Publish

```

v0.9

Release Candidate

```

---

# Phase 6

Week 26

## Final Release

Finish the game.

Requirements

- Menu
- Audio
- Multiplayer
- Save files
- Documentation
- Benchmarks
- CI
- Screenshots

---

Publish

```

v1.0

Complete Engine

```

---

# What Should Evolve Every Week?

Every week should improve at least one of these dimensions:

| Dimension | Example |
|-----------|---------|
| Features | New gameplay capability |
| Architecture | Better abstractions, cleaner modules |
| Performance | Lower frame time, reduced allocations |
| Code Quality | Refactoring, tests, documentation |
| Tooling | CI, formatting, profiling, packaging |

The goal is that a visitor can compare **Week 3** to **Week 20** and immediately recognize the growth.

---

# Monthly Articles

At the end of every four weeks publish an article.

Examples

```

Month 1

What I Learned About Modern C++

Month 2

Building My Own Engine

Month 3

Memory is Everything

Month 4

Parallel Programming in Practice

Month 5

Networking from Scratch

Month 6

Six Months Building an Engine

```

---

# Metrics to Track

Maintain a dashboard in the root README.

```

Weeks Completed

Commits

LOC

Benchmarks

Tests

FPS

Frame Time

Memory Usage

Release Version

```

Watching these metrics improve over six months reinforces the narrative of continuous engineering growth.

---

# Success Criteria

After 26 weeks, someone should be able to clone the repository, browse each release tag from **v0.1** to **v1.0**, and clearly see the progression from a blank SDL window to a polished, performant engine. The repository should demonstrate not just knowledge of C++, but disciplined software engineering: incremental development, architecture evolution, performance optimization, documentation, testing, and long-term consistency.
```

