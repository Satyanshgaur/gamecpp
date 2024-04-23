add_library(Engine STATIC
    src/core/Window.cpp
    src/core/Logger.cpp
)

target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

find_package(SDL2 REQUIRED CONFIG OPTIONAL_COMPONENTS)
if(SDL2_FOUND)
    target_link_libraries(Engine PRIVATE SDL2::SDL2)
    target_compile_definitions(Engine PUBLIC ENGINE_HAS_SDL2)
endif()
