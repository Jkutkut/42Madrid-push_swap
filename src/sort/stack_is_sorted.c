/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:34:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 12:56:08 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	stack_is_sorted(t_stack *stack, int type)
{
	int	i;

	if (!stack)
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
