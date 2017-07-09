cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME WS_Server)

project(${PROJECT_NAME})

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (HEADERS
	${HEADER_DIR}/WSHeaderManager.h
	${HEADER_DIR}/WSIPacket.h
	${HEADER_DIR}/WSOPacket.h
	${HEADER_DIR}/WSServer.h
	${HEADER_DIR}/Packets/PackFW.pb.h)
	
set (SOURCES
	${SOURCE_DIR}/WSHeaderManager.cpp
	${SOURCE_DIR}/WSIPacket.cpp
	${SOURCE_DIR}/WSOPacket.cpp
	${SOURCE_DIR}/WSServer.cpp
	${SOURCE_DIR}/Packets/PackFW.pb.cc)
	
set(Boost_INCLUDE_DIR "/usr/local/src/boost_1_64_0" CACHE STRING "The directories of the boost header files")
set(Boost_LIBRARY_DIR "/usr/local/src/boost_1_64_0/stage/lib"  CACHE STRING "The directories of the boost library files")

set(Proto_INCLUDE_DIR "/usr/local/src/protobuf-3.3.0/install/include")
set(Proto_LIBRARY_DIR "/usr/local/src/protobuf-3.3.0/install/lib")

set(AsyncPar_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../AsyncServerParent/include)
set(AsyncPar_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../AsyncServerParent/build)

set(HtmlHandle_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../HtmlHandle/include)
set(HtmlHandle_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../HtmlHandle/build)

include_directories(${HEADER_DIR})
include_directories(${Boost_INCLUDE_DIR})
include_directories(${Proto_INCLUDE_DIR})
include_directories(${AsyncPar_INCLUDE_DIR})
include_directories(${HtmlHandle_INCLUDE_DIR})

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARY_DIR}/libboost_system.a)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARY_DIR}/libboost_thread.a)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARY_DIR}/libboost_serialization.a)

target_link_libraries(${PROJECT_NAME} ${Proto_LIBRARY_DIR}/libprotobuf.a)

target_link_libraries(${PROJECT_NAME} ${AsyncPar_LIBRARY_DIR}/libAsyncServerParent.a)
target_link_libraries(${PROJECT_NAME} ${HtmlHandle_LIBRARY_DIR}/libHtmlHandle.a)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 11)
