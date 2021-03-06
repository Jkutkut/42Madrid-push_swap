# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 22:57:44 by jre-gonz          #+#    #+#              #
#    Updated: 2022/07/05 17:07:00 by jre-gonz         ###   ########.fr        #
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
FLAGS		=	-Wall -Wextra #-fsanitize=address #-Werror
COMPILE		=	$(CC) $(FLAGS) -I include/

# Code variables

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

SORT_5		=	dist_to_sandwich.c \
				dist_to.c \
				index_lst.c \
				just_rotate.c \
				ready_just_rotate.c \
				sort_5.c

SORT		=	is_sorted.c \
				list_is_sorted.c \
				radix_sort.c \
				sort_3.c \
				sort.c \
				$(SORT_5:%=sort5/%)

PUSH_SWAP_UTILS	=	binary_search.c \
					free_end.c \
					get_from_lst.c \
					linkedlist_to_array.c \
					merge_sort.c \
					print.c \
					z_miscellaneous.c


T_LIST		=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

TOOLS		=	end.c \
				ft_abs.c \
				ft_atoi.c \
				ft_hasany.c \
				ft_isdigit.c \
				ft_itoa.c \
				ft_memmove.c \
				ft_ndigits.c \
				ft_putstr_fd.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c


SRCS		=	push_swap.c \
				${INPUT:%=input/%} \
				${OPERATIONS:%=operations/%} \
				${PUSH_SWAP_UTILS:%=push_swap_utils/%} \
				${SORT:%=sort/%} \
				${T_LIST:%=t_list/%} \
				${TOOLS:%=tools/%}
# ft_pushswap.c \
# ${INPUT:%=input/%} \
# ${OPERATIONS:%=operations/%} \
# ${PRINT:%=print/%} \
# ${SORT:%=sort/%} \
# ${T_LIST:%=t_list/%} \
# ${TOOLS:%=tools/%}

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
	make -C $(LIBFT_DIR) BIN="../../bin/libft"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(BONUS_NAME)${NC}\c"
	@$(COMPILE) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

clean:
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME) and $(BONUS_NAME)\c"
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

.PHONY: all re fclean clean libft
