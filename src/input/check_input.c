/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:09:26 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/19 18:09:44 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	check_input(t_dstack *pswap)
{
	int	i;

	pswap->size = ft_lstsize(pswap->a);
	pswap->arg = linkedlist_to_array(pswap->a, pswap->size);
	merge_sort(pswap->arg, pswap->size);
	i = 0;
	while (++i < pswap->size)
		if (pswap->arg[i] == pswap->arg[i - 1])
			free_end(pswap, 1, ERROR_REPEAT_NBR);
}
