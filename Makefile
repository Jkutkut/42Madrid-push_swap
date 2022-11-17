# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 22:57:44 by jre-gonz          #+#    #+#              #
#    Updated: 2022/11/17 09:07:10 by jre-gonz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
FLAGS		=	-Wall -Wextra -Werror #-fsanitize=address #-Werror
COMPILE		=	$(CC) $(FLAGS) -I include/ -I libft/include/

# Code variables
LIBFT_DIR	=	libft
LIBFT		=	${LIBFT_DIR}/libft.a
NAME		=	push_swap

INPUT		=	check_input.c \
				init_pushswap.c \
				normalize.c \
				parse_input.c

OPERATIONS	=	apply.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c

PUSH_SWAP_UTILS	=	binary_search.c \
					end.c \
					free_end.c \
					get_from_stack.c \
					merge_sort.c \
					stack_to_array.c \
					lambdas.c

SORT_5		=	dist_to.c \
				dist_to_sandwich.c \
				index_stack.c \
				just_rotate.c \
				ready_just_rotate.c \
				sort_5.c

SORT		=	is_sorted.c \
				radix_sort.c \
				sort_3.c \
				$(SORT_5:%=sort5/%) \
				sort.c \
				sort_chunks.c \
				stack_is_sorted.c

T_STACK		=	ft_stack_addb.c \
				ft_stack_addf.c \
				ft_stack_clear.c \
				ft_stack_del.c \
				ft_stack_last.c \
				ft_stack_len.c \
				ft_stack_new.c

SRCS		=	${INPUT:%=input/%} \
				${OPERATIONS:%=operations/%} \
				push_swap.c \
				${PUSH_SWAP_UTILS:%=push_swap_utils/%} \
				${SORT:%=sort/%} \
				${T_STACK:%=t_stack/%}

OBJS		=	${SRCS:%.c=bin/%.o}

# Bonus
# BONUS_NAME	=	checker
# BONUS_SRCS	=	bonus/checker.c \
# 				bonus/get_next_line_utils.c \
# 				bonus/get_next_line.c \
# 				${INPUT:%=input/%} \
# 				${OPERATIONS:%=operations/%} \
# 				${PRINT:%=print/%} \
# 				${SORT:%=sort/%} \
# 				${T_LIST:%=t_list/%} \
# 				${TOOLS:%=tools/%}

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
	@echo "${TITLE}Compiling${NC} ${YELLOW}$(LIBFT)${NC}\c"
	@make -C $(LIBFT_DIR) BIN="../bin/libft"
	@echo "${GREEN} [OK]${NC}\n"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(BONUS_NAME)${NC}\c"
	@$(COMPILE) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

clean:
	@echo "${LRED}Cleaning ${NC}libft"
	@make -C $(LIBFT_DIR) fclean BIN="../bin/libft"
	@echo "\n${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME) and $(BONUS_NAME)\c" # TODO
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

.PHONY: all re fclean clean libft
