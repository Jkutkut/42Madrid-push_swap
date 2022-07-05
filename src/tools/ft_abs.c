/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:04:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/07/05 17:06:25 by jre-gonz         ###   ########.fr       */
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