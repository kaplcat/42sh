# GLOBAL VARS

LIBNAME=libft.a
CC=clang
CFLAGS= -Wall -Werror -Wextra -c
INC_DIR=inc
OBJ_DIR=obj


#################################
#
#	STRING
#
###########################################

STRING_SRC_DIR:=src/string
STRING_SRC_FILES:=\
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_mempcpy.c \
	ft_memrchr.c \
	ft_memset.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strcspn.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnlen.c \
	ft_strnstr.c \
	ft_strpbrk.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strspn.c \
	ft_strstr.c

STRING_OBJ_FILES:= $(STRING_SRC_FILES:.c=.o)
STRING_OBJ_FILES:= $(addprefix $(OBJ_DIR)/, $(STRING_OBJ_FILES))


all: $(LIBNAME)

$(LIBNAME): $(OBJ_DIR) $(STRING_OBJ_FILES)
	@ar cr $(LIBNAME) $(STRING_OBJ_FILES)
	@echo "Create " $(LIBNAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(STRING_OBJ_FILES):
	@$(CC) $(CFLAGS) $(STRING_SRC_DIR)/$(notdir $(@:.o=.c)) -o $@ -I $(INC_DIR)/
	@echo "Compile " $(notdir $(@:.o=.c))

.PHONY : clean
clean:
	@rm -rf obj
	@echo "Remove " $(OBJ_DIR)

.PHONY : fclean
fclean: clean
	@rm -rf $(LIBNAME)
	@echo "Remove " $(LIBNAME)

.PHONY : re
re: fclean all