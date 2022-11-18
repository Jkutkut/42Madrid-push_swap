/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:03:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 16:35:28 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Deletes the given element.
 * 
 * @param Element to delete.
 */
void	ft_stack_del(t_stack *stack)
{
	if (stack != NULL)
		free(stack);
}
