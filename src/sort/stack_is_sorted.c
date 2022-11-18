/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:34:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:13:50 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Verifies if the stack is sorted.
 * 
 * @param stack Stack to verify.
 * @param type Type of sorting.
 * @return int 1 if sorted, 0 otherwise.
 */
int	ft_stack_is_sorted(t_stack *stack, t_sort_type type)
{
	int	i;

	if (!stack || (type != ASC_ORDER && type != DESC_ORDER))
		return (1);
	i = stack->content;
	while (stack)
	{
		if (stack->content != i)
			return (0);
		i += type;
		stack = stack->next;
	}
	return (1);
}
