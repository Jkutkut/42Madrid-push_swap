/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:54:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/24 09:41:01 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
#define PUSH_SWAP_UTILS_H

#include "push_swap.h"

int		binary_search(int arr[], int l, int r, int value);
void	free_end(t_dstack *pswap, int endtype, char *msg);
int		get_from_lst(int (*f)(int, int), t_list *lst);
int		*linkedlist_to_array(t_list *lst, int size);
void	merge_sort(int *array, int size);
void	print(t_dstack *pswap, int fd);

// miscellaneous
int	ft_max(int a, int b);
int	ft_min(int a, int b);

#endif