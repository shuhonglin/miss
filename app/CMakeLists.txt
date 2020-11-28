cmake_minimum_required(VERSION 3.18)
project(CalApp 
    VERSION 1.0
    DESCRIPTION "My fancy calculator app.")

add_subdirectory(entity)

# Freely available calculator app.
add_executable(miss)
target_sources(miss PRIVATE "main.cpp" )
target_link_libraries(miss
  PRIVATE 
    MyCalc::basicmath
    Boost::program_options
    # connector  #mysqlx api, use for mysql document, need mysql version larger than 5.7.xx
    connector-jdbc
    entity
)

# Premium-calculator app (with advanced functionality)
# add_executable(PremiumCalculator)
# target_sources(PremiumCalculator PRIVATE "src/main.cpp")
# target_link_libraries( PremiumCalculator
# PRIVATE MyCalc::extmath
# Boost::program_options connector)

# # Possibly, compile key-file into premium-calculator, too.
# if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/key-file.cpp")
# target_sources( PremiumCalculator
# PRIVATE "src/key-file.cpp" )
# endif()
