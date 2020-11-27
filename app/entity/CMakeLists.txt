add_library(entity STATIC)
target_sources(entity
  PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/book.cpp
  PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/book.h
)
target_include_directories(entity
  PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}
)