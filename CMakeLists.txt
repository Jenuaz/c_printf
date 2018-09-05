cmake_minimum_required(VERSION 3.9)
project(ft_printf)

set(CMAKE_CXX_STANDARD 11)

add_executable(ft_printf
        ft_printf.c
        ft_printf.h
        main.c
        parsing.c
        hex.c
        ft_put_count.c
        octal.c
        ft_put_char.c)
