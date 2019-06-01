cmake_minimum_required(VERSION 2.8)

PROJECT(LOG4CXX)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#SET(CMAKE_C_COMPILER "/usr/bin/gcc")
#SET(CMAKE_CXX_COMPILER "/usr/bin/g++")

SET(CMAKE_BUILD_TYPE "Release")  # Debug模式 选项: Release Debug MinSizeRel RelWithDebInfo

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  # debug模式下 gdb相关选项
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") # release模式下 gdb相关选项

# set(CMAKE_VERBOSE_MAKEFILE ON) # 开启调试 出现问题时开启

INCLUDE_DIRECTORIES("./log4cpp/include")
ADD_SUBDIRECTORY(log4cpp)
LINK_DIRECTORIES(log4cpp)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

ADD_EXECUTABLE(func ${DIR_SRCS})
TARGET_LINK_LIBRARIES(func liblog4cpp.a pthread)
