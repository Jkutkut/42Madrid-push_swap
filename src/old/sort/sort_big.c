/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:35:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/05 13:35:28 by jre-gonz         ###   ########.fr       */
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
		if (pswap->a->content * GROUPS / pswap->size == group)
		{
			apply(pswap, PB);
			if ((double) pswap->b->content < (0.5 + group) * (pswap->size / GROUPS))
				if (ft_lstsize(pswap->b) > 1)
					apply(pswap, RB);
			group = ++size_b * GROUPS / pswap->size;
		}
		else
			apply(pswap, RA);
	}
}

static void	move_subgroup(t_dstack *pswap, int group)
{
	int min;
	int max;
	int dir;

	// max = (group + 1) * (pswap->size / GROUPS) - 1;
	min = group * (pswap->size / GROUPS);
	// max = ft_max(get_from_lst(ft_max, pswap->b), max);
	max = get_from_lst(ft_max, pswap->b);
	printf("min: %d, max: %d\n  (should be %d)\n", min, max, (group + 1) * (pswap->size / GROUPS) - 1);
	// dir = 0;
	// while (min < max)
	// {
	// 	if (pswap->b->content == max)
	// 	{
	// 		apply(pswap, PA);
	// 		max--;
	// 	}
	// 	else
	// 		apply(pswap, RB + dir * 3);
	// 	if (pswap->b->content < min)
	// 	{
	// 		dir = (dir + 1) % 2;
	// 		if (pswap->b->next->content < min)
	// 			dir = 1;
	// 		apply(pswap, RB + dir * 3);
	// 	}
	// }
	// apply(pswap, PA);
}

static void	back_to_a(t_dstack *pswap)
{
	int	group;

	group = GROUPS;
	while (group-- > 0)
	{
		move_subgroup(pswap, group);
	}
}

void	sort_big(t_dstack *pswap)
{
	to_b(pswap);
	back_to_a(pswap);
}