/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:49:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/24 08:08:23 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	free_end(t_dstack *pswap, int endtype, char *msg)
{
	if (pswap->a)
		ft_lstclear(&pswap->a);
	if (pswap->b)
		ft_lstclear(&pswap->b);
	if (pswap->arg != NULL)
		free(pswap->arg);
	end(endtype, msg);
}
