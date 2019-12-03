# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 15:36:16 by yquaro            #+#    #+#              #
#    Updated: 2019/12/03 18:03:41 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/sh42.mk

CFLAGS = -g -Wall -Wextra -Werror
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)

LIBS = $(LIBNAME) $(READLINE_LIBNAME)

all:
	@mv ../libft/$(LIBNAME) $(LIBNAME)
	@mv ../readline/$(READLINE_LIBNAME) $(READLINE_LIBNAME)
	$(COMPILING) *.o $(LIBS) -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ../$(EXECUTABLE)
	@echo \*\*\* 42_SH COMPILED!

clean:
	@rm -f *.o

fclean:
	@rm -f $(LIBNAME)