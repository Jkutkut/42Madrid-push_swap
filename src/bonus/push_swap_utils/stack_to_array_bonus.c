/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:00:58 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/21 16:19:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Converts the stack to an array of integers.
 * 
 * @param stack
 * @param size
 * @return int*
 */
int	*ft_stack_to_array(t_stack *stack, int size)
{
	int		*array;
	int		i;

	array = (int *) malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i++] = stack->content;
		stack = stack->next;
	}
	return (array);
}
