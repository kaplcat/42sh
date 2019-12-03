# Base variables for 42sh

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
HEADER_H = -I ../includes/
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)
EXECUTABLE = 42sh
LIBNAME = libft.a
