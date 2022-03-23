/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:46:31 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/23 08:42:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include "../ft_pushswap.h"

int		binary_search(int arr[], int l, int r, int value);
void	end(int endtype, char *msg);
void	free_end(t_dstack *pswap, int endtype, char *msg);
int		*linkedlist_to_array(t_list *lst, int size);
void	merge_sort(int *array, int size);
void	print_array(int *array, int size);

#endif