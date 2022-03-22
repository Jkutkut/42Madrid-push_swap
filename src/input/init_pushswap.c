/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:33:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/22 10:18:58 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	check_input(t_dstack *pswap, int argc, char **argv)
{
	// check_huge_numbers(pswap, argc, argv);
	// check_unique(pswap);
}

t_dstack	*init_pushswap(int argc, char **argv)
{
	t_dstack	*pswap;
	int			i;

	pswap = malloc(sizeof(t_dstack));
	if (pswap == NULL)
		return (NULL);
	pswap->b = NULL;
	pswap->a = NULL;
	i = 1;
	while (i < argc)
		parse_input(argv[i++], pswap);
	check_input(pswap, argc, argv);
	return (pswap);
}
