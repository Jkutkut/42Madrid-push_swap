/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:31:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/02 17:27:28 by jre-gonz         ###   ########.fr       */
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
	if (GRAPHIC)
		print(pswap, 2);
	sort(pswap);
	if (GRAPHIC)
		print(pswap, 2);
	free_end(pswap, 0, NULL);
	return (0);
}
