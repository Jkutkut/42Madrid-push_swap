/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:08:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/02 17:26:20 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_5(t_dstack *pswap)
{
	int	i;

	i = pswap->size - 3;
	while (--i >= 0)
		apply(pswap, PB);
	sort_3(pswap, 0);
	sort_3(pswap, 1);
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