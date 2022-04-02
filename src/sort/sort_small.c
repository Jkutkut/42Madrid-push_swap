/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:08:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/02 20:51:49 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	dist_to(int v, t_list *lst)
{
	int		dist;
	t_list	*tmp;

	dist = 0;
	tmp = lst;
	while (tmp && tmp->content < v)
	{
		dist++;
		tmp = tmp->next;
	}
	if (lst->content /**/&& tmp && tmp->content == v)
		return (dist);
	
	return (dist);
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
			i = pswap->size - i;
			while (i--)
				apply(pswap, RRA);
			apply(pswap, PA);
		}
	}
	// i = dist_to(0, pswap->a, 1);
	// if (i < pswap->size / 2)
	// 	while (i--)
	// 		apply(pswap, RA);
	// else
	// {
	// 	i = pswap->size - i;
	// 	while (i--)
	// 		apply(pswap, RRA);
	// }
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