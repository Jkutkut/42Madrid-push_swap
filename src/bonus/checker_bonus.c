/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:03:27 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/21 12:02:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	moves_remaining(char **s)
{
	*s = get_next_line(0);
	if (*s == NULL)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_pswap	pswap;
	// char		*line;
	// char		*result;

	ft_init_pushswap(&pswap, argc, argv);
	ft_printf("init\n");
	return (0);
}
