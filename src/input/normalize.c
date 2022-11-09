/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:05:09 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/09 20:05:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize(t_dstack *pswap)
{
	t_list	*a;
	int		i;

	i = 0;
	a = pswap->a;
	while (i++ < pswap->size)
	{
		a->content = binary_search(pswap->arg, 0, pswap->size, a->content);
		a = a->next;
	}
}
