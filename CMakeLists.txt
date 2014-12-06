cmake_minimum_required(VERSION 2.6)
project (cmake_test)

# The version number.
set (test_VERSION_MAJOR 1)
set (test_VERSION_MINOR 0)

#Should we use our implementation of math functions?
option(USE_MYMATH
		"Use test provided math implementation"
		ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/Config.h.in"
    "${PROJECT_BINARY_DIR}/Config.h"
)

if (USE_MYMATH)
	include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
	add_subdirectory (MathFunctions)
	#add_library(MathFunctions ${PROJECT_SOURCE_DIR}/MathFunctions/mysqrt.cpp)
	set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

add_executable(test test.cpp)
target_link_libraries(test ${EXTRA_LIBS})

# add the install targets
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"        
         DESTINATION include)
