/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/16 18:14:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts the push_swap stack.
 * 
 * @param pswap The push_swap stack.
 */
void	sort(t_dstack *pswap)
{
	if (pswap->size <= 5)
		sort_5(pswap);
	else
		sort_chunks(pswap);
}
