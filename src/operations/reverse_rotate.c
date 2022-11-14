/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:40:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 12:57:25 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	current = *stack;
	while (current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	return (1);
}

char	*rra(t_dstack *pswap)
{
	if (!reverse_rotate_stack(&pswap->a))
		return (NULL);
	return ("rra");
}

char	*rrb(t_dstack *pswap)
{
	if (!reverse_rotate_stack(&pswap->b))
		return (NULL);
	return ("rrb");
}

char	*rrr(t_dstack *pswap)
{
	if (!reverse_rotate_stack(&pswap->a) || !reverse_rotate_stack(&pswap->b))
		return (NULL);
	return ("rrr");
}
