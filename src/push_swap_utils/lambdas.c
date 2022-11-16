/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambdas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 09:30:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/16 18:41:05 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns the absolute value of the given number.
 * 
 * Keep in mind that in the case of MIN_INT, an overflow will happen.
 * 
 * @param nbr Number to use.
 * @return int Absolute value of nbr.
 */
int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

/**
 * @param a
 * @param b
 * @return int The greater value between a and b.
 */
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * @param a
 * @param b
 * @return int The lower value between a and b.
 */
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
