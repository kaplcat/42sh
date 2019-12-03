# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 15:51:35 by yquaro            #+#    #+#              #
#    Updated: 2019/12/03 16:32:36 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/sh42.mk

HEADER_H = -I ../includes/

DIR_O = ../obj
SOURCES = makefile_test.c # sources here
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling src

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
