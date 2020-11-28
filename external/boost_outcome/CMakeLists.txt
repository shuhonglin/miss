# 导入纯头文件库
# https://blog.csdn.net/LaineGates/article/details/108242803
cmake_minimum_required(VERSION 3.11)

project(External.Reviewed_Boost.outcome 
        VERSION 2.0 
        DESCRIPTION "Boost.Outcome header-only lib.")

# provide target for "Boost.Outcome" library.
add_library(Reviewed_Boost.outcome INTERFACE IMPORTED GLOBAL)

# Store include search-path containing headers
# of "Boost.Outcome".
target_include_directories(Reviewed_Boost.outcome SYSTEM 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
# Require at least compiling with C++11.
target_compile_features(Reviewed_Boost.outcome 
    INTERFACE cxx_std_11)

# Create an alias for "Boost.Outcome".
add_library(Boost::outcome ALIAS Reviewed_Boost.outcome)
