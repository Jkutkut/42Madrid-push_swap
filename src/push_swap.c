/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 07:57:00 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:14:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pswap	pswap;

	if (argc == 1)
		return (1);
	ft_init_pushswap(&pswap, argc, argv);
	ft_sort(&pswap);
	ft_free_end(&pswap, 0, NULL);
	return (0);
}
