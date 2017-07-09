cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME WSS_Server)

project(${PROJECT_NAME})

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (HEADERS
	${HEADER_DIR}/WSS_Server.h
	${HEADER_DIR}/WSS_ServicePool.h
	${HEADER_DIR}/WSS_TCPAcceptor.h
	${HEADER_DIR}/WSS_TCPConnection.h)
	
set (SOURCES
	${SOURCE_DIR}/WSS_Server.cpp
	${SOURCE_DIR}/WSS_ServicePool.cpp
	${SOURCE_DIR}/WSS_TCPAcceptor.cpp
	${SOURCE_DIR}/WSS_TCPConnection.cpp)

include_directories(${HEADER_DIR}
	${WS_Server_INCLUDE_DIRS}
	${Sll_INCLUDE_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARY_DIR}/libboost_system.a
				      ${Boost_LIBRARY_DIR}/libboost_thread.a
				      ${Proto_LIBRARY_DIR}/libprotobuf.a
				      ${Sll_LIBRARY_DIR}/libssl.a
				      ${Sll_LIBRARY_DIR}/libcrypto.a
				      AsyncServerParent
				      HtmlHandle
				      WS_Server)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 11)

set(${PROJECT_NAME}_INCLUDE_DIRS ${HEADER_DIR}
				 ${WS_Server_INCLUDE_DIRS}
				 ${Sll_INCLUDE_DIR}
			CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
