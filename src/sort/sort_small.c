/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:08:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/27 17:09:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_small(t_dstack *pswap)
{
	if (pswap->size > 5)
		free_end(pswap, 0, "Not enough elements to sort.\n");
	
}