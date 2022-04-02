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
FLAGS		=	-Wall -Wextra #-fsanitize=address #-Werror
COMPILE		=	$(CC) $(FLAGS)

# DEBUG		= -D DEBUG
DEBUG		=

# Code variables

NAME		=	push_swap

LIBFT		=	src/libft/libft.a
LIBFT_DIR	=	$(dir $(LIBFT))

INPUT		=	check_input.c \
				init_pushswap.c \
				normalize.c \
				parse_input.c

OPERATIONS	=	apply.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c

PRINT		=	print.c

SORT		=	is_sorted.c \
				sort_small.c \
				sort.c

T_LIST		=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

TOOLS		=	binary_search.c \
				end.c \
				free_end.c \
				linkedlist_to_array.c \
				merge_sort.c \
				print_array.c

SRCS		=	ft_pushswap.c \
				${INPUT:%=input/%} \
				${OPERATIONS:%=operations/%} \
				${PRINT:%=print/%} \
				${SORT:%=sort/%} \
				${T_LIST:%=t_list/%} \
				${TOOLS:%=tools/%}

OBJS		=	${SRCS:%.c=bin/%.o}

# Bonus
BONUS_NAME	=	checker
BONUS_SRCS	=	bonus/checker.c \
				bonus/get_next_line_utils.c \
				bonus/get_next_line.c \
				${INPUT:%=input/%} \
				${OPERATIONS:%=operations/%} \
				${PRINT:%=print/%} \
				${SORT:%=sort/%} \
				${T_LIST:%=t_list/%} \
				${TOOLS:%=tools/%}

BONUS_OBJS		=	${BONUS_SRCS:%.c=bin/%.o}


# Makefile logic
all: $(NAME)
re: fclean all

$(NAME):	$(LIBFT) $(OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(NAME)${NC}\c"
	@$(COMPILE) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "${LGREEN} [OK]${NC}"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@ $(DEBUG)
	@echo "${GREEN} [OK]${NC}"

$(LIBFT):
	make -C $(LIBFT_DIR) BIN="../../bin/libft"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(BONUS_NAME)${NC}\c"
	@$(COMPILE) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

clean:
	@echo "${LRED}Cleaning ${NC}libft"
	@make -C $(LIBFT_DIR) fclean BIN="../../bin/libft"
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME) and $(BONUS_NAME)\c"
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

.PHONY: all re fclean clean libft
