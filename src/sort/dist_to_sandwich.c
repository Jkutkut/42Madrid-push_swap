/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_sandwich.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:52:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 09:41:04 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Returns the distance from the sandwich of the given value.
 * 
 * A sandwich is a position where a value v is between the values
 * v1 and v2 where:
 * - The stack is sorted in ascending order, even if it is split in 2.
 *   - Split example: 8 10 0 2 4 6
 *   - No split example: 0 2 4 6 8 10
 * - v2 is the next value relative to v1.
 * - v1 >= v > v2
 *
 * Keep in mind that the distance is from the top of the stack going down.
 *
 * Example:
 * - Stack: 8 10 0 2 4 6
 * - v = 3
 * dist_to_sandwich(v) = 4
 *
 * @param v Value to use.
 * @param stack Stack to search in.
 * @return int Distance from the sandwich.
 */
int	dist_to_sandwich(int v, t_stack *stack)
{
	int		dist;
	t_stack	*tmp;
	t_stack	*prev;

	if (stack->content > v && ft_stack_last(stack)->content < v)
		return (0);
	dist = 0;
	tmp = stack;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		dist++;
		if (tmp && tmp->content >= v && prev->content < v)
			return (dist);
	}
	return (-1);
}
