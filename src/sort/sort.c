/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/29 12:56:37 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

/* just rotate */
static int	ready_just_rotate(t_dstack *pswap)
{
	t_list	*tmp;
	int		i;

	if (pswap->b)
		return (0);
	if (is_sorted(pswap))
		return (1);
	tmp = pswap->a;
	while (tmp && tmp->content != 0)
		tmp = tmp->next;
	i = 0;
	while (tmp)
	{
		if (tmp->content != i++)
			return (0);
		tmp = tmp->next;
	}
	tmp = pswap->a;
	while (i < pswap->size)
	{
		if (tmp->content != i++)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	dist_to_sandwich(int v, t_list *lst)
{
	int 	dist;
	t_list	*tmp;
	t_list	*prev;

	if (lst->content > v && ft_lstlast(lst)->content < v)
		return (0);
	dist = 0;
	tmp = lst;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		dist++;
		if (tmp && tmp->content >= v && prev->content < v)
			return (dist);
	}
	printf("Error: dist_to_sandwich\n");
	return (0);
}

static int	index_lst(int v, t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->content == v)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static int	dist_to(int v, t_list *lst)
{
	int	m;

	m = get_from_lst(ft_min, lst);
	if (v <= m)
		return (index_lst(m, lst));
	m = get_from_lst(ft_max, lst);
	if (v > m)
		return (index_lst(m, lst) + 1);
	return (dist_to_sandwich(v, lst));
}

static void	just_rotate(t_dstack *pswap, int l)
{
	t_list	*lst;
	int		i;

	lst = pswap->a;
	if (l == 1)
		lst = pswap->b;
	i = dist_to(0, lst);
	if (i <= ft_lstsize(lst) / 2)
		while (i-- > 0)
			apply(pswap, RA + l);
	else
	{
		i = ft_lstsize(lst) - i;
		while (i-- > 0)
			apply(pswap, RRA + l);
	}
}

/* just rotate */


void	sort_5(t_dstack *pswap)
{
	int	s;

	if (ready_just_rotate(pswap))
		return just_rotate(pswap, 0);

	s = pswap->size;
	while (s-- > 3)
	{
		if (pswap->a->content == get_from_lst(ft_max, pswap->a))
			apply(pswap, RA);
		if (pswap->a->content > ft_lstlast(pswap->a)->content && ft_lstlast(pswap->a)->content < 2)
			apply(pswap, RRA);
		apply(pswap, PB);
	}
	sort_3(pswap, 0);
	// TODO Sort B if already in order?

	int DEBUG = -1;
	while (pswap->b && DEBUG)
	{
		DEBUG--;
		int v = pswap->b->content;
		if (list_is_sorted(pswap->a, ASC_ORDER) && v > get_from_lst(ft_max, pswap->a))
		{
			apply(pswap, PA);
			apply(pswap, RA);
			continue;
		}
		int d = dist_to(v, pswap->a);
		// printf("Dist: %d\n", d);
		// if (d < ft_lstsize(pswap->a) / 2)
		if (1)
		{
			// while (pswap->a->content < v + 1)
			while (d > 0)
			{
				d--;
				apply(pswap, RA);
			}
			apply(pswap, PA);
		}
		// print(pswap, 1);
	}
	if (ready_just_rotate(pswap))
		just_rotate(pswap, 0);
	// while (count < 0)
	// 	apply(pswap, RA + count++ * 0);
	// while (count > 0)
	// 	apply(pswap, RRA - count-- * 0);
}

void	sort(t_dstack *pswap)
{
	if (pswap->size <= 5)
		sort_5(pswap);
	else
		radix_sort(pswap);
}