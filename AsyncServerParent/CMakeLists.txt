cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME AsyncServerParent)

project(${PROJECT_NAME})

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (HEADERS
	${HEADER_DIR}/Client.h
	${HEADER_DIR}/ClientManager.h
	${HEADER_DIR}/HeaderManager.h
	${HEADER_DIR}/IPacket.h
	${HEADER_DIR}/Logger.h
	${HEADER_DIR}/Macros.h
	${HEADER_DIR}/OPacket.h
	${HEADER_DIR}/PacketManager.h
	${HEADER_DIR}/PKey.h
	${HEADER_DIR}/PKeyOwner.h
	${HEADER_DIR}/Server.h
	${HEADER_DIR}/ServicePool.h
	${HEADER_DIR}/TCPAcceptor.h
	${HEADER_DIR}/TCPConnection.h)
	
set (SOURCES
	${SOURCE_DIR}/Client.cpp
	${SOURCE_DIR}/ClientManager.cpp
	${SOURCE_DIR}/HeaderManager.cpp
	${SOURCE_DIR}/IPacket.cpp
	${SOURCE_DIR}/OPacket.cpp
	${SOURCE_DIR}/PacketManager.cpp
	${SOURCE_DIR}/PKey.cpp
	${SOURCE_DIR}/PKeyOwner.cpp
	${SOURCE_DIR}/Server.cpp
	${SOURCE_DIR}/ServicePool.cpp
	${SOURCE_DIR}/TCPAcceptor.cpp
	${SOURCE_DIR}/TCPConnection.cpp)
	
set(Boost_INCLUDE_DIR "/usr/local/src/boost_1_64_0" CACHE STRING "The directories of the boost header files")
set(Boost_LIBRARY_DIR "/usr/local/src/boost_1_64_0/stage/lib"  CACHE STRING "The directories of the boost library files")

set(Proto_INCLUDE_DIR "/usr/local/src/protobuf-3.3.0/install/include")
set(Proto_LIBRARY_DIR "/usr/local/src/protobuf-3.3.0/install/lib")

include_directories(${Boost_INCLUDE_DIR})
include_directories(${Proto_INCLUDE_DIR})

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARY_DIR}/libboost_system.a)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARY_DIR}/libboost_thread.a)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARY_DIR}/libboost_serialization.a)

target_link_libraries(${PROJECT_NAME} ${Proto_LIBRARY_DIR}/libprotobuf.a)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 11)