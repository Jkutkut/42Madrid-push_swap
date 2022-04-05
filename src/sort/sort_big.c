/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:35:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/05 13:06:33 by jre-gonz         ###   ########.fr       */
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
	int mid;
	int max;
	int dir;

	max = (group + 1) * (pswap->size / GROUPS) - 1;
	min = group * (pswap->size / GROUPS);
	mid = (min + max) / 2;

	max = ft_min(get_from_lst(ft_max, pswap->b), max);
	printf("group %d\n  - min: %d\n  - mid: %d\n  - max: %d\n", group, min, mid, max);
	printf("Current values: %d\n", pswap->b->content);
	fflush(stdout);

	dir = 0;
	// while (min < get_from_lst(ft_max, pswap->b))
	// while (min < max && pswap->b->content >= min && pswap->b->content <= max)
	while (min < max)
	{
		if (pswap->b->content == max)
		{
			apply(pswap, PA);
			max--;
			printf("Now is %d\n", pswap->b->content);
			fflush(stdout);
		}
		else
			apply(pswap, RB + dir * 3);
		if (pswap->b->content < min)
		{
			printf("  min detected\n");
			dir = (dir + 1) % 2;
			if (pswap->b->next->content < mid)
				dir = 1;
			apply(pswap, RB + dir * 3);
			printf("  dir %d -> rotate\n  v %d\n", dir, pswap->b->content);
		}
	}
	apply(pswap, PA);
}

static void	back_to_a(t_dstack *pswap)
{
	int	group;

	group = GROUPS;
	while (group-- > 0)
	{
		move_subgroup(pswap, group);
		ft_putstr_fd("GROUP ENDED\n", 1);
		// break;
	}
}

void	sort_big(t_dstack *pswap)
{
	to_b(pswap);
	printf("Size: %d\n", pswap->size);
	back_to_a(pswap);
}