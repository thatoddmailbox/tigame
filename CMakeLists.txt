cmake_minimum_required(VERSION 3.7)

project(tigame)

file(GLOB SOURCES src/*.cpp)
file(GLOB EXTERNAL_SOURCES external/*.c)

add_executable(${PROJECT_NAME} ${SOURCES} ${EXTERNAL_SOURCES} glad/src/glad.c)
include_directories("src")
include_directories("glad/include")
include_directories("external")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	# glad requires linking against the dynamic linker (dl)
	target_link_libraries(${PROJECT_NAME} "dl")
endif()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} "${SDL2_LIBRARY}" "${SDL2MAIN_LIBRARY}")
include_directories("${SDL2_INCLUDE_DIR}")

find_package(PhysFS REQUIRED)
target_link_libraries(${PROJECT_NAME} "${PHYSFS_LIBRARY}")
include_directories("${PHYSFS_INCLUDE_DIR}")