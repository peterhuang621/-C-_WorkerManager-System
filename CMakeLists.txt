cmake_minimum_required(VERSION 3.22.2)

project(work_sys)

include_directories(lib)

aux_source_directory(lib libs)

add_executable(demo src/main.cpp ${libs})
