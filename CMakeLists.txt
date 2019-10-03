cmake_minimum_required(VERSION 3.10)
project(basic_algorithms LANGUAGES CXX)
find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -Wall -O3 -Wextra -Werror=unknown-pragmas")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add strip capability when build type is release
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("-- Release build type, binaries will be stripped")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s")
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
message("-- Intel compiler detected, flags: -xCORE-AVX512 -qopenmp-link=static -qopt-zmm-usage=high -qopt-report=5 -qopt-report-phase=vec are applied")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -xCORE-AVX512 -qopenmp-link=static -qopt-report=5 -qopt-report-phase=vec -qopt-zmm-usage=high")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -qopenmp-link=static -qopt-report=5 -qopt-report-phase=vec -qopt-zmm-usage=high")
endif()

set(SOURCES
    src/main.cpp
    src/LinkedList.cpp
    src/Array.cpp
    src/Search.cpp
    src/Bits.cpp
    src/Sort.cpp
    src/BST.cpp
    src/Graph.cpp
    src/Algo.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/src/) 
add_executable(basic_algo ${SOURCES}) 
