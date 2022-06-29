/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/29 10:12:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_5(t_dstack *pswap)
{
	int	s;

	s = pswap->size;
	while (s-- > 3)
		apply(pswap, PB);
	sort_3(pswap, 0);

	while (pswap->b)
	{
		int v = pswap->b->content;
		if (v == ft_lstlast(pswap->a)->content + 1)
		{
			apply(pswap, PA);
			apply(pswap, RA);
		}
		else if (v == 0)
		{
			apply(pswap, PA);
		}
		else
		{
			int count = 0;
			while (pswap->a->content < v + 1)
			{
				count++;
				apply(pswap, RA);
			}
			apply(pswap, PA);
			while (count-- > 0)
				apply(pswap, RRA);
		}
	}
}

void	sort(t_dstack *pswap)
{
	if (pswap->size <= 5)
		sort_5(pswap);
	else
		radix_sort(pswap);
}