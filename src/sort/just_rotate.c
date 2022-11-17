/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:58:24 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 11:38:11 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts the array just by rotating it.
 * 
 * @param pswap Struct with the stacks.
 * @param l // TODO
 */
void	just_rotate(t_dstack *pswap, int l) // TODO refactor
{
	t_stack	*stack;
	int		i;

	stack = pswap->a;
	if (l == 1)
		stack = pswap->b;
	i = dist_to(0, stack);
	if (i <= ft_stack_len(stack) / 2)
		while (i-- > 0)
			apply(pswap, RA + l);
	else
	{
		i = ft_stack_len(stack) - i;
		while (i-- > 0)
			apply(pswap, RRA + l);
	}
}
