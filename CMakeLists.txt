cmake_minimum_required(VERSION 3.18)
if(APPLE)
    set(CMAKE_C_COMPILER /usr/bin/clang)
    set(CMAKE_CXX_COMPILER /usr/bin/clang++)
    set(OPENSSL_ROOT_DIR /usr/local/opt/openssl@1.1)

    set(MYSQL_DIR /usr/local/Cellar/mysql/8.0.22_1)
    # set(MYSQL_DIR /usr/local/mysql-5.6.28-osx10.8-x86_64)
    # set(MYSQL_INCLUDE_DIR /usr/local/Cellar/mysql/8.0.22_1/include)
    # set(MYSQL_LIB_DIR /usr/local/Cellar/mysql/8.0.22_1/include)

    # set(WITH_JDBC ON)
    # set(CMAKE_INSTALL_PREFIX /usr/local/)
    # set(CMAKE_INSTALL_INCLUDEDIR include)
    # set(CMAKE_INSTALL_LIBDIR lib)
    # set(WITH_SSL /usr/local/opt/openssl@1.1)
    # set(MYSQLCLIENT_STATIC_LINKING OFF)
elseif(WIN32)

else()
    set(CMAKE_C_COMPILER /opt/rh/devtoolset-7/root/bin/clang)
    set(CMAKE_CXX_COMPILER /opt/rh/llvm-toolset-7/root/bin/clang++)
endif()

project(miss VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(WITH_JDBC ON)
set(CMAKE_INSTALL_PREFIX /usr/local/)
set(CMAKE_INSTALL_INCLUDEDIR include)
set(CMAKE_INSTALL_LIBDIR lib)
set(WITH_SSL /usr/local/opt/openssl@1.1)
set(MYSQLCLIENT_STATIC_LINKING OFF)

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