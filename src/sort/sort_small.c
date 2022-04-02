/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:08:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/03 00:37:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

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
	printf("Error: index_lst\n");
	return (0);
}

static int	dist_to(int v, t_list *lst)
{
	if (v <= get_from_lst(ft_min, lst))
		return (index_lst(get_from_lst(ft_min, lst), lst));
	if (v > get_from_lst(ft_max, lst))
		return (ft_lstsize(lst) + 1);
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
		while (i--)
			apply(pswap, RA + l);
	else
	{
		i = ft_lstsize(lst) - i;
		while (i--)
			apply(pswap, RRA + l);
	}
}

void	sort_5(t_dstack *pswap)
{
	int	i;

	if (ready_just_rotate(pswap))
		just_rotate(pswap, 0);
	i = pswap->size - 3;
	while (--i >= 0)
		apply(pswap, PB);
	sort_3(pswap, 0);
	while (pswap->b)
	{
		i = dist_to(pswap->b->content, pswap->a);
		if (i <= pswap->size / 2)
		{
			while (i--)
				apply(pswap, RA);
			apply(pswap, PA);
		}
		else
		{
			i = pswap->size - i - 1;
			while (i--)
				apply(pswap, RRA);
			apply(pswap, PA);
		}
	}
	just_rotate(pswap, 0);
}


void	sort_small(t_dstack *pswap)
{
	if (pswap->size > 5)
		free_end(pswap, 0, "Not enough elements to sort.\n");
	if (pswap->size <= 3)
		sort_3(pswap, 0);
	else
		sort_5(pswap);
}