cmake_minimum_required(VERSION 3.19.1)
project(miss VERSION 0.1.0)

#include(CTest)
#enable_testing()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# make external libraries globally available.
add_subdirectory(external)

# create targets for building the (local) libraries.
add_subdirectory(library)

# create the targets for the entire app 
add_subdirectory(app)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
