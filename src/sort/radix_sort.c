/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:57:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/28 13:21:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	biggest_signi_int(int size)
{
	int	bit;

	bit = 0;
	while (size > 0)
	{
		if ((size >> bit) & 1)
			size -= 1 << bit;
		bit++;
	}
	return (bit);
}

void	radix_sort(t_dstack *p)
{
	int	bit;
	int	maxBit;

	bit = 0;
	maxBit = biggest_signi_int(p->size);
	while(!is_sorted(p) && bit < maxBit)
	{
		int ops = 0;
		while (ops < p->size && !list_is_sorted(p->a))
		{
			if (((p->a->content >> bit) & 1) == 0)
				apply(p, PB);
			else
			{
				if (p->a->next)
					apply(p, RA);
				else
					break;
			}
			ops++;
		}
		while (p->b)
			apply(p, PA);
		bit++;
	}
}