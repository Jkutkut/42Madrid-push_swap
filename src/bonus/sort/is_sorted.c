/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:21:26 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/28 19:37:43 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Verifies if the stack is sorted.
 * 
 * @param stack Stack to verify.
 * @return int 1 if sorted, 0 otherwise.
 */
static int	ft_stack_is_sorted(t_stack *stack)
{
	int	i;

	if (!stack)
		return (1);
	i = stack->content;
	while (stack)
	{
		if (stack->content != i)
			return (0);
		i++;
		stack = stack->next;
	}
	return (1);
}

/**
 * @brief Verifies if the current state of push_swap is final solution.
 * 
 * @param pswap Struct with the stacks.
 * 
 * @return int 1 if sorted, 0 otherwise.
 */
int	ft_is_sorted(t_pswap *pswap)
{
	if (!pswap)
		return (0);
	if (pswap->b)
		return (0);
	return (ft_stack_is_sorted(pswap->a));
}
