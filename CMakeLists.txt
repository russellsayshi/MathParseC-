cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)

project(cmathparse_project)

add_library(cmathparse STATIC interpreter.cpp lexer.cpp token.cpp)

install(TARGETS cmathparse DESTINATION lib)
install(FILES interpreter.h lexer.h token.h tokentype.h DESTINATION include)
