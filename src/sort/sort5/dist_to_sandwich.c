/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_sandwich.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:52:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 11:06:44 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dist_to_sandwich(int v, t_stack *stack)
{
	int 	dist;
	t_stack	*tmp;
	t_stack	*prev;

	if (stack->content > v && ft_stack_last(stack)->content < v)
		return (0);
	dist = 0;
	tmp = stack;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		dist++;
		if (tmp && tmp->content >= v && prev->content < v)
			return (dist);
	}
	ft_printf("Error: dist_to_sandwich\n");
	return (0);
}
