/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:35:56 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 08:56:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Ends the program when the requiered move can not be done.
 * 
 * @param pswap The push_swap struct.
 * @param o The operation attempted.
 */
static void	error_apply(t_dstack *pswap, int o)
{
	char	msg[ERROR_APPLY_LEN];

	ft_strlcpy(msg, ERROR_APPLY, ERROR_APPLY_LEN);
	ft_memmove(msg + ERROR_APPLY_LEN - 6, &ERROR_APPLY_MOVE[o * 3], 3);
	free_end(pswap, 1, msg);
}

/**
 * @brief Applies the selected operation to the push_swap.
 * If the operation can not be done, the program ends.
 * The operation selection is done by the use of an array to reduce complexity.
 * 
 * @param pswap The push_swap struct.
 * @param o The operation to be applied.
 */
void	apply(t_dstack *pswap, t_op o)
{
	char	*done;

	if (o < 0 || o >= NUMBER_OPERATIONS)
		free_end(pswap, 1, ERROR_APPLY_OP);
	done = pswap->operations[o](pswap);
	if (done == NULL)
		error_apply(pswap, o);
	ft_putendl_fd(done, 1);
}
