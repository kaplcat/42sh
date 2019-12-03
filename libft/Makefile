#####################################
#	████─█───████─████──████─█
#	█────█───█──█─█──██─█──█─█
#	█─██─█───█──█─████──████─█
#	█──█─█───█──█─█──██─█──█─█
#	████─███─████─████──█──█─███
#
#
#	█─█─████─████─███
#	█─█─█──█─█──█─█
#	█─█─████─████─███
#	███─█──█─█─█────█
#	─█──█──█─█─█──███
#
#####################################

LIBNAME=libft.a
CC=clang
CFLAGS=-Wall -Werror -Wextra -c
INC_DIR=inc
OBJ_DIR=obj
OBJ_FILE:=

#####################################
#	███─███─████─███─█──█─████
#	█────█──█──█──█──██─█─█
#	███──█──████──█──█─██─█─██
#	──█──█──█─█───█──█──█─█──█
#	███──█──█─█──███─█──█─████
#####################################

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

$(STRING_OBJ_FILES):
	@$(CC) $(CFLAGS) $(STRING_SRC_DIR)/$(notdir $(@:.o=.c)) -o $@ -I $(INC_DIR)/
	@echo "Compile " $(notdir $(@:.o=.c))

OBJ_FILE += $(STRING_OBJ_FILES)

#####################################
#	███─███─████──█───███─████
#	█────█──█──██─█────█──█──██
#	███──█──█──██─█────█──████
#	──█──█──█──██─█────█──█──██
#	███──█──████──███─███─████
#####################################

STDLIB_SRC_DIR:=src/stdlib
STDLIB_SRC_FILES:=\
	env_fnc.c \
	ft_atoi.c \
	ft_getenv.c \
	ft_setenv.c
STDLIB_OBJ_FILES:= $(STDLIB_SRC_FILES:.c=.o)
STDLIB_OBJ_FILES:= $(addprefix $(OBJ_DIR)/, $(STDLIB_OBJ_FILES))

$(STDLIB_OBJ_FILES):
	@$(CC) $(CFLAGS) $(STDLIB_SRC_DIR)/$(notdir $(@:.o=.c)) -o $@ -I $(INC_DIR)/
	@echo "Compile " $(notdir $(@:.o=.c))

OBJ_FILE += $(STDLIB_OBJ_FILES)

#################################
#	████─███─██─██─████─███
#	█──█──█───███──█──█─█
#	█─────█────█───████─███
#	█──█──█────█───█────█
#	████──█────█───█────███
#	───────────█
#################################

CTYPE_SRC_DIR:=src/ctype
CTYPE_SRC_FILES:=\
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isblank.c \
	ft_iscntrl.c \
	ft_isdigit.c \
	ft_isgraph.c \
	ft_islower.c \
	ft_isprint.c \
	ft_ispunct.c \
	ft_isspace.c \
	ft_isupper.c \
	ft_isxdigit.c \
	ft_tolower.c \
	ft_toupper.c
CTYPE_OBJ_FILES:= $(CTYPE_SRC_FILES:.c=.o)
CTYPE_OBJ_FILES:= $(addprefix $(OBJ_DIR)/, $(CTYPE_OBJ_FILES))

$(CTYPE_OBJ_FILES):
	@$(CC) $(CFLAGS) $(CTYPE_SRC_DIR)/$(notdir $(@:.o=.c)) -o $@ -I $(INC_DIR)/
	@echo "Compile " $(notdir $(@:.o=.c))

OBJ_FILE += $(CTYPE_OBJ_FILES)

#################################
#	███─███─████──███─████
#	█────█──█──██──█──█──█
#	███──█──█──██──█──█──█
#	──█──█──█──██──█──█──█
#	███──█──████──███─████
#################################

STDIO_SRC_DIR:=src/stdio
STDIO_SRC_FILES:=\
	ft_putendl_fd.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putstr.c \
	ft_putstr_fd.c
STDIO_OBJ_FILES:= $(STDIO_SRC_FILES:.c=.o)
STDIO_OBJ_FILES:= $(addprefix $(OBJ_DIR)/, $(STDIO_OBJ_FILES))


$(STDIO_OBJ_FILES):
	@$(CC) $(CFLAGS) $(STDIO_SRC_DIR)/$(notdir $(@:.o=.c)) -o $@ -I $(INC_DIR)/
	@echo "Compile " $(notdir $(@:.o=.c))

OBJ_FILE += $(STDIO_OBJ_FILES)

STDIO_PRINTF_SRCDIR:=$(STDIO_SRC_DIR)/printf/src
STDIO_PRINTF_INCDIR:=$(STDIO_SRC_DIR)/printf/inc
STDIO_PRINTF_SRC:=\
	ft_buf.c \
	ft_fitoa.c \
	ft_fuitoa.c \
	ft_printf_main.c \
	parse_dig.c \
	parse_format.c \
	parse_hndl.c \
	parse_sym.c \
	parse_types.c
STDIO_PRINTF_OBJ_FILES:= $(STDIO_PRINTF_SRC:.c=.o)
STDIO_PRINTF_OBJ_FILES:= $(addprefix $(OBJ_DIR)/, $(STDIO_PRINTF_OBJ_FILES))

$(STDIO_PRINTF_OBJ_FILES):
	@$(CC) $(CFLAGS) $(STDIO_PRINTF_SRCDIR)/$(notdir $(@:.o=.c)) -o $@ -I $(INC_DIR)/ -I $(STDIO_PRINTF_INCDIR)/
	@echo "Compile " $(notdir $(@:.o=.c))

OBJ_FILE += $(STDIO_PRINTF_OBJ_FILES)

#############################
#	█───█─████─█──█─███
#	██─██─█──█─█─█──█
#	█─█─█─████─██───███
#	█───█─█──█─█─█──█
#	█───█─█──█─█──█─███
#############################

all: print $(LIBNAME)

print:
	@echo \*\*\* Compiling libft

$(LIBNAME): $(OBJ_DIR) $(OBJ_FILE)
	@ar cr $(LIBNAME) $(OBJ_FILE)
	@echo "Create " $(LIBNAME)
	@echo "*** LIBFT COMPILED!\n"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

.PHONY : clean
clean:
	@rm -rf obj
# 	@echo "Remove " $(OBJ_DIR)

.PHONY : fclean
fclean: clean
	@rm -rf $(LIBNAME)
# 	@echo "Remove " $(LIBNAME)

.PHONY : re
re: fclean all
