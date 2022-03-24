/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:40:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/24 09:56:22 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	rotate_list(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return (0);
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstlast(*lst)->next = tmp;
	return (1);
}

char	*ra(t_dstack *pswap)
{
	if (!rotate_list(&pswap->a))
		return (NULL);
	return ("RA");
}

char	*rb(t_dstack *pswap)
{
	if (!rotate_list(&pswap->b))
		return (NULL);
	return ("RB");
}

char	*rr(t_dstack *pswap)
{
	if (!rotate_list(&pswap->a) || !rotate_list(&pswap->b))
		return (NULL);
	return ("RR");
}
