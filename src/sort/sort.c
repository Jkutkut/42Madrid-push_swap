/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/27 17:09:08 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_big(t_dstack *pswap)
{
	
}

void	sort(t_dstack *pswap)
{
	if (pswap->size <= 5)
		sort_small(pswap);
	else
		sort_big(pswap);
}