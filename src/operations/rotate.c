/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:40:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 12:58:32 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_stack_last(*stack)->next = tmp;
	return (1);
}

char	*ra(t_dstack *pswap)
{
	if (!rotate_stack(&pswap->a))
		return (NULL);
	return ("ra");
}

char	*rb(t_dstack *pswap)
{
	if (!rotate_stack(&pswap->b))
		return (NULL);
	return ("rb");
}

char	*rr(t_dstack *pswap)
{
	if (!rotate_stack(&pswap->a) || !rotate_stack(&pswap->b))
		return (NULL);
	return ("rr");
}
