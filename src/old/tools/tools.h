/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:46:31 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/02 21:09:16 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include "../ft_pushswap.h"

int		binary_search(int arr[], int l, int r, int value);
void	end(int endtype, char *msg);
void	free_end(t_dstack *pswap, int endtype, char *msg);
int		get_from_lst(int (*f)(int, int), t_list *lst);
int		*linkedlist_to_array(t_list *lst, int size);
void	merge_sort(int *array, int size);
void	print_array(int *array, int size);

// Miscellaneous lst functions
int	ft_max(int a, int b);
int	ft_min(int a, int b);

#endif