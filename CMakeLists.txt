cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME Example)

project(${PROJECT_NAME})

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Example/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Example/src)

set (SOURCES
	${SOURCE_DIR}/source.cpp)
	
set(Boost_INCLUDE_DIR "/usr/local/src/boost_1_64_0" CACHE STRING "The directories of the boost header files")
set(Boost_LIBRARY_DIR "/usr/local/src/boost_1_64_0/stage/lib"  CACHE STRING "The directories of the boost library files")

set(Proto_INCLUDE_DIR "/usr/local/src/protobuf-3.3.0/install/include" CACHE STRING "The directories of the proto header files")
set(Proto_LIBRARY_DIR "/usr/local/src/protobuf-3.3.0/install/lib" CACHE STRING "The directories of the proto library files")

set(AsyncPar_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/AsyncServerParent/include)
set(AsyncPar_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/AsyncServerParent/build)

set(HtmlHandle_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/HtmlHandle/include)
set(HtmlHandle_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/HtmlHandle/build)

set(WS_Server_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/WS_Server/include)
set(WS_Server_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/WS_Server/build)

set(WSS_Server_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/WSS_Server/include)
set(WSS_Server_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/WSS_Server/build)

include_directories(${WS_Server_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARY_DIR}/libboost_system.a
${Boost_LIBRARY_DIR}/libboost_thread.a
${Boost_LIBRARY_DIR}/libboost_serialization.a
${PROJECT_NAME} ${Proto_LIBRARY_DIR}/libprotoc.a
${Proto_LIBRARY_DIR}/libprotobuf.a
AsyncServerParent
HtmlHandle
WS_Server)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 11)
