/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_just_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:55:10 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/09 20:01:43 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ready_just_rotate(t_dstack *pswap)
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
