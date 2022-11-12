/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:03:54 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/12 18:57:51 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"

/**
 * @brief Iterates the full stack, running f on each element.
 * 
 * @param stack
 * @param f Function to run on each element.
 */
void	ft_stack_iter(t_stack *stack, int (*f)(int))
{
	if (stack == NULL)
		return ;
	stack->content = f(stack->content);
	if (stack->next != NULL)
		ft_stack_iter(stack->next, f);
}
