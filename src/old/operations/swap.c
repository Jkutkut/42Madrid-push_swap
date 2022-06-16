/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:39:14 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/27 19:03:00 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	swap_list(t_list **lst)
{
	t_list	*tmp;

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
	if (!swap_list(&pswap->a))
		return (NULL);
	return ("sa");
}

char	*sb(t_dstack *pswap)
{
	if (!swap_list(&pswap->b))
		return (NULL);
	return ("sb");
}

char	*ss(t_dstack *pswap)
{
	if (!sa(pswap) || !sb(pswap))
		return (NULL);
	return ("ss");
}