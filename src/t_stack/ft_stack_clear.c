/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:03:47 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/12 19:41:06 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"

void	ft_stack_del(t_stack *stack);

/**
 * @brief Destroys the given stack.
 * 
 * @param stack
 */
void	ft_stack_clear(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	ft_stack_clear(&(*stack)->next);
	ft_stack_del(*stack);
	*stack = NULL;
}
