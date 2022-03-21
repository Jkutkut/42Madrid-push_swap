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
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
COMPILE		=	$(CC) $(FLAGS)

# Code variables
NAME		=	ft_pushswap

LIBFT		=	src/libft/libft.a
LIBFT_DIR	=	$(dir $(LIBFT))

SRCS		=	src/ft_pushswap.c \
				src/t_list/ft_lstnew.c \
				src/t_list/ft_lstadd_front.c \
				src/t_list/ft_lstsize.c \
				src/t_list/ft_lstlast.c \
				src/t_list/ft_lstadd_back.c \
				src/t_list/ft_lstdelone.c \
				src/t_list/ft_lstclear.c \
				src/t_list/ft_lstiter.c \
				src/t_list/ft_lstmap.c


OBJS		=	${SRCS:src/%.c=bin/%.o}


# Makefile logic
all: $(NAME)
re: fclean all

$(NAME):	$(LIBFT) $(OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(NAME)${NC} \c"
	@$(COMPILE) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "${LGREEN}[OK]${NC}"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@ -D DEBUG
	@echo " ${GREEN}[OK]${NC}"

$(LIBFT):
	make -C $(LIBFT_DIR) BIN="../../bin/libft"


clean:
	@echo "${LRED}Cleaning ${NC}libft"
	@make -C $(LIBFT_DIR) fclean BIN="../../bin/libft"
	@echo "${LRED}Cleaning ${NC}binaries"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME)"
	@rm -f $(NAME)
	@echo "${LGREEN}[OK]${NC}"

.PHONY: all re fclean clean libft
