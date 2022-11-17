/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:34:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 09:35:01 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Verifies if the stack is sorted.
 * 
 * @param stack Stack to verify.
 * @param type Type of sorting logic.
 * @return int 1 if sorted, 0 otherwise.
 */
int	stack_is_sorted(t_stack *stack, int type) // TODO refactor type with enum
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
