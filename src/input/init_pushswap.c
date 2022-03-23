/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:33:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/23 09:05:23 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_dstack	*init_pushswap(int argc, char **argv)
{
	t_dstack	*pswap;
	int			i;

	pswap = malloc(sizeof(t_dstack));
	if (pswap == NULL)
		end(1, "Error: Malloc failed\n");
	pswap->b = NULL;
	pswap->a = NULL;
	pswap->arg = NULL;
	i = 1;
	while (i < argc)
		parse_input(argv[i++], pswap);
	check_input(pswap);
	normalize(pswap);
	print_array(pswap->arg, pswap->size);
	return (pswap);
}
