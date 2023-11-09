cmake_minimum_required(VERSION 3.0.2)
project(TnStatus C)

set(CMAKE_C_FLAGS "-Werror")
option(TN_STATUS_EXTENDED "TnStatus extended mode" OFF)

if(TN_STATUS_EXTENDED)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -DTN_STATUS_EXTENDED")
endif(TN_STATUS_EXTENDED)

unset(TN_STATUS_EXTENDED CACHE)

add_library(TnStatus Src/TnStatus.c)
target_include_directories(TnStatus PUBLIC Inc/)