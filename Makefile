# Colors:
NC			=	\033[0m
LRED		=	\033[0;31m
GREEN		=	\033[0;32m
LRED		=	\033[1;31m
LGREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
LBLUE		=	\033[1;34m
TITLE		=	\033[38;5;33m

# Compile variables
LIB_CC		=	ar rcT
CC			=	gcc -Wall -Wextra -Werror


# Code variables
NAME		=	ft_pushswap

SRCS		=	src/ft_pushswap.c

OBJS		=	${SRCS:src/%.c=bin/%.o}


# Makefile logic
all: $(NAME)
re: fclean all

$(NAME):	$(OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(NAME)${NC} \c"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "${LGREEN}[OK]${NC}"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME) \c"
	@rm -f $(NAME)
	@echo "${LGREEN}[OK]${NC}"

clean:
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

.PHONY: all re fclean clean


# ! DEBUG
libft:
	git clone git@github.com:jkutkut/42Madrid-libft libft
