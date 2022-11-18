/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:49:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:04:13 by jre-gonz         ###   ########.fr       */
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
void	ft_free_end(t_pswap *pswap, int endtype, char *msg)
{
	if (pswap->a)
		ft_stack_clear(&pswap->a);
	if (pswap->b)
		ft_stack_clear(&pswap->b);
	if (pswap->arg != NULL)
		free(pswap->arg);
	ft_end(endtype, msg);
}
