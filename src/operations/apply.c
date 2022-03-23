/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:35:56 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/23 13:44:34 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	error_apply(t_dstack *pswap, int o)
{
	char	msg[42];

	ft_strlcpy(msg, "Error: Not able to execute the move    .\n", 42);
	ft_strlcpy(msg + 36, &" sa sb ss pa pb ra rb rrrrarrbrrr"[o * 3], 3);
	free_end(pswap, 1, msg);
}


void	apply(t_dstack *pswap, int o)
{
	char	*done;

	done = NULL;
	if (o == SA)
		done = NULL;
		// done = sa(pswap);
	else if (o == SB)
		done = NULL;
	// 	done = sb(pswap);
	else if (o == SS)
		done = NULL;
	// 	done = ss(pswap);
	else if (o == PA)
		done = NULL;
	// 	done = pa(pswap);
	else if (o == PB)
		done = NULL;
	// 	done = pb(pswap);
	else if (o == RA)
		done = NULL;
	// 	done = ra(pswap);
	else if (o == RB)
		done = NULL;
	// 	done = rb(pswap);
	else if (o == RR)
		done = NULL;
	// 	done = rr(pswap);
	else if (o == RRA)
		done = NULL;
	// 	done = rra(pswap);
	else if (o == RRB)
		done = NULL;
	// 	done = rrb(pswap);
	else if (o == RRR)
		done = NULL;
	// 	done = rrr(pswap);
	if (done == NULL)
		error_apply(pswap, o);
	ft_putstr_fd(done, 1);
	ft_putchar_fd('\n', 1);
}
