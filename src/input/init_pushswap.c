/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:33:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 07:55:14 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initializes the push_swap operations array.
 * 
 * @param pswap
 */
static void	load_operations(t_dstack *pswap)
{
	if (!pswap)
		return ;
	pswap->operations[SA] = &sa;
	pswap->operations[SB] = &sb;
	pswap->operations[SS] = &ss;
	pswap->operations[PA] = &pa;
	pswap->operations[PB] = &pb;
	pswap->operations[RA] = &ra;
	pswap->operations[RB] = &rb;
	pswap->operations[RR] = &rr;
	pswap->operations[RRA] = &rra;
	pswap->operations[RRB] = &rrb;
	pswap->operations[RRR] = &rrr;
}

/**
 * @brief Initializes the pushswap structure with the main arguments.
 * Also checks if the given arguments are valid.
 *
 * @param argc
 * @param argv
 */
void	init_pushswap(t_dstack	*pswap, int argc, char **argv)
{
	int	i;

	pswap->b = NULL;
	pswap->a = NULL;
	pswap->arg = NULL;
	load_operations(pswap);
	i = 1;
	while (i < argc)
		parse_input(argv[i++], pswap);
	check_input(pswap);
	normalize(pswap);
}
