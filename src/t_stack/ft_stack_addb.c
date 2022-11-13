/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_addb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:02:58 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 11:24:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"

/**
 * @brief Adds a new element at the end of the stack.
 * 
 * @param stack
 * @param new New element.
 */
void	ft_stack_addb(t_stack **stack, t_stack *new)
{
	if (stack == NULL || new == NULL)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
		ft_stack_last(*stack)->next = new;
}
