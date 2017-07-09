cmake_minimum_required(VERSION 2.8)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)


set (SOURCES
	${SOURCE_DIR}/source.cpp)
	
set(Boost_INCLUDE_DIR "/usr/local/src/boost_1_64_0" CACHE STRING "The directories of the boost header files")
set(Boost_LIBRARY_DIR "/usr/local/src/boost_1_64_0/stage/lib"  CACHE STRING "The directories of the boost library files")

set(Proto_INCLUDE_DIR "/usr/local/src/protobuf-3.3.0/install/include" CACHE STRING "The directories of the proto header files")
set(Proto_LIBRARY_DIR "/usr/local/src/protobuf-3.3.0/install/lib" CACHE STRING "The directories of the proto library files")
Message(STATUS "ProtoLibDir: " ${Proto_LIBRARY_DIR})

add_subdirectory(HtmlHandle)
add_subdirectory(AsyncServerParent)
add_subdirectory(WS_Server)
add_subdirectory(Example)
