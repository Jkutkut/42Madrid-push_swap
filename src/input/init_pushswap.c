/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:33:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/19 18:21:43 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/**
 * @brief 	Initializes the pushswap structure.
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
	i = 1;
	while (i < argc)
		parse_input(argv[i++], pswap);
	check_input(pswap);
	normalize(pswap);
}
