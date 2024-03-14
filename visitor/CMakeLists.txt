project(VisitorPattern)

include_directories(include)

file(GLOB_RECURSE INHERITANCE_IMPL_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/inh_impl/shapes/*.cpp
)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${INHERITANCE_IMPL_SOURCES}
)