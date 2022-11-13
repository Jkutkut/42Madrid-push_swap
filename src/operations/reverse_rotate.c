/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:40:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 10:45:46 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_stack(t_stack **lst)
{
	t_stack	*current;
	t_stack	*tmp;

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
	if (!reverse_rotate_stack(&pswap->a))
		return (NULL);
	return ("rra");
}

char	*rrb(t_dstack *pswap)
{
	if (!reverse_rotate_stack(&pswap->b))
		return (NULL);
	return ("rrb");
}

char	*rrr(t_dstack *pswap)
{
	if (!reverse_rotate_stack(&pswap->a) || !reverse_rotate_stack(&pswap->b))
		return (NULL);
	return ("rrr");
}
