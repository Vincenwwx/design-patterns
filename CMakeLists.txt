cmake_minimum_required(VERSION 3.10)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE OO_IMPL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/oo_impl/shapes/*.cpp
)

add_compile_options(-Wall -Werror)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${OO_IMPL_SOURCES}
)