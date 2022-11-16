/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:49:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/16 16:42:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Frees all the allocated memory and exits the program.
 * 
 * @param pswap Pushswap structure.
 * @param endtype Exit code to return.
 * @param msg Message to print before exiting.
 */
void	free_end(t_dstack *pswap, int endtype, char *msg)
{
	if (pswap->a)
		ft_stack_clear(&pswap->a);
	if (pswap->b)
		ft_stack_clear(&pswap->b);
	if (pswap->arg != NULL)
		free(pswap->arg);
	end(endtype, msg);
}
