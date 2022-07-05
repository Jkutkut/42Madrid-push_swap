/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/07/05 15:53:20 by jre-gonz         ###   ########.fr       */
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

static void	move_subgroup(t_dstack *pswap, int min, int max)
{
	int	dir;

	dir = 0;
	while (min < max)
	{
		if (pswap->b->content == max)
			apply(pswap, PA + 0 * max--);
		else if (pswap->b->content == min)
		{
			apply(pswap, PA);
			if (ft_lstsize(pswap->a) >= 2)
				apply(pswap, RA);
			min++;
		}
		else if (ft_lstlast(pswap->b)->content == min)
		{
			apply(pswap, RRB);
		}
		else if (pswap->b->content < min)
		{
			dir = (dir + 1) % 2;
			if (pswap->b->next->content < min)
				dir = 1;
			apply(pswap, RB + dir * 3);
		}
		else
		{
			apply(pswap, RB + dir * 3);
		}
	}
	if (pswap->b->content != min)
		apply(pswap, RRB);
	apply(pswap, PA);

	min = get_from_lst(ft_min, pswap->a);
	while (pswap->a->content > min)
		apply(pswap, RRA);
}

static void	back_to_a(t_dstack *pswap)
{
	int	group;
	int	min;
	int	max;

	group = GROUPS;
	while (group-- > 0)
	{
		max = (group + 1) * (pswap->size / GROUPS) - 1;
		min = group * (pswap->size / GROUPS);
		max = ft_max(get_from_lst(ft_max, pswap->b), max);
		move_subgroup(pswap, min, max);
	}
}

void	sort_chunks(t_dstack *pswap)
{
	to_b(pswap);
	back_to_a(pswap);
}


void	sort(t_dstack *pswap)
{
	if (pswap->size <= 5)
		sort_5(pswap);
	else
		sort_chunks(pswap);
		// radix_sort(pswap);
}
