project(VisitorPattern)

include_directories(include)

file(GLOB_RECURSE OO_IMPL_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/oo_impl/shapes/*.cpp
)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${OO_IMPL_SOURCES}
)