# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 15:33:09 by yquaro            #+#    #+#              #
#    Updated: 2019/12/03 18:14:07 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include includes/sh42.mk

all:
	@make -C libft/ all
	@make -C readline/ all
	@make -C src/ all
	@make -C obj/ all

clean:
	@make -C libft/ clean
	@make -C readline/ clean
	@make -C obj/ clean

fclean: clean
	@make -C libft/ fclean
	@make -C readline/ fclean
	@make -C obj/ fclean
	@rm -f $(EXECUTABLE)

re: fclean all
