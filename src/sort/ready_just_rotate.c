/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_just_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:55:10 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:11:40 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Does the first 2 steps of ready_just_rotate.
 * 
 * @param pswap Structure with the push_swap data.
 * @return int -1 if the stack is not ready, else number of elements ready.
 */
static int	ft_form_0_to_end(t_pswap *pswap)
{
	int		i;
	t_stack	*stack;

	stack = pswap->a;
	while (stack && stack->content != 0)
		stack = stack->next;
	i = 0;
	while (stack)
	{
		if (stack->content != i++)
			return (-1);
		stack = stack->next;
	}
	return (i);
}

/**
 * @brief Check if the push_swap can be solved just by rotating the stack a.
 * Steps:
 * - Find the 0 (going through the stack).
 * - Go through the stack while the elements are in order.
 * - Once on the end, check if the first elements where in order respect to
 * the last.
 * 
 * @param pswap push_swap structure.
 * @return int 1 if possible, 0 otherwise.
 */
int	ft_ready_just_rotate(t_pswap *pswap)
{
	t_stack	*stack;
	int		i;

	if (pswap->b)
		return (0);
	if (ft_is_sorted(pswap))
		return (1);
	i = ft_form_0_to_end(pswap);
	if (i == -1)
		return (0);
	stack = pswap->a;
	while (i < pswap->size)
	{
		if (stack->content != i++)
			return (0);
		stack = stack->next;
	}
	return (1);
}
