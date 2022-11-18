/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:01:41 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 16:36:59 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Returns the number of elements in a stack.
 *
 * @param stack
 * @return int Number of elements.
 */
int	ft_stack_len(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	if (stack->next == NULL)
		return (1);
	return (1 + ft_stack_len(stack->next));
}
