/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:09:26 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/21 16:28:32 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Checks if the given push_swap structure is valid.
 * A stack is not valid if there are repeated numbers.
 * 
 * @param pswap
 */
void	ft_check_input(t_pswap *pswap)
{
	int	i;

	pswap->size = ft_stack_len(pswap->a);
	if (pswap->size == 0)
		ft_free_end(pswap, 0, ""); // TODO Might be OK or error
	pswap->arg = ft_stack_to_array(pswap->a, pswap->size);
	ft_merge_sort(pswap);
	i = 0;
	while (++i < pswap->size)
		if (pswap->arg[i] == pswap->arg[i - 1])
			ft_free_end(pswap, 1, ERROR_REPEAT_NBR);
}
