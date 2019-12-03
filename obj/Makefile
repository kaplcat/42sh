# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 15:36:16 by yquaro            #+#    #+#              #
#    Updated: 2019/12/03 16:45:13 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/sh42.mk

CFLAGS = -g -Wall -Wextra -Werror
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)

all:
	@mv ../libft/$(LIBNAME) $(LIBNAME)
	$(COMPILING) *.o $(LIBNAME) -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ../$(EXECUTABLE)
	@echo \*\*\* 42_SH COMPILED!

clean:
	@rm -f *.o

fclean:
	@rm -f $(LIBNAME)