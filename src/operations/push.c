/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:16:57 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/24 08:27:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	push_list(t_list **lst, t_list **lst2)
{
	t_list	*tmp;

	if (!*lst)
		return (0);
	tmp = *lst;
	*lst = tmp->next;
	tmp->next = *lst2;
	*lst2 = tmp;
	return (1);
}

char	*pa(t_dstack *pswap)
{
	if (!push_list(&pswap->b, &pswap->a))
		return (NULL);
	return ("PA");
}

char	*pb(t_dstack *pswap)
{
	if (!push_list(&pswap->a, &pswap->b))
		return (NULL);
	return ("PB");
}
