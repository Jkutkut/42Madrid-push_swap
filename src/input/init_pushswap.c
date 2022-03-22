/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:33:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/22 21:10:02 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	check_input(t_dstack *pswap)
{
	pswap->size = ft_lstsize(pswap->a);
	if (pswap->size == 0)
		free_end(pswap, 1, "Error: No numbers to sort.\n");
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
	check_input(pswap);
	return (pswap);
}
