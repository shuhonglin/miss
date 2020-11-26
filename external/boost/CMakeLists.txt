set(BOOST_VERSION 1.53.0)
# https://zhuanlan.zhihu.com/p/50829542
# settings for finding correct Boost libraries.
set(Boost_USE_STATIC_LIBS FALSE)
set(Boost_USE_MULTITHREADED TRUE)
set(Boost_USE_STATIC_RUNTIME FALSE)
set(Boost_ADDITIONAL_VERSIONS "${BOOST_VERSION}")
set(Boost_COMPILER "-gcc")

# search for Boost libraries
find_package(Boost ${BOOST_VERSION} EXACT REQUIRED 
    COMPONENTS program_options graph)

# make found targets globally available
# since cmake 3.11 IMPORTED targets can be promoted to global scope by setting the
# IMPORTED_GLOBAL property to TRUE 
if(Boost_FOUND)
    set_target_properties(Boost::boost Boost::program_options Boost::graph
        PROPERTIES IMPORTED_GLOBAL TRUE)
endif()
