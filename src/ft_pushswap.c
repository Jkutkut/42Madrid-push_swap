/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:31:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/21 11:05:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_dstack	*init_pushswap(int argc, char **argv)
{
	t_dstack	*pswap;

	if (argc < 2)
		argv++;
	pswap = malloc(sizeof(t_dstack));
	if (pswap == NULL)
		return (NULL);
	pswap->b = NULL;
	// pswap->b = ft_lstnew(123);
	pswap->a = ft_lstnew(2);

	ft_lstadd_back(&pswap->a, ft_lstnew(234));
	ft_lstadd_back(&pswap->a, ft_lstnew(6));
	return (pswap);
}

int	main(int argc, char **argv)
{
	t_dstack	*pswap;
	
	pswap = init_pushswap(argc, argv);
	if (GRAPHIC)
		print(pswap);
	// sort
	// print
	return (0);
}
