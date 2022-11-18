/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:58:56 by jkutkut           #+#    #+#             */
/*   Updated: 2022/11/17 16:38:43 by jre-gonz         ###   ########.fr       */
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

// ********* input *********

void	check_input(t_dstack *pswap);
void	init_pushswap(t_dstack	*pswap, int argc, char **argv);
void	normalize(t_dstack *pswap);
void	parse_input(char *arg, t_dstack *pswap);

// ********* operations *********

void	apply(t_dstack *pswap, t_op o);

// Push
char	*pa(t_dstack *pswap);
char	*pb(t_dstack *pswap);

// Reverse Rotate
char	*rra(t_dstack *pswap);
char	*rrb(t_dstack *pswap);
char	*rrr(t_dstack *pswap);

// Rotate
char	*ra(t_dstack *pswap);
char	*rb(t_dstack *pswap);
char	*rr(t_dstack *pswap);

// Swap
char	*sa(t_dstack *pswap);
char	*sb(t_dstack *pswap);
char	*ss(t_dstack *pswap);

// ********* push_swap_utils *********

int		binary_search(int arr[], int l, int r, int value);
void	end(int endtype, char *msg);
void	free_end(t_dstack *pswap, int endtype, char *msg);
int		get_from_stack(int (*f)(int, int), t_stack *stack);

// lambdas
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int nbr);

void	merge_sort(t_dstack *pswap);
int		shortest_dist_to_values(int v1, int v2, t_stack *s);
int		*stack_to_array(t_stack *stack, int size);

// ********* sort *********

int		dist_to_sandwich(int v, t_stack *lst);
int		dist_to(int v, t_stack *stack);
int		index_stack(int v, t_stack *stack);
int		is_sorted(t_dstack *pswap);
void	just_rotate(t_dstack *pswap, t_tstack l);
void	radix_sort(t_dstack *pswap);
int		ready_just_rotate(t_dstack *pswap);
void	sort_3(t_dstack *pswap, t_tstack l);
void	sort_5(t_dstack *pswap);
void	sort_chunks(t_dstack *pswap);
void	sort(t_dstack *p);
int		stack_is_sorted(t_stack *stack, t_sort_type type);

// ********* t_stack *********

void	ft_stack_addb(t_stack **stack, t_stack *new);
void	ft_stack_addf(t_stack **stack, t_stack *new);
void	ft_stack_clear(t_stack **stack);
void	ft_stack_del(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);
int		ft_stack_len(t_stack *stack);
t_stack	*ft_stack_new(int value);

#endif
