cmake_minimum_required (VERSION 2.6)
project (sorting)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O4")

FILE (GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.c"
	               "${PROJECT_SOURCE_DIR}/include/*.h")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable (test_sorting ${SOURCES})

if(BINHEAP_PATH)
	message("Linking binheap library")
	add_library(binheap SHARED IMPORTED) 

	set_target_properties(binheap PROPERTIES
  		IMPORTED_LOCATION "${BINHEAP_PATH}/lib/libbinheap.so"
  		INTERFACE_INCLUDE_DIRECTORIES "${BINHEAP_PATH}/include/"
	)

	target_link_libraries(test_sorting "binheap")
endif(BINHEAP_PATH)
