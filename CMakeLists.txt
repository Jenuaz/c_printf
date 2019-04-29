cmake_minimum_required(VERSION 3.9)
project(ft_printf)

set(CMAKE_CXX_STANDARD 11)

add_executable(ft_printf
        ft_printf.c
        ft_printf.h
        main.c
        parsing.c
        ft_digits_hex.c
        ft_digits_o.c
        ft_put_count.c
        ft_put_char.c
        ft_char.c
        ft_digits_di.c
        ft_pointer.c
        ft_char_string.c
        ft_percent.c
        ft_char_char.c)
