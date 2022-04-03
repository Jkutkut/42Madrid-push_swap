/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:35:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/03 16:22:03 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

#define GROUPS 4

static void	to_b(t_dstack *pswap)
{
	int	size_b;
	int	group;

	group = 0;
	size_b = 0;
	while (pswap->a)
	{
		// printf("val: %d\ncgroup %d\ngroup: %d\n", pswap->a->content, group, pswap->a->content * GROUPS / pswap->size);
		// fflush(stdout);
		if (pswap->a->content * GROUPS / pswap->size == group)
		{
			apply(pswap, PB);
			printf("value %d\ngroupmid %f\n", pswap->b->content, (0.5 + group) * (pswap->size / GROUPS));
			fflush(stdout);
			if ((double) pswap->b->content < (0.5 + group) * (pswap->size / GROUPS))
				apply(pswap, RB);
			group = ++size_b * GROUPS / pswap->size;
		}
		else
			apply(pswap, RA);
	}
}

void	sort_big(t_dstack *pswap)
{
	to_b(pswap);
	// back_to_a(pswap);
}