NAME := prt.a

SRC :=	print_f.c	h_put_char.c	h_put_nbr.c	h_put_base.c	\
		h_put_ptr.c	h_put_str.c		h_strlen.c

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
