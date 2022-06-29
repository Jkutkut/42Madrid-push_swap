/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/29 10:47:36 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_5(t_dstack *pswap)
{
	int	s;
	int	count;

	s = pswap->size;
	while (s-- > 3)
		apply(pswap, PB);
	sort_3(pswap, 0);

	int DEBUG = -1;
	while (pswap->b && DEBUG)
	{
		DEBUG--;
		int v = pswap->b->content;
		if (v > ft_lstlast(pswap->a)->content)
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
			count = 0;
			while (pswap->a->content < v + 1)
			{
				count++;
				apply(pswap, RA);
			}
			apply(pswap, PA);
			while (count > 0)
				apply(pswap, RRA - (count-- * 0));
		}
	}

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