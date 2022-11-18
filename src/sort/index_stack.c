/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:14:57 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:10:00 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get the index of a value in a stack.
 * 
 * @param v Value to search.
 * @param stack Stack to search in.
 * @return int Index of the value. If not found, 0 is returned.
 */
int	ft_index_stack(int v, t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->content == v)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
