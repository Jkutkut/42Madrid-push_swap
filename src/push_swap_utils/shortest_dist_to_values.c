/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_dist_to_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:56:14 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:05:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Takes two possible values and determines the distance to the
 * closest one.
 * 
 * @param v1 First value
 * @param v2 Second value
 * @param s Stack to check
 * @return int Distance to the closest value
 */
int	ft_shortest_dist_to_values(int v1, int v2, t_stack *s)
{
	int	d1;
	int	d2;

	d1 = ft_index_stack(v1, s);
	if (d1 >= ft_stack_len(s) / 2)
		d1 = d1 - ft_stack_len(s);
	d2 = ft_index_stack(v2, s);
	if (d2 >= ft_stack_len(s) / 2)
		d2 = d2 - ft_stack_len(s);
	if (ft_abs(d1) < ft_abs(d2))
		return (d1);
	return (d2);
}
