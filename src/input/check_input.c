/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:09:26 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/12 19:58:14 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(t_dstack *pswap)
{
	int	i;

	pswap->size = ft_stack_len(pswap->a);
	if (pswap->size == 0)
		free_end(pswap, 0, "");
	pswap->arg = stack_to_array(pswap->a, pswap->size);
	merge_sort(pswap->arg, pswap->size);
	i = 0;
	while (++i < pswap->size)
		if (pswap->arg[i] == pswap->arg[i - 1])
			free_end(pswap, 1, ERROR_REPEAT_NBR);
}
