cmake_minimum_required(VERSION 3.16)
project(Min_max)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib )

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_library(nr_lib SHARED ../headers/max.h ../src/max.cpp ../headers/min.h ../src/min.cpp ../headers/operations.h ../src/operations.cpp)

add_executable(main
../main.cpp)

add_executable(testMax
../unit_test/test_max.cpp)

add_executable(testMin
../unit_test/test_min.cpp)

add_executable(testMath
../unit_test/test_operations.cpp)

find_package(Boost CONFIG COMPONENTS system filesystem unit_test_framework REQUIRED)

target_link_libraries(testMax 
  nr_lib
  Boost::unit_test_framework
  )

target_link_libraries(testMin 
nr_lib
Boost::unit_test_framework
)

target_link_libraries(testMath 
nr_lib
Boost::unit_test_framework
)

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"
