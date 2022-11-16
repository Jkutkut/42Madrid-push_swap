/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:35:56 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/16 19:58:37 by jre-gonz         ###   ########.fr       */
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
 * 
 * @param pswap The push_swap struct.
 * @param o The operation to be applied.
 */
void	apply(t_dstack *pswap, int o)
{
	char	*done;

	if (o == SA)
		done = sa(pswap);
	else if (o == SB)
		done = sb(pswap);
	else if (o == SS)
		done = ss(pswap);
	else if (o == PA)
		done = pa(pswap);
	else if (o == PB)
		done = pb(pswap);
	else if (o == RA)
		done = ra(pswap);
	else if (o == RB)
		done = rb(pswap);
	else if (o == RR)
		done = rr(pswap);
	else if (o == RRA)
		done = rra(pswap);
	else if (o == RRB)
		done = rrb(pswap);
	else if (o == RRR)
		done = rrr(pswap);
	if (done == NULL)
		error_apply(pswap, o);
	ft_putendl_fd(done, 1);
}
