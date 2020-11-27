cmake_minimum_required(VERSION 3.19.1)
SET(CMAKE_C_COMPILER /opt/rh/devtoolset-7/root/bin/gcc)
SET(CMAKE_CXX_COMPILER /opt/rh/llvm-toolset-7/root/bin/clang++)

project(miss VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include(CTest)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# make external libraries globally available.
add_subdirectory(external)

# create targets for building the (local) libraries.
add_subdirectory(library)

# create the targets for the entire app 
add_subdirectory(app)

#enable_testing()

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
