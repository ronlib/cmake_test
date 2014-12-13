cmake_minimum_required(VERSION 2.6)

# first we add the executable that generates the table
add_executable(MakeTable MakeTable.cpp)
# add the generated header file to the compilation process of test
 	add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
)

# 
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_library(MathFunctions mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)

MESSAGE(${PROJECT_BINARY_DIR})
