/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:58:24 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/09 20:01:32 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	just_rotate(t_dstack *pswap, int l)
{
	t_list	*lst;
	int		i;

	lst = pswap->a;
	if (l == 1)
		lst = pswap->b;
	i = dist_to(0, lst);
	if (i <= ft_lstsize(lst) / 2)
		while (i-- > 0)
			apply(pswap, RA + l);
	else
	{
		i = ft_lstsize(lst) - i;
		while (i-- > 0)
			apply(pswap, RRA + l);
	}
}
