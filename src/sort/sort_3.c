/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:15:54 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/02 17:16:06 by jre-gonz         ###   ########.fr       */
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