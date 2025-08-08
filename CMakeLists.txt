cmake_minimum_required(VERSION 3.10)

project(HackAssembler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

add_executable(HackAssembler
    src/main.cpp
    src/Assembler.cpp
    src/Code.cpp
    src/Parser.cpp
    src/SymbolTable.cpp
)
