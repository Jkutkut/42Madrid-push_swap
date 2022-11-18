/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:13:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts the push_swap stack.
 * 
 * @param pswap The push_swap stack.
 */
void	ft_sort(t_pswap *pswap)
{
	if (pswap->size <= 5)
		ft_sort_5(pswap);
	else if (pswap->size <= 500)
		ft_sort_chunks(pswap);
	else
		ft_radix_sort(pswap);
}
