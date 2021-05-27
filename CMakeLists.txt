cmake_minimum_required(VERSION 3.7)

project(tigame)

file(GLOB SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
file(GLOB EXTERNAL_SOURCES ${CMAKE_CURRENT_LIST_DIR}/external/*.c)

add_executable(${PROJECT_NAME} ${GAME_SOURCES} ${SOURCES} ${EXTERNAL_SOURCES} ${CMAKE_CURRENT_LIST_DIR}/glad/src/glad.c)
include_directories("${CMAKE_CURRENT_LIST_DIR}/src")
include_directories("${CMAKE_CURRENT_LIST_DIR}/glad/include")
include_directories("${CMAKE_CURRENT_LIST_DIR}/external")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	# glad requires linking against the dynamic linker (dl)
	target_link_libraries(${PROJECT_NAME} "dl")
endif()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} "${SDL2_LIBRARIES}" "${SDL2MAIN_LIBRARY}")
include_directories("${SDL2_INCLUDE_DIRS}")

find_package(PhysFS REQUIRED)
target_link_libraries(${PROJECT_NAME} "${PHYSFS_LIBRARY}")
include_directories("${PHYSFS_INCLUDE_DIR}")

find_package(PNG REQUIRED)
target_link_libraries(${PROJECT_NAME} "${PNG_LIBRARIES}")
include_directories("${PNG_INCLUDE_DIRS}")