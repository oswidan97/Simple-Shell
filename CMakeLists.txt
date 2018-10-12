cmake_minimum_required(VERSION 3.7)
project(SimpleShell)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c shell.c shell.h input.c input.h process.c process.h tokenizer.c tokenizer.h)
add_executable(SimpleShell ${SOURCE_FILES})
