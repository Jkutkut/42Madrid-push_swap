/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/09 20:02:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_dstack *pswap)
{
	if (pswap->size <= 5)
		sort_5(pswap);
	else
		sort_chunks(pswap);
		//radix_sort(pswap);
}
