/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 07:57:00 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/28 11:46:45 by jre-gonz         ###   ########.fr       */
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
	// print(&pswap, 1);
	sort(&pswap);
	// print(&pswap, 1);
	// free_end(pswap, 0, NULL);
	// if (!is_sorted(&pswap))
	// 	printf("No ordenado\n");
	// else
	// 	printf("Ordenado\n");
	return (0);
}