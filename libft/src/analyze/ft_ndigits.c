/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndigits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:25:53 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/10/19 07:57:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Returns the number of digits needed to represent the given number
 * in base 10.
 * 
 * @param n Number to represent.
 * @return size_t Number of digits to represent it.
 */
size_t	ft_ndigits(int n)
{
	size_t	order;

	if (!n)
		return (1);
	order = 0;
	if (n < 0)
		order++;
	while (n != 0)
	{
		order++;
		n /= 10;
	}
	return (order);
}
