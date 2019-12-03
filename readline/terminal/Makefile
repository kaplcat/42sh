# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 15:36:05 by yquaro            #+#    #+#              #
#    Updated: 2019/12/03 20:25:23 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/sh42.mk

HEADER_H = -I ../includes/

DIR_O = ../obj
SOURCES = test_terminal.c # sources here
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling terminal

$(DIR_O)/%.o: %.c
	@$(COMPILING) $< -o $@
	@echo "Compile " $(notdir $(@:.o=.c))
