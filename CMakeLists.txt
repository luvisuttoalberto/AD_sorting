cmake_minimum_required (VERSION 2.6)
project (strassen)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O4")

FILE (GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.c"
	               "${PROJECT_SOURCE_DIR}/*.h")

add_executable (test_sorting ${SOURCES})

