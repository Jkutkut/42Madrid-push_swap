/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:03:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 09:12:19 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Obtain the value required from the stack.
 * This function generalizes the obtainment of the greatest, lowest...
 * 
 * @param f Function to apply to the stack to get the wanted value.
 * @param stack Stack to apply the function.
 * @return int The value required.
 */
int	get_from_stack(int (*f)(int, int), t_stack *stack)
{
	int		val;
	t_stack	*tmp;

	val = stack->content;
	tmp = stack;
	while (tmp)
	{
		val = f(val, tmp->content);
		tmp = tmp->next;
	}
	return (val);
}
