cmake_minimum_required(VERSION 2.8)

project(udp_sender)

# add cxx flags
add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")

aux_source_directory(src SRCS)
include_directories(
  include
)

add_library(udp_sender SHARED ${SRCS})
add_library(udp_sender_static ${SRCS})

SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/build)
IF (BUILD_EXAMPLE)
  add_executable(udp_sender_example example/main.cpp)

  add_dependencies(udp_sender_example
    udp_sender
  )

  target_link_libraries(udp_sender_example
    udp_sender
  )

  install(TARGETS udp_sender_example DESTINATION ${CMAKE_INSTALL_PREFIX}/example)
ENDIF (BUILD_EXAMPLE)

SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/build)

install(FILES include/udp_sender.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
install(TARGETS udp_sender udp_sender_static
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)
