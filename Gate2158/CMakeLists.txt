cmake_minimum_required(VERSION 3.3)
project(Gate2158)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/Gate2158.cpp
        src/Map.cpp
        src/Map.h
        src/MapObject.cpp
        src/MapObject.h
        src/MovableMapObject.cpp
        src/MovableMapObject.h
        src/UserInteractableMapObject.cpp
        src/UserInteractableMapObject.h
        src/Character.cpp Gate2158/Character.h)

#Test auto include all source files
AUX_SOURCE_DIRECTORY(./Gate2158 DIR_ALL_SRC)

add_executable(Gate2158 ${SOURCE_FILES} ${DIR_ALL_SRC})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Gate2158 ${SFML_LIBRARIES})
endif()

