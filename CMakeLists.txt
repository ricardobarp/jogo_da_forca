cmake_minimum_required(VERSION 4.0)
project(jogo_da_forca C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(jogo_da_forca
        funcoes.c
        funcoes.h
        main.c)
