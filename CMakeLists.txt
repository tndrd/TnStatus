cmake_minimum_required(VERSION 3.0)
project(TnStatus C)

add_library(TnStatus Src/TnStatus.c)
target_include_directories(TnStatus PUBLIC Inc/)