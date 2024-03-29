/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:13:28 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define GROUPS_MEDIUM 3
#define GROUPS_BIG 4 // 100
#define GROUPS_HUGE 10 // 500  10
#define GROUPS_HUGE_RETURN 20

/**
 * @brief Sends all elements from A to B by chunks.
 * The smallest will remain in the center, spliting each group to the sides.
 * 
 * @param pswap Structure with the push_swap data
 * @param groups Total amount of groups to form.
 */
static void	ft_to_b(t_pswap *pswap, int groups)
{
	int	size_b;
	int	group;

	group = 0;
	size_b = 0;
	while (pswap->a)
	{
		if (pswap->a->content * groups / pswap->size == group)
		{
			ft_apply(pswap, PB);
			if ((double) pswap->b->content < \
				(0.5 + group) * (pswap->size / groups))
				if (ft_stack_len(pswap->b) > 1)
					ft_apply(pswap, RB);
			group = ++size_b * groups / pswap->size;
		}
		else
			ft_apply(pswap, RA);
	}
}

/**
 * @brief Tries to move from B to A either min or max.
 * If it's not possible, it will setup B to be able to do it next time.
 * 
 * @param pswap Structure with the push_swap data
 * @param min Minimum value of the group to move
 * @param max Maximum value of the group to move
 */
static void	ft_smart_move(t_pswap *pswap, int *min, int *max)
{
	int	d;

	if (pswap->b->content == *max)
	{
		ft_apply(pswap, PA);
		(*max)--;
	}
	else if (pswap->b->content == *min)
	{
		ft_apply(pswap, PA);
		if (ft_stack_len(pswap->a) >= 2)
			ft_apply(pswap, RA);
		(*min)++;
	}
	else if (ft_stack_last(pswap->b)->content == *min)
		ft_apply(pswap, RRB);
	else
	{
		d = ft_shortest_dist_to_values(*max, *min, pswap->b);
		while (d > 0)
			ft_apply(pswap, RB + 0 * d--);
		while (d < 0)
			ft_apply(pswap, RRB + 0 * d++);
	}
}

/**
 * @brief Move the elements in range [min, max] from B to A.
 * 
 * @param pswap Structure with the push_swap data
 * @param min Minimum value to move
 * @param max Maximum value to move
 */
static void	ft_move_subgroup(t_pswap *pswap, int min, int max)
{
	while (min <= max)
		ft_smart_move(pswap, &min, &max);
	min = ft_get_from_stack(ft_min, pswap->a);
	while (pswap->a->content > min)
		ft_apply(pswap, RRA);
}

/**
 * @brief Moves the elements back to A, group by group.
 * 
 * @param pswap Structure with the push_swap data
 * @param groups Total amount of groups to form.
 */
static void	ft_back_to_a(t_pswap *pswap, int groups)
{
	int	group;
	int	min;
	int	max;

	group = groups;
	while (group-- > 0)
	{
		max = (group + 1) * (pswap->size / groups) - 1;
		min = group * (pswap->size / groups);
		max = ft_max(ft_get_from_stack(ft_max, pswap->b), max);
		ft_move_subgroup(pswap, min, max);
	}
}

/**
 * @brief Sort algorithm based on chunks/groups. Based on the stack size, it
 * will generate more or less groups. 
 * 
 * Algorithm:
 * It will start by moving the elements to B.
 *   The smallest number will be in the center.
 * Then, all the numbers are placed in order back in A.
 * To boost performance, the algorithm will move both the biggest and the
 * smallest in the current group; making both ends at the same time.
 * This way, the elements are only moved once to B, and then back to A.
 * 
 * @param pswap
 */
void	ft_sort_chunks(t_pswap *pswap)
{
	int	groups;

	groups = GROUPS_HUGE;
	if (pswap->size < 80)
		groups = GROUPS_MEDIUM;
	else if (pswap->size < 300)
		groups = GROUPS_BIG;
	ft_to_b(pswap, groups);
	if (groups == GROUPS_HUGE)
		ft_back_to_a(pswap, GROUPS_HUGE_RETURN);
	else
		ft_back_to_a(pswap, groups);
}
