cmake_minimum_required(VERSION 3.10)

project(HackAssembler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(HackAssembler
    src/main.cpp
    src/Assembler.cpp
    src/Code.cpp
    src/Parser.cpp
    src/SymbolTable.cpp
)

set_target_properties(HackAssembler PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
