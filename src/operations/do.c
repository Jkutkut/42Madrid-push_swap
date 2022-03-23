/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:35:56 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/23 09:58:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	operation(t_dstack *pswap, int o)
{
	if (o == SA)
		sa(pswap);
	else if (o == SB)
		sb(pswap);
	else if (o == SS)
		ss(pswap);
	else if (o == PA)
		pa(pswap);
	else if (o == PB)
		pb(pswap);
	else if (o == RA)
		ra(pswap);
	else if (o == RB)
		rb(pswap);
	else if (o == RR)
		rr(pswap);
	else if (o == RRA)
		rra(pswap);
	else if (o == RRB)
		rrb(pswap);
	else if (o == RRR)
		rrr(pswap);
}
