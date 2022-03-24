/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:31:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/24 08:26:53 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	check_leaks(void)
{
	// system("leaks -q ft_pushswap");
}

void	test_move(t_dstack *pswap, int move)
{
	ft_putstr_fd("--------------\n", 1);
	apply(pswap, move);
	print(pswap);
	ft_putstr_fd("--------------\n", 1);
}

int	main(int argc, char **argv)
{
	t_dstack	*pswap;

	atexit(check_leaks);
	if (argc == 1)
		return (1);
	pswap = init_pushswap(argc, argv);
	if (GRAPHIC)
		print(pswap);
	test_move(pswap, SA);
	test_move(pswap, PB);
	test_move(pswap, PB);
	test_move(pswap, PA);
	test_move(pswap, PB);
	test_move(pswap, SB);
	test_move(pswap, SS);
	// test_move(pswap, RA);
	// test_move(pswap, RB);
	// test_move(pswap, RR);
	// test_move(pswap, RRA);
	// test_move(pswap, RRB);
	// test_move(pswap, RRR);
	free_end(pswap, 0, NULL);
	return (0);
}
