/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 11:07:18 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
#define SORT_H

#include "push_swap.h"

#define ASC_ORDER 1
#define DESC_ORDER -1

int		is_sorted(t_dstack *pswap);
// int		list_is_sorted(t_list *lst, int type);
int		stack_is_sorted(t_stack *stack, int type);
void	radix_sort(t_dstack *pswap);
void	sort_3(t_dstack *pswap, int l);
void	sort(t_dstack *p);
void	sort_chunks(t_dstack *pswap);

// Sort 5
int		dist_to_sandwich(int v, t_stack *lst);
int		dist_to(int v, t_stack *stack);
int		index_stack(int v, t_stack *stack);
int		dist_to_sandwich(int v, t_stack *stack);
int		dist_to(int v, t_stack *stack);
int		index_lst(int v, t_stack *stack);
void	just_rotate(t_dstack *pswap, int l);
int		ready_just_rotate(t_dstack *pswap);
void	sort_5(t_dstack *pswap);

#endif
