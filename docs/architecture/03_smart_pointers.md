# Week 3: Smart Pointer Hierarchy & Scene Graph

## Memory Strategy
- `std::unique_ptr` for exclusive engine subsystem ownership.
- `std::shared_ptr` for scene graph parent-child node relationships.
- `std::weak_ptr` for child-to-parent back pointers to prevent reference cycles.
