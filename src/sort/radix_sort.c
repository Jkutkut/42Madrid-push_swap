/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:57:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/28 11:55:32 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	biggest_signi_int(int size)
{
	int bit;

	bit = sizeof(int) - 1;
	while (((size >> bit) & 1) == 0)
		bit--;
	return (bit);
}

void	radix_sort(t_dstack *p)
{
	int	operations;
	int	bit;
	int	maxBit;

	bit = 0;
	maxBit = biggest_signi_int(p->size) + 1;
	while (bit <= maxBit) ///* && !is_sorted(p)*/)
	{
		operations = 0;
		// while (operations++ < p->size && !list_is_sorted(p->a))
		while (operations++ < p->size)
		{
			if (((p->a->content >> bit) & 1) == 0)
				apply(p, PB);
			else
				apply(p, RA);
		}
		while (p->b != NULL)
		{
			apply(p, PA);
		}
		bit++;
	}
}