# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 15:35:38 by yquaro            #+#    #+#              #
#    Updated: 2019/12/03 16:27:53 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/sh42.mk

all: print
	@make -C autocom/ all
	@make -C history/ all
	@make -C terminal/ all

print:
	@echo \*\*\* Compiling readline

clean:
	@make -C autocom/ clean
	@make -C history/ clean
	@make -C terminal/ clean

fclean: clean
	@make -C autocom/ fclean
	@make -C history/ fclean
	@make -C terminal/ fclean

re: fclean all
