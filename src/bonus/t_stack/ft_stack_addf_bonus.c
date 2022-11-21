/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_addf_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:00:55 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/21 12:05:46 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Adds a new element at the beginning of a stack.
 * 
 * @param stack
 * @param new New element to add.
 */
void	ft_stack_addf(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}
