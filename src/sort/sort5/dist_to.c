/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:14:14 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 11:08:16 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dist_to(int v, t_stack *stack)
{
	int	m;

	m = get_from_stack(ft_min, stack);
	if (v <= m)
		return (index_stack(m, stack));
	m = get_from_stack(ft_max, stack);
	if (v > m)
		return (index_stack(m, stack) + 1);
	return (dist_to_sandwich(v, stack));
}
