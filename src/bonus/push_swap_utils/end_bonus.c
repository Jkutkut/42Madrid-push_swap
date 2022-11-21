/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:43:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/21 16:16:05 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Ends the execution of the program
 * 
 * @param endtype Type of end (0: normal, 1: error)
 * @param msg Message to display 
 */
void	ft_end(int endtype, char *msg)
{
	if (endtype == 1)
		ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(msg, endtype + 1);
	exit(endtype);
}
