/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:40:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 10:46:50 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return (0);
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_stack_last(*lst)->next = tmp;
	return (1);
}

char	*ra(t_dstack *pswap)
{
	if (!rotate_stack(&pswap->a))
		return (NULL);
	return ("ra");
}

char	*rb(t_dstack *pswap)
{
	if (!rotate_stack(&pswap->b))
		return (NULL);
	return ("rb");
}

char	*rr(t_dstack *pswap)
{
	if (!rotate_stack(&pswap->a) || !rotate_stack(&pswap->b))
		return (NULL);
	return ("rr");
}
