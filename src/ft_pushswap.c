/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:31:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/22 21:10:39 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	check_leaks(void)
{
	// system("leaks -q ft_pushswap");
}

int	main(int argc, char **argv)
{
	t_dstack	*pswap;

	atexit(check_leaks);
	if (argc == 1)
		return (1);
	pswap = init_pushswap(argc, argv);
	if (pswap == NULL)
	{
		printf("Error\n");
		return (1);
	}
	if (GRAPHIC)
		print(pswap);
	return (0);
}
