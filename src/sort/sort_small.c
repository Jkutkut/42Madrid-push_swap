/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:08:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/02 22:27:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

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
		return (ft_lstsize(lst)); // TODO Not tested
	return (dist_to_sandwich(v, lst));
}

void	sort_5(t_dstack *pswap)
{
	int	i;

	i = pswap->size - 3;
	while (--i >= 0)
		apply(pswap, PB);
	sort_3(pswap, 0);
	while (pswap->b)
	{
		i = dist_to(pswap->b->content, pswap->a);
		if (i < pswap->size / 2)
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
	i = dist_to(0, pswap->a);
	if (i < pswap->size / 2)
		while (i--)
			apply(pswap, RA);
	else
	{
		i = pswap->size - i - 1;
		while (i--)
			apply(pswap, RRA);
	}
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