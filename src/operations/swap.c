/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:39:14 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/24 08:08:00 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

char	*sa(t_dstack *pswap)
{
	if (!swap_list(&pswap->a))
		return (NULL);
	return ("SA");
}

char	*sb(t_dstack *pswap)
{
	if (!swap_list(&pswap->b))
		return (NULL);
	return ("SB");
}

char	*ss(t_dstack *pswap)
{
	if (!sa(pswap) || !sb(pswap))
		return (NULL);
	return ("SS");
}