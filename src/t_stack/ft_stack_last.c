/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:02:24 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 16:35:43 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Returns the last element of a stack.
 *
 * @param stack
 * @return t_stack* Pointer to the last element.
 */
t_stack	*ft_stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next != NULL)
		return (ft_stack_last(stack->next));
	return (stack);
}
