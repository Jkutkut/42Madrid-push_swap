/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:14:14 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:09:53 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Returns the distance to the value v in the sorted stack.
 * If the value is not in the stack, returns the dist_to_sandwich.
 * 
 * @param v Value to find.
 * @param stack Stack to search.
 * @return int Distance to the value v or the dist_to_sandwich.
 */
int	ft_dist_to(int v, t_stack *stack)
{
	int	m;

	m = ft_get_from_stack(ft_min, stack);
	if (v <= m)
		return (ft_index_stack(m, stack));
	m = ft_get_from_stack(ft_max, stack);
	if (v > m)
		return (ft_index_stack(m, stack) + 1);
	return (ft_dist_to_sandwich(v, stack));
}
