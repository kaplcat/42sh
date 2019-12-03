# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 15:35:48 by yquaro            #+#    #+#              #
#    Updated: 2019/12/03 16:27:56 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/sh42.mk

HEADER_H = -I ../includes/

DIR_O = ../../obj
SOURCES = test_autocom.c # sources here
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling autocom

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
