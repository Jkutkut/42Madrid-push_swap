/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:57:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/28 09:04:33 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	biggest_signi_int(int size)
{
	int bit;

	bit = sizeof(int);
	while ((size & (1 << bit)) == 0)
		bit--;
	return (bit);
}

void	radix_sort(t_dstack *p)
{
	int	operations;
	int	bit;
	int	maxBit;

	bit = 0;
	maxBit = biggest_signi_int(p->size);
	while (bit <= maxBit && !is_sorted(p))
	{
		operations = 0;
		while (p->a->next && operations++ < p->size)
		{
			if (((p->a->content >> bit) & 1) == 0)
				apply(p, PB);
			else
				apply(p, RA);
		}
		while(p->b != NULL)
			apply(p, PA);
		bit++;
	}
}