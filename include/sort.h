/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 11:28:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
#define SORT_H

#include "push_swap.h"

#define ASC_ORDER 1
#define DESC_ORDER -1

int		dist_to_sandwich(int v, t_stack *lst);
int		dist_to(int v, t_stack *stack);
int		index_stack(int v, t_stack *stack);
int		is_sorted(t_dstack *pswap);
void	just_rotate(t_dstack *pswap, int l);
void	radix_sort(t_dstack *pswap);
int		ready_just_rotate(t_dstack *pswap);
void	sort_3(t_dstack *pswap, int l);
void	sort_5(t_dstack *pswap);
void	sort_chunks(t_dstack *pswap);
void	sort(t_dstack *p);
int		stack_is_sorted(t_stack *stack, int type);


// int		list_is_sorted(t_list *lst, int type);

#endif
