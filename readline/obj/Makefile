# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 18:00:45 by yquaro            #+#    #+#              #
#    Updated: 2019/12/04 21:09:21 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../inc/sh42.mk

all:
	@ar rc $(READLINE_LIBNAME) *.o
	@echo "Create " $(READLINE_LIBNAME)
	@ranlib $(READLINE_LIBNAME)
	@mv $(READLINE_LIBNAME) ../$(READLINE_LIBNAME)
	@echo "*** READLINE COMPILED!\n"

clean:
	@rm -f *.o

fclean: clean
	@rm -f ../$(READLINE_LIBNAME)
