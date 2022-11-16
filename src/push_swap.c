/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 07:57:00 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/16 16:29:01 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leaks(void)
{
	// system("leaks -q ft_pushswap");
}

int	main(int argc, char **argv)
{
	t_dstack	pswap;

	atexit(check_leaks);
	if (argc == 1)
		return (1);
	init_pushswap(&pswap, argc, argv);
	sort(&pswap);
	free_end(&pswap, 0, NULL);
	return (0);
}
