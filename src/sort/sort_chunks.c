/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 09:45:46 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define GROUPS_MEDIUM 3
#define GROUPS_BIG 4 // 100
#define GROUPS_HUGE 10 // 500  10

static void	to_b(t_dstack *pswap, int groups)
{
	int	size_b;
	int	group;

	group = 0;
	size_b = 0;
	while (pswap->a)
	{
		if (pswap->a->content * groups / pswap->size == group)
		{
			apply(pswap, PB);
			if ((double) pswap->b->content < (0.5 + group) * (pswap->size / groups))
				if (ft_stack_len(pswap->b) > 1)
					apply(pswap, RB);
			group = ++size_b * groups / pswap->size;
		}
		else
			apply(pswap, RA);
	}
}

static int	sortest_dist_to_values(int v1, int v2, t_stack *s)
{
	int	d1;
	int	d2;

	d1 = index_stack(v1, s);
	if (d1 >= ft_stack_len(s) / 2)
		d1 = d1 - ft_stack_len(s);
	d2 = index_stack(v2, s);
	if (d2 >= ft_stack_len(s) / 2)
		d2 = d2 - ft_stack_len(s);
	if (ft_abs(d1) < ft_abs(d2))
		return (d1);
	return d2;
}

static void	move_subgroup(t_dstack *pswap, int min, int max)
{
	int	d;

	while (min <= max)
	{

		if (pswap->b->content == max)
			apply(pswap, PA + 0 * max--);
		else if (pswap->b->content == min)
		{
			apply(pswap, PA);
			if (ft_stack_len(pswap->a) >= 2)
				apply(pswap, RA);
			min++;
		}

		else if (ft_stack_last(pswap->b)->content == min)
			apply(pswap, RRB);
		else
		{
			d = sortest_dist_to_values(max, min, pswap->b);
			while (d > 0)
				apply(pswap, RB + 0 * d--);
			while (d < 0)
				apply(pswap, RRB + 0 * d++);
		}
	}

	min = get_from_stack(ft_min, pswap->a);
	while (pswap->a->content > min)
		apply(pswap, RRA);
}

static void	back_to_a(t_dstack *pswap, int groups)
{
	int	group;
	int	min;
	int	max;

	group = groups;
	while (group-- > 0)
	{
		max = (group + 1) * (pswap->size / groups) - 1;
		min = group * (pswap->size / groups);
		max = ft_max(get_from_stack(ft_max, pswap->b), max);
		move_subgroup(pswap, min, max);
	}
}

void	sort_chunks(t_dstack *pswap)
{
	int	groups;

	groups = GROUPS_HUGE;
	if (pswap->size < 80)
		groups = GROUPS_MEDIUM;
	else if (pswap->size < 300)
		groups = GROUPS_BIG;
	to_b(pswap, groups);

	if (groups == GROUPS_HUGE)
		back_to_a(pswap, 20); // TODO refactor
	else
		back_to_a(pswap, groups);
}
