/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/10/30 10:01:30 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

#define GROUPS_MEDIUM 3
#define GROUPS_BIG 4 // 100
#define GROUPS_HUGE 7 // 500

static int	sortest_dist_to(int v, t_list *lst);

// to b

static int	sortest_dist_to_range(t_list *lst, int group, int psize, int groups)
{
	int min;
	int max;
	int	md;
	int	d;

	max = (group + 1) * (psize / groups) - 1;
	min = group * (psize / groups);
	if (lst->content <= min && lst->content >= max)
		return (0);
	md = ft_lstsize(lst);
	while (min < max && md)
	{
		d = sortest_dist_to(min, lst);
		// if (d == 0 && lst->content != min)
		// 	continue;
		if (ft_abs(d) < ft_abs(md))
			md = d;
		min++;
	}
	return md;
}

static void	to_b(t_dstack *pswap, int groups)
{
	int	size_b;
	int	group;
	int	d;

	group = 0;
	size_b = 0;
	while (pswap->a)
	{
		if (pswap->a->content * groups / pswap->size == group)
		{
			apply(pswap, PB);
			if ((double) pswap->b->content < (0.5 + group) * (pswap->size / groups))
				if (ft_lstsize(pswap->b) > 1)
					apply(pswap, RB);
			group = ++size_b * groups / pswap->size;
		}
		else
		{
			// apply(pswap, RA);
			d = sortest_dist_to_range(pswap->a, group, pswap->size, groups);
			if (d < 0)
				apply(pswap, RRA);
			else if (d > 0)
				apply(pswap, RA);

		}
	}
}

// to a

static int	sortest_dist_to(int v, t_list *lst)
{
	int	d;

	d = index_lst(v, lst);
	if (d >= ft_lstsize(lst) / 2)
		d = d - ft_lstsize(lst);
	return d;
}

static int	sortest_dist_to_values(int v1, int v2, t_list *lst)
{
	int	d1;
	int	d2;

	d1 = sortest_dist_to(v1, lst);
	d2 = sortest_dist_to(v2, lst);
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
			if (ft_lstsize(pswap->a) >= 2)
				apply(pswap, RA);
			min++;
		}

		else if (ft_lstlast(pswap->b)->content == min)
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

	min = get_from_lst(ft_min, pswap->a);
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
		max = ft_max(get_from_lst(ft_max, pswap->b), max);
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
	back_to_a(pswap, groups);
}


void	sort(t_dstack *pswap)
{
	if (pswap->size <= 5)
		sort_5(pswap);
	else
		radix_sort(pswap);
		// sort_chunks(pswap);
}
