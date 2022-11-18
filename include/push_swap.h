/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:58:56 by jkutkut           #+#    #+#             */
/*   Updated: 2022/11/18 09:53:29 by jre-gonz         ###   ########.fr       */
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

void	ft_check_input(t_pswap *pswap);
void	ft_init_pushswap(t_pswap	*pswap, int argc, char **argv);
void	ft_normalize(t_pswap *pswap);
void	ft_parse_input(char *arg, t_pswap *pswap);

// ********* operations *********

void	ft_apply(t_pswap *pswap, t_op o);

// Push
char	*ft_pa(t_pswap *pswap);
char	*ft_pb(t_pswap *pswap);

// Reverse Rotate
char	*ft_rra(t_pswap *pswap);
char	*ft_rrb(t_pswap *pswap);
char	*ft_rrr(t_pswap *pswap);

// Rotate
char	*ft_ra(t_pswap *pswap);
char	*ft_rb(t_pswap *pswap);
char	*ft_rr(t_pswap *pswap);

// Swap
char	*ft_sa(t_pswap *pswap);
char	*ft_sb(t_pswap *pswap);
char	*ft_ss(t_pswap *pswap);

// ********* push_swap_utils *********

int		ft_binary_search(int arr[], int l, int r, int value);
void	ft_end(int endtype, char *msg);
void	ft_free_end(t_pswap *pswap, int endtype, char *msg);
int		ft_get_from_stack(int (*f)(int, int), t_stack *stack);

// lambdas
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int nbr);

void	ft_merge_sort(t_pswap *pswap);
int		ft_shortest_dist_to_values(int v1, int v2, t_stack *s);
int		*ft_stack_to_array(t_stack *stack, int size);

// ********* sort *********

int		ft_dist_to_sandwich(int v, t_stack *lst);
int		ft_dist_to(int v, t_stack *stack);
int		ft_index_stack(int v, t_stack *stack);
int		ft_is_sorted(t_pswap *pswap);
void	ft_just_rotate(t_pswap *pswap, t_tstack l);
void	ft_radix_sort(t_pswap *pswap);
int		ft_ready_just_rotate(t_pswap *pswap);
void	ft_sort_3(t_pswap *pswap, t_tstack l);
void	ft_sort_5(t_pswap *pswap);
void	ft_sort_chunks(t_pswap *pswap);
void	ft_sort(t_pswap *p);
int		ft_stack_is_sorted(t_stack *stack, t_sort_type type);

// ********* t_stack *********

void	ft_stack_addb(t_stack **stack, t_stack *new);
void	ft_stack_addf(t_stack **stack, t_stack *new);
void	ft_stack_clear(t_stack **stack);
void	ft_stack_del(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);
int		ft_stack_len(t_stack *stack);
t_stack	*ft_stack_new(int value);

#endif
