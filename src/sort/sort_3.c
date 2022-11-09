/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:15:54 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/09 20:00:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_dstack *pswap, int l)
{
	t_list	*lst;
	int		max;
	int		min;

	lst = pswap->a;
	if (l == 1)
		lst = pswap->b;
	if (ft_lstsize(lst) < 3)
	{
		if (ft_lstsize(lst) == 2 && lst->content > lst->next->content)
			apply(pswap, SA + l);
		return ;
	}
	max = get_from_lst(ft_max, lst);
	min = get_from_lst(ft_min, lst);
	if (lst->content == min && lst->next->content == max)
	{
		apply(pswap, RRA + l);
		apply(pswap, SA + l);
	}
	else if(lst->next->content == min && lst->content != max)
			apply(pswap, SA + l);
	else if(lst->next->content == max && lst->content != min)
		apply(pswap, RRA + l);
	else if (lst->content == max && lst->next->content == min)
		apply(pswap, RA + l);
	else if (lst->content == max && lst->next->content != min)
	{
		apply(pswap, SA + l);
		apply(pswap, RRA + l);
	}
}
