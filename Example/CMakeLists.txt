cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME Example)

project(${PROJECT_NAME})

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (SOURCES
	${SOURCE_DIR}/source.cpp)

include_directories(${WS_Server_INCLUDE_DIRS})

find_package(Threads)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} 
${Boost_LIBRARY_DIR}/libboost_system.a
${Boost_LIBRARY_DIR}/libboost_thread.a
${Proto_LIBRARY_DIR}/libprotobuf.a
AsyncServerParent
HtmlHandle
WS_Server)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 11)
