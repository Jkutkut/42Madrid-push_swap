/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:58:56 by jkutkut           #+#    #+#             */
/*   Updated: 2022/11/16 18:38:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP
# define FT_PUSHSWAP

# include <stddef.h>
# include <unistd.h>
#       include <stdio.h> // TODO REMOVE
# include <stdlib.h>

# include "t_stack.h"

typedef struct	s_dstack
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		*arg;
}			t_dstack;


#include "libft.h"
#include "msg.h"
#include "sort.h"
#include "operations.h"

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
int	ft_max(int a, int b);
int	ft_min(int a, int b);
int	ft_abs(int nbr);

// tools
void	end(int endtype, char *msg);

#endif
