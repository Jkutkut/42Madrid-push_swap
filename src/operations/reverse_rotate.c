/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:40:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/24 10:04:27 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	reverse_rotate_list(t_list **lst)
{
	t_list	*current;
	t_list	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return (0);
	current = *lst;
	while (current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = *lst;
	*lst = tmp;
	return (1);
}

char	*rra(t_dstack *pswap)
{
	if (!reverse_rotate_list(&pswap->a))
		return (NULL);
	return ("RRA");
}

char	*rrb(t_dstack *pswap)
{
	if (!reverse_rotate_list(&pswap->b))
		return (NULL);
	return ("RRB");
}

char	*rrr(t_dstack *pswap)
{
	if (!reverse_rotate_list(&pswap->a) || !reverse_rotate_list(&pswap->b))
		return (NULL);
	return ("RRR");
}
