cmake_minimum_required(VERSION 3.10)
project(DesignPatternsInCpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Werror)

# Add subdirectories
add_subdirectory(visitor)
add_subdirectory(factory)