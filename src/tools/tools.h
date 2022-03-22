/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:46:31 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/22 22:40:12 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include "../ft_pushswap.h"

void	end(int endtype, char *msg);
void	free_end(t_dstack *pswap, int endtype, char *msg);
int		*linkedlist_to_array(t_list *lst, int size);
void	merge_sort(int *array, int size);
void	print_array(int *array, int size);

#endif