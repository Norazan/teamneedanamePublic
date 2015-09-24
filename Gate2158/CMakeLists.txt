cmake_minimum_required(VERSION 3.3)
project(Gate2158)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Gate2158/Gate2158.cpp
        Gate2158/ball.cpp
        Gate2158/ball.h
        Gate2158/rectangle.cpp
        Gate2158/rectangle.h
    )
add_executable(Gate2158 ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Gate2158 ${SFML_LIBRARIES})
endif()

