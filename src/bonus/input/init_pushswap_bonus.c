/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pushswap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:33:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/28 23:00:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Initializes the push_swap operations_names array.
 * 
 * @param pswap
 */
static void	ft_load_operation_names(t_pswap *pswap)
{
	if (!pswap)
		return ;
	pswap->operation_names[SA] = "sa";
	pswap->operation_names[SB] = "sb";
	pswap->operation_names[SS] = "ss";
	pswap->operation_names[PA] = "pa";
	pswap->operation_names[PB] = "pb";
	pswap->operation_names[RA] = "ra";
	pswap->operation_names[RB] = "rb";
	pswap->operation_names[RR] = "rr";
	pswap->operation_names[RRA] = "rra";
	pswap->operation_names[RRB] = "rrb";
	pswap->operation_names[RRR] = "rrr";
}

/**
 * @brief Initializes the push_swap operations array.
 * 
 * @param pswap
 */
static void	ft_load_operations(t_pswap *pswap)
{
	if (!pswap)
		return ;
	pswap->operations[SA] = &ft_sa;
	pswap->operations[SB] = &ft_sb;
	pswap->operations[SS] = &ft_ss;
	pswap->operations[PA] = &ft_pa;
	pswap->operations[PB] = &ft_pb;
	pswap->operations[RA] = &ft_ra;
	pswap->operations[RB] = &ft_rb;
	pswap->operations[RR] = &ft_rr;
	pswap->operations[RRA] = &ft_rra;
	pswap->operations[RRB] = &ft_rrb;
	pswap->operations[RRR] = &ft_rrr;
}

/**
 * @brief Initializes the pushswap structure with the main arguments.
 * Also checks if the given arguments are valid.
 *
 * @param argc
 * @param argv
 */
void	ft_init_pushswap(t_pswap	*pswap, int argc, char **argv)
{
	int	i;

	pswap->b = NULL;
	pswap->a = NULL;
	pswap->arg = NULL;
	ft_load_operations(pswap);
	ft_load_operation_names(pswap);
	i = 1;
	while (i < argc)
		ft_parse_input(argv[i++], pswap);
	ft_check_input(pswap);
	ft_normalize(pswap);
}
