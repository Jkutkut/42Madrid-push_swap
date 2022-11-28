# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 22:57:44 by jre-gonz          #+#    #+#              #
#    Updated: 2022/11/28 19:11:51 by jre-gonz         ###   ########.fr        #
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
LIB_CC			=	ar rcT
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror #-fsanitize=address #-Werror
COMPILE			=	$(CC) $(FLAGS) -I include/ -I libft/include/
COMPILE_BONUS	=	$(CC) $(FLAGS) -I include/bonus -I libft/include/

# ************ CODE ************
LIBFT_DIR	=	./libft
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
					lambdas.c \
					merge_sort.c \
					shortest_dist_to_values.c \
					stack_to_array.c

SORT		=	dist_to_sandwich.c \
				dist_to.c \
				index_stack.c \
				is_sorted.c \
				just_rotate.c \
				radix_sort.c \
				ready_just_rotate.c \
				sort_3.c \
				sort_5.c \
				sort_chunks.c \
				sort.c \
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

# ************ BONUS ************

INPUT_BONUS	=	check_input_bonus.c \
				init_pushswap_bonus.c \
				normalize_bonus.c \
				parse_input_bonus.c

OPERATIONS_BONUS=	apply_bonus.c \
				push_bonus.c \
				reverse_rotate_bonus.c \
				rotate_bonus.c \
				swap_bonus.c

PUSH_SWAP_UTILS_BONUS=	binary_search_bonus.c \
					end_bonus.c \
					free_end_bonus.c \
					merge_sort_bonus.c \
					stack_to_array_bonus.c
# 					get_from_stack_bonus.c \
# 					lambdas_bonus.c \
# 					shortest_dist_to_values_bonus.c \

SORT_BONUS	=	is_sorted.c \

T_STACK_BONUS=	ft_stack_addb_bonus.c \
				ft_stack_addf_bonus.c \
				ft_stack_clear_bonus.c \
				ft_stack_del_bonus.c \
				ft_stack_last_bonus.c \
				ft_stack_len_bonus.c \
				ft_stack_new_bonus.c

BONUS_NAME	=	checker
BONUS_SRCS	=	checker_bonus.c \
				${INPUT_BONUS:%=input/%} \
				${OPERATIONS_BONUS:%=operations/%} \
				${PUSH_SWAP_UTILS_BONUS:%=push_swap_utils/%} \
				${SORT_BONUS:%=sort/%} \
				${T_STACK_BONUS:%=t_stack/%}

BONUS_OBJS		=	${BONUS_SRCS:%.c=bin/bonus/%.o}


# Makefile logic
all: $(NAME)
bonus: $(BONUS_NAME)
re: fclean all

$(NAME):	$(LIBFT) $(OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(NAME)${NC}\c"
	@$(COMPILE) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "${LGREEN} [OK]${NC}"

$(BONUS_NAME):	COMPILE = $(COMPILE_BONUS)
$(BONUS_NAME):	$(LIBFT) $(BONUS_OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(BONUS_NAME)${NC}\c"
	@$(COMPILE) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@ $(DEBUG)
	@echo "${GREEN} [OK]${NC}"

$(LIBFT):
	@echo "${TITLE}Compiling${NC} ${YELLOW}$(LIBFT)${NC}"
	@make -C $(LIBFT_DIR) all BIN="../bin/libft"

clean:
	@@echo "${LRED}Cleaning ${NC}libft"
	@make -C $(LIBFT_DIR) fclean BIN="../bin/libft"
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME) and $(BONUS_NAME)\c" # TODO
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

.PHONY: all re fclean clean
