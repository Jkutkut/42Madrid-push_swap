/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:39:14 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 10:47:30 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst || !(*lst)->next)
		return (0);
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
	return (1);
}

char	*sa(t_dstack *pswap)
{
	if (!swap_stack(&pswap->a))
		return (NULL);
	return ("sa");
}

char	*sb(t_dstack *pswap)
{
	if (!swap_stack(&pswap->b))
		return (NULL);
	return ("sb");
}

char	*ss(t_dstack *pswap)
{
	if (!sa(pswap) || !sb(pswap))
		return (NULL);
	return ("ss");
}
