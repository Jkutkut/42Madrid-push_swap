/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:08:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/02 17:09:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_3(t_dstack *pswap, int l)
{
	t_list	*lst;

	lst = pswap->a;
	if (l == 1)
		lst = pswap->b;
	if (ft_lstsize(lst) < 3)
	{
		if (ft_lstsize(lst) == 2 && lst->content > lst->next->content)
			apply(pswap, SA + l);
		return ;
	}
	if (lst->content == 0 && lst->next->content == 2)
	{
		apply(pswap, RRA + l);
		apply(pswap, SA + l);
	}
	else if (lst->content == 1 && lst->next->content == 0)
		apply(pswap, SA + l);
	else if (lst->content == 1 && lst->next->content == 2)
		apply(pswap, RRA + l);
	else if (lst->content == 2 && lst->next->content == 0)
		apply(pswap, RA + l);
	else if (lst->content == 2 && lst->next->content == 1)
	{
		apply(pswap, SA + l);
		apply(pswap, RRA + l);
	}
}

void	sort_small(t_dstack *pswap)
{
	if (pswap->size > 5)
		free_end(pswap, 0, "Not enough elements to sort.\n");
	if (pswap->size <= 3)
		sort_3(pswap, 0);
}