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
	${HEADER_DIR}/PackFW.pb.h)
	
set (SOURCES
	${SOURCE_DIR}/WSHeaderManager.cpp
	${SOURCE_DIR}/WSIPacket.cpp
	${SOURCE_DIR}/WSOPacket.cpp
	${SOURCE_DIR}/WSServer.cpp
	${SOURCE_DIR}/PackFW.pb.cc)

include_directories(${HEADER_DIR}
	${AsyncServerParent_INCLUDE_DIRS}
	${HtmlHandle_INCLUDE_DIRS})

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARY_DIR}/libboost_system.a
	${Boost_LIBRARY_DIR}/libboost_thread.a
	${Proto_LIBRARY_DIR}/libprotobuf.a
	HtmlHandle
	AsyncServerParent)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 11)

set(${PROJECT_NAME}_INCLUDE_DIRS ${HEADER_DIR}
${AsyncServerParent_INCLUDE_DIRS}
${HtmlHandle_INCLUDE_DIRS}
CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

