/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:14:14 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/09 20:01:53 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dist_to(int v, t_list *lst)
{
	int	m;

	m = get_from_lst(ft_min, lst);
	if (v <= m)
		return (index_lst(m, lst));
	m = get_from_lst(ft_max, lst);
	if (v > m)
		return (index_lst(m, lst) + 1);
	return (dist_to_sandwich(v, lst));
}
