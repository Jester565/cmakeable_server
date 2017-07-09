cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME HtmlHandle)

project(${PROJECT_NAME})

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (HEADERS
	${HEADER_DIR}/base64_converter.h
	${HEADER_DIR}/dataframe.h
	${HEADER_DIR}/dataframe_manager.h
	${HEADER_DIR}/dataframe_parser.h
	${HEADER_DIR}/handshake_manager.h
	${HEADER_DIR}/header.h
	${HEADER_DIR}/reply.h
	${HEADER_DIR}/request.h
	${HEADER_DIR}/request_handler.h
	${HEADER_DIR}/request_parser.h
	${HEADER_DIR}/SHA1.h
	${HEADER_DIR}/tribool.h)
	
set (SOURCES
	${SOURCE_DIR}/base64_converter.cpp
	${SOURCE_DIR}/dataframe.cpp
	${SOURCE_DIR}/dataframe_manager.cpp
	${SOURCE_DIR}/dataframe_parser.cpp
	${SOURCE_DIR}/handshake_manager.cpp
	${SOURCE_DIR}/reply.cpp
	${SOURCE_DIR}/request_handler.cpp
	${SOURCE_DIR}/request_parser.cpp
	${SOURCE_DIR}/SHA1.cpp)
include_directories(${HEADER_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 11)

set(${PROJECT_NAME}_INCLUDE_DIRS ${HEADER_DIR}
	CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
