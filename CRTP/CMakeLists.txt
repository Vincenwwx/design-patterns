project(CRTPPattern)

include_directories(include)

# file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    # ${SOURCES}
)