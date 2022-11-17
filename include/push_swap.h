/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:58:56 by jkutkut           #+#    #+#             */
/*   Updated: 2022/11/17 13:41:39 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

# include "elements.h"
# include "msg.h"
# include "operations.h"
# include "sort.h"
# include "t_stack.h"

// input
void	check_input(t_dstack *pswap);
void	init_pushswap(t_dstack	*pswap, int argc, char **argv);
void	normalize(t_dstack *pswap);
void	parse_input(char *arg, t_dstack *pswap);

// push_swap_utils
int		binary_search(int arr[], int l, int r, int value);
void	free_end(t_dstack *pswap, int endtype, char *msg);
int		get_from_stack(int (*f)(int, int), t_stack *stack);
int		*stack_to_array(t_stack *stack, int size);
void	merge_sort(t_dstack *pswap);
void	print(t_dstack *pswap, int fd);

// push_swap_utils/lambdas
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int nbr);

// tools
void	end(int endtype, char *msg);

#endif
