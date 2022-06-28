/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:57:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/28 12:55:10 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	biggest_signi_int(int size)
{
	return (sizeof(int) * 8);
}

void	radix_sort(t_dstack *p)
{
	int	bit;

	bit = 0;
	//while (bit < biggest_signi_int(p->size))
	while(!is_sorted(p) && bit < 16)
	{
		int ops = 0;
		// pasar todos los que tocan a b
		while (ops < p->size)
		{
			if (((p->a->content >> bit) & 1) == 0)
				apply(p, PB);
			else
			{
				if (ft_lstsize(p->a) == 2 && !list_is_sorted(p->a))
				{
					apply(p, SA);
				}
				else if (ft_lstsize(p->a) > 2 && p->a->next)
					apply(p, RA);
				else
					break;
			}
			ops++;
		}
		// pasar de vuelta todos a a
		while (p->b)
			apply(p, PA);
		bit++;
	}
}