/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:33:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 08:08:55 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initializes the push_swap operations array.
 * 
 * @param pswap
 */
static void load_operations(t_dstack *pswap)
{
	if (!pswap)
		return ;
	pswap->operations[0] = &sa;
	pswap->operations[1] = &sb;
	pswap->operations[2] = &ss;
	pswap->operations[3] = &pa;
	pswap->operations[4] = &pb;
	pswap->operations[5] = &ra;
	pswap->operations[6] = &rb;
	pswap->operations[7] = &rr;
	pswap->operations[8] = &rra;
	pswap->operations[9] = &rrb;
	pswap->operations[10] = &rrr; // TODO enum
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
