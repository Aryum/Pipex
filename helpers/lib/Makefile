NAME := lib.a

SRC :=	lib_isalpha.c		lib_isdigit.c	lib_isalnum.c		lib_isascii.c	lib_isprint.c	\
		lib_strlen.c		lib_memset.c	lib_bzero.c			lib_memcpy.c	lib_memmove.c	\
		lib_strlcpy.c		lib_strlcat.c	lib_toupper.c		lib_tolower.c	lib_strchr.c	\
		lib_strrchr.c		lib_strncmp.c	lib_memchr.c		lib_memcmp.c	lib_strnstr.c	\
		lib_atoi.c			lib_calloc.c	lib_strdup.c		lib_substr.c	lib_strjoin.c	\
		lib_strtrim.c		lib_split.c		lib_itoa.c			lib_strmapi.c	lib_striteri.c	\
		lib_putchar_fd.c	lib_putstr_fd.c	lib_putendl_fd.c	lib_putnbr_fd.c

HDR_DIR := .

FLAGS := -Wall -Wextra -Werror

AR := ar -rcs

RM := rm -f

blank :=
define NEWLINE

$(blank)
endef

COLOUR_GREEN := \033[1;32m
COLOUR_RED := \033[1;31m
COLOUR_YELLOW := \033[1;33m
COLOUR_BLUE := \033[1;34m
COLOR_WHITE := \033[0m

all: $(NAME)

$(NAME): $(SRC)
	@$(foreach cfile,$(SRC), cc $(FLAGS) -o $(cfile:.c=.o) -c $(cfile) -I$(HDR_DIR) $(NEWLINE))
	@$(AR) $@ $(SRC:.c=.o)
	@echo "$(COLOUR_GREEN)	Making $(NAME)$(COLOUR_WHITE)"
	@$(RM) $(SRC:.c=.o)

clean:
	@$(RM) $(SRC:.c=.o)
	@echo "$(COLOUR_YELLOW)	Cleaning objects of $(NAME)$(COLOUR_WHITE)"

fclean:
	@$(RM) $(NAME)
	@$(RM) $(SRC:.c=.o)
	@echo "$(COLOUR_RED)	Cleaning $(NAME)$(COLOUR_WHITE)"

re: fclean all

.PHONY: all clean fclean re
