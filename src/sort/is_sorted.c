/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:21:26 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/24 09:26:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

/**
 * @brief Verifies if the current state of push_swap is final solution.
 * 
 * @param pswap Struct with the stacks.
 * 
 * @return int 1 if sorted, 0 otherwise.
 */
int	is_sorted(t_dstack *pswap)
{
	int		i;
	t_list	*current;

	if (!pswap || !pswap->a)
		return (0);
	if (pswap->b)
		return (0);
	current = pswap->a;
	i = 0;
	while (i < pswap->size)
	{
		if (current->content != i++)
			return (0);
		current = current->next;
	}
	if (current != NULL)
		return (0);
	return (1);
}
