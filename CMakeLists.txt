cmake_minimum_required(VERSION 3.0.2)
project(TnStatus C)

set(CMAKE_C_FLAGS "-Werror")
option(TN_STATUS_LIGHT "TnStatus light mode" OFF)

if(TN_STATUS_LIGHT)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -DTN_STATUS_LIGHT")
endif(TN_STATUS_LIGHT)

unset(TN_STATUS_LIGHT CACHE)

add_library(TnStatus Src/TnStatus.c)
target_include_directories(TnStatus PUBLIC Inc/)
