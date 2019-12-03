# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 15:35:38 by yquaro            #+#    #+#              #
#    Updated: 2019/12/03 18:15:41 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/sh42.mk

all: print
	@make -C autocom/ all
	@make -C history/ all
	@make -C terminal/ all
	@make -C obj/ all

print:
	@echo \*\*\* Compiling readline

clean:
	@make -C obj/ clean

fclean: clean
	@make -C obj/ fclean

re: fclean all
