/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:05:09 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/21 14:48:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Nomalizes the values of the stack.
 * It transforms a stack of N elements where the min is MIN and the max is MAX
 * into a stack of N elements where the min is 0 and the max is N - 1.
 * This step makes the rest of the algorithm easier to implement.
 * 
 * @param pswap Pushswap structure.
 */
void	ft_normalize(t_pswap *pswap)
{
	t_stack	*a;

	a = pswap->a;
	while (a)
	{
		a->content = ft_binary_search(pswap->arg, 0, pswap->size, a->content);
		a = a->next;
	}
}
