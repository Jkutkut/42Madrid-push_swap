/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:21:26 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/25 21:30:27 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	is_sorted(t_dstack *pswap)
{
	int i = 0;
	t_list	*current;

	if (!pswap || !pswap->a)
		return (0);
	if (pswap->b)
		return (0);
	current = pswap->a;
	while (i < pswap->size)
	{
		if (current->content != i++)
			return (0);
		current = current->next;
	}
	if (current != NULL)
		return (0);
	return (1);
}