cmake_minimum_required(VERSION 3.14)
project(esercitazione2)

set(CMAKE_CXX_STANDARD 17)

add_executable(esercitazione2 main.cpp filesystem/Base.cpp filesystem/Base.h filesystem/directory/Directory.cpp filesystem/directory/Directory.h filesystem/file/File.cpp filesystem/file/File.h)