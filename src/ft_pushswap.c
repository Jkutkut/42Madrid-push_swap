/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:31:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/19 16:23:08 by jkutkut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_dstack	*init_pushswap(int argc, char **argv)
{
	t_dstack	*pswap;
	int			*value;

	*value = 2;
	pswap->b = NULL;
	pswap->a = ft_lstnew(value);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_dstack	*pswap;
	
	pswap = init_pushswap(argc, argv);
	// sort
	// print
	return (0);
}
