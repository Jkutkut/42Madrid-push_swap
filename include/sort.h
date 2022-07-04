/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/07/04 09:16:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
#define SORT_H

#include "push_swap.h"

#define ASC_ORDER 1
#define DESC_ORDER -1

int		is_sorted(t_dstack *pswap);
int		list_is_sorted(t_list *lst, int type);
void	radix_sort(t_dstack *pswap);
void	sort_3(t_dstack *pswap, int l);
void	sort(t_dstack *p);

// Sort 5
int		dist_to_sandwich(int v, t_list *lst);
int		dist_to(int v, t_list *lst);
int		index_lst(int v, t_list *lst);
void	just_rotate(t_dstack *pswap, int l);
int		ready_just_rotate(t_dstack *pswap);
void	sort_5(t_dstack *pswap);

#endif
