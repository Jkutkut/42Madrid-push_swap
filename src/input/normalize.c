/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:05:09 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/16 18:30:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Nomalizes the values of the stack.
 * It transforms a stack of N elements where the min is MIN and the max is MAX
 * into a stack of N elements where the min is 0 and the max is N - 1.
 * This step makes the rest of the algorithm easier to implement.
 * 
 * @param pswap Pushswap structure.
 */
void	normalize(t_dstack *pswap)
{
	t_stack	*a;

	a = pswap->a;
	while (a)
	{
		a->content = binary_search(pswap->arg, 0, pswap->size, a->content);
		a = a->next;
	}
}
